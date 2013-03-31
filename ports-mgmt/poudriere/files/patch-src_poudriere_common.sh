diff -ruN src.orig/share/poudriere/common.sh src/share/poudriere/common.sh
--- src.orig/share/poudriere/common.sh	2013-03-25 15:44:37.000000000 +0100
+++ src/share/poudriere/common.sh	2013-03-31 01:07:58.037616402 +0100
@@ -354,7 +354,6 @@
 	fi
 
 	mount -t devfs devfs ${JAILMNT}/dev
-	mount -t fdescfs fdesc ${JAILMNT}/dev/fd
 	mount -t procfs proc ${JAILMNT}/proc
 
 	if [ -z "${NOLINUX}" ]; then
