# $FreeBSD: head/sysutils/terraform/Makefile 413043 2016-04-11 16:22:33Z swills $

PORTNAME=	terraform
PORTVERSION=	0.7.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
STRIP=		# stripping can break go binaries

post-extract:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .github .gitignore .travis.yml BUILDING.md CHANGELOG.md LICENSE \
	Makefile README.md Vagrantfile builtin checkpoint.go command commands.go \
	communicator config config.go config_test.go config_unix.go config_windows.go \
	contrib dag deps digraph dot examples flatmap help.go helper main.go panic.go \
	plugin scripts state terraform test-fixtures version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/hashicorp/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
