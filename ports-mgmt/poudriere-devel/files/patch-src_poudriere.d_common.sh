diff -rNu src.orig/share/poudriere/common.sh src/share/poudriere/common.sh
--- src.orig/share/poudriere/common.sh  2013-03-17 21:03:10.000000000 +0100
+++ src/share/poudriere/common.sh       2013-03-19 15:53:30.307600202 +0100
@@ -354,7 +354,6 @@
        fi
 
        mount -t devfs devfs ${JAILMNT}/dev
-       mount -t fdescfs fdesc ${JAILMNT}/dev/fd
        mount -t procfs proc ${JAILMNT}/proc
 
        if [ -z "${NOLINUX}" ]; then
