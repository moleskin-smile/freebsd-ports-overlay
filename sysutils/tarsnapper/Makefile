# Created by: Emil Smolenski <am@nereis.pl>
# $FreeBSD$

PORTNAME=		tarsnapper
PORTVERSION=		0.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=		am@nereis.pl
COMMENT=		tarsnap wrapper which expires backups using a gfs-scheme

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		miracle2k

USES=			python
USE_PYTHON=		autoplist distutils

RUN_DEPENDS+=	tarsnap:sysutils/tarsnap				\
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.3:devel/py-dateutil	\
		${PYTHON_PKGNAMEPREFIX}yaml>=3:devel/py-yaml

.include <bsd.port.mk>
