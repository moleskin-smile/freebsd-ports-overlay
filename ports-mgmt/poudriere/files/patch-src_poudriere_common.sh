--- src/share/poudriere/common.sh.orig	2013-10-10 04:20:34.000000000 +0200
+++ src/share/poudriere/common.sh	2013-10-14 13:19:14.930072700 +0200
@@ -765,10 +765,12 @@
 
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
@@ -1906,7 +1908,7 @@
 	buildlog_start ${portdir}
 
 	# Ensure /dev/null exists (kern/139014)
-	devfs -m ${mnt}/dev rule apply path null unhide
+	[ ${JAILED} -eq 0 ] && devfs -m ${mnt}/dev rule apply path null unhide
 
 	if [ -n "${ignore}" ]; then
 		msg "Ignoring ${port}: ${ignore}"
