diff -ruN src.orig/poudriere.d/common.sh src/poudriere.d/common.sh
--- src.orig/poudriere.d/common.sh	2013-01-13 18:11:32.000000000 +0000
+++ src/poudriere.d/common.sh	2013-02-08 11:51:45.465681176 +0000
@@ -333,7 +333,6 @@
 	fi
 
 	mount -t devfs devfs ${JAILMNT}/dev
-	mount -t fdescfs fdesc ${JAILMNT}/dev/fd
 	mount -t procfs proc ${JAILMNT}/proc
 
 	if [ -z "${NOLINUX}" ]; then
