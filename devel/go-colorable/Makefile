# Created by: Emil Smolenski <am+bsd@nereis.pl>
# $FreeBSD$

PORTNAME=	colorable
PORTVERSION=	0.0.0.20160302
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	am+bsd@nereis.pl
COMMENT=	Go wrapper library to get proper colours on Windows

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${GO_LIBDIR}/github.com/mattn/go-isatty.a:${PORTSDIR}/devel/go-isatty

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	mattn
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}
GH_TAGNAME=	9cbef7c

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.mk>
