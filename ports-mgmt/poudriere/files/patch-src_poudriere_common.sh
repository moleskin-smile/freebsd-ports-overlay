--- src/share/poudriere/common.sh.orig	2013-06-10 14:51:21.758617306 +0200
+++ src/share/poudriere/common.sh	2013-06-10 14:53:02.193812885 +0200
@@ -740,10 +740,12 @@
 
 	# ref jail only needs devfs
 	mount -t devfs devfs ${mnt}/dev
-	devfs -m ${mnt}/dev rule apply hide
-	for p in ${devfspath} ; do
-		devfs -m ${mnt}/dev/ rule apply path "${p}" unhide
-	done
+	if [ ${JAILED} -eq 0 ]; then
+		devfs -m ${mnt}/dev rule apply hide
+		for p in ${devfspath} ; do
+			devfs -m ${mnt}/dev/ rule apply path "${p}" unhide
+		done
+	fi
 	if [ "${mnt##*/}" != "ref" ]; then
 		[ ${JAILED} -eq 0 ] && mount -t fdescfs fdesc ${mnt}/dev/fd
 		mount -t procfs proc ${mnt}/proc
