# $FreeBSD$

PORTNAME=	wego
PORTVERSION=	1.0
CATEGORIES=	astro
PKGNAMEPREFIX=	go-

MAINTAINER=	am+bsd@nereis.pl
COMMENT=	Weather app for the terminal

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-colorable.a:${PORTSDIR}/devel/go-colorable \
		${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-runewidth.a:${PORTSDIR}/devel/go-runewidth

USE_GITHUB=	yes
GH_ACCOUNT=	schachmat

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=    bin/wego

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
