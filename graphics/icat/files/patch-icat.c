--- ./icat.c.orig	2013-01-15 10:24:37.000000000 +0100
+++ ./icat.c	2013-04-30 16:34:41.089620081 +0200
@@ -36,6 +36,7 @@
 #include <getopt.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#define X_DISPLAY_MISSING
 #include <Imlib2.h>
 
 #define VERSION "0.4"
