# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD: head/sysutils/hatop/Makefile 412349 2016-04-01 14:25:16Z mat $

PORTNAME=	hatop
PORTVERSION=	0.7.7
CATEGORIES=	sysutils net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@christianserving.org
COMMENT=	Interactive real-time monitoring tool for the HAProxy unix socket

RUN_DEPENDS=	${LOCALBASE}/sbin/haproxy:net/haproxy

USES=		python
NO_BUILD=	yes

LICENSE=	GPLv3

PLIST_FILES=	bin/hatop man/man1/hatop.1.gz
PORTDOCS=	HACKING KEYBINDS README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop ${STAGEDIR}${PREFIX}/bin/hatop
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
