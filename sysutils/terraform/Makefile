# $FreeBSD: head/sysutils/terraform/Makefile 413043 2016-04-11 16:22:33Z swills $

PORTNAME=	terraform
PORTVERSION=	0.7.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
STRIP=		# stripping can break go binaries

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=    bin/terraform


.include <bsd.port.mk>
