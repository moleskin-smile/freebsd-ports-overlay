# $FreeBSD$

PORTNAME=	wego
PORTVERSION=	2.0
CATEGORIES=	astro
PKGNAMEPREFIX=	go-

MAINTAINER=	am+bsd@nereis.pl
COMMENT=	Weather app for the terminal

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-colorable.a:devel/go-colorable \
		${LOCALBASE}/${GO_LIBDIR}/github.com/schachmat/ingo.a:devel/go-ingo \
		${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-runewidth.a:devel/go-runewidth
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	schachmat

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=    bin/wego

.include <bsd.port.mk>
