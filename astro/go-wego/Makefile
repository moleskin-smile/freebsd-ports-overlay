# $FreeBSD$

PORTNAME=	wego
PORTVERSION=	2.0
CATEGORIES=	astro
PKGNAMEPREFIX=	go-

MAINTAINER=	am+bsd@nereis.pl
COMMENT=	Weather app for the terminal

LICENSE=	ISCL

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	schachmat

GH_TUPLE=	mattn:go-colorable:v0.0.9:colorable/../src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:isatty/../src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:runewidth/../src/github.com/mattn/go-runewidth \
		schachmat:ingo:a4bdc07:ingo/../src/github.com/schachmat/ingo

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=    bin/wego

.include <bsd.port.mk>
