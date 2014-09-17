# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD: sysutils/hyperic-sigar/Makefile 327772 2013-09-20 23:05:58Z bapt $

PORTNAME=	hyperic-sigar
PORTVERSION=	1.6.4
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sigar/sigar/${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SIGAR - System Information Gatherer and Reporter

WRKSRC=		${WRKDIR}/${DISTNAME}/bindings/java/

USES=		perl5
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

SHLIB_MAJOR=	0
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 900007
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-sigar.c
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/sigar-bin/include/*.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/sigar-bin/lib/libsigar-*.so ${STAGEDIR}${PREFIX}/lib/libsigar.so.${SHLIB_MAJOR}
	${LN} -sf ${PREFIX}/lib/libsigar.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libsigar.so
	${INSTALL_DATA} ${WRKSRC}/sigar-bin/lib/sigar.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.post.mk>
