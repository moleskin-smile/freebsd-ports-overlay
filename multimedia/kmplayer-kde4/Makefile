# Created by: Kris Moore
# $FreeBSD: head/multimedia/kmplayer-kde4/Makefile 412348 2016-04-01 14:17:44Z mat $

PORTNAME=	kmplayer
PORTVERSION=	0.11.4
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://quickgit.kde.org/?p=kmplayer.git&a=snapshot&h=${GIT_COMMIT}&fmt=tbz2&/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE4

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libcairo.so:graphics/cairo
RUN_DEPENDS=	mplayer:multimedia/mplayer

GIT_COMMIT=	73c171d
USES=		cmake gettext pkgconfig tar:bzip2
USE_GNOME=	gtk20
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdelibs kdeprefix
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
