# $FreeBSD: www/owncloud/Makefile 329466 2013-10-05 15:03:22Z kevlo $

PORTNAME=	owncloud
PORTVERSION=	5.0.12
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	ctype curl dom fileinfo filter gd hash iconv json mbstring \
		openssl pdo session simplexml xml xmlreader xsl wddx zip zlib
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite sqlite3
.endif

WWWDOCROOT?=	www

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}

post-install:
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type f -print | \
		${SED} -e "s#^\.#${WWWDIR_REL}#" >> ${TMPPLIST}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type d  -print | \
		${SED} -e "s#^\.#@dirrm ${WWWDIR_REL}#" >> ${TMPPLIST}

.include <bsd.port.mk>
