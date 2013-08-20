# $FreeBSD: www/owncloud/Makefile 324752 2013-08-15 06:19:57Z kevlo $

PORTNAME=	owncloud
PORTVERSION=	5.0.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Personal cloud which runs on your own server

LICENSE=	AGPLv3

BUILD_DEPENDS=	mp3info:${PORTSDIR}/audio/mp3info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PHP=	ctype curl dom fileinfo filter gd hash iconv json mbstring \
		pdo session simplexml xml wddx zip zlib
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
	${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type f -print | \
		${SED} -e "s#^\.#${WWWDIR_REL}#" >> ${TMPPLIST}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type d  -print | \
		${SED} -e "s#^\.#@dirrm ${WWWDIR_REL}#" >> ${TMPPLIST}

.include <bsd.port.mk>
