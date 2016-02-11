# Created by: Emil Smolenski <am+bsd@nereis.pl>
# $FreeBSD $

PORTNAME=	htop
PORTVERSION=	2.0.0
CATEGORIES=	sysutils
MASTER_SITES=   http://hisham.hm/htop/releases/${PORTVERSION}/

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer

LICENSE=	GPLv2

OPTIONS_DEFINE=	LSOF
OPTIONS_DEFAULT=LSOF

NOT_FOR_ARCHS=	ia64 powerpc sparc64

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

CONFIGURE_ARGS=	--enable-unicode
USES=		autoreconf ncurses libtool execinfo python:2,build

LSOF_RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/python:${PYTHON_CMD}:' ${WRKSRC}/scripts/MakeHeader.py

.include <bsd.port.mk>
