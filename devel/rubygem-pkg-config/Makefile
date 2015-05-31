# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD: head/devel/rubygem-pkg-config/Makefile 373236 2014-11-24 18:24:47Z sunpoet $

PORTNAME=	pkg-config
PORTVERSION=	1.1.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	pkg-config implementation for Ruby

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		pkgconfig
USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.9
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-lib-pkg-config.rb
.endif

.include <bsd.port.post.mk>
