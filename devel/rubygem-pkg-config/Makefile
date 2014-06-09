# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD: head/devel/rubygem-pkg-config/Makefile 332040 2013-10-30 02:40:36Z swills $

PORTNAME=	pkg-config
PORTVERSION=	1.1.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A pkg-config implementation for Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.9
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-lib-pkg-config.rb
.endif

.include <bsd.port.post.mk>
