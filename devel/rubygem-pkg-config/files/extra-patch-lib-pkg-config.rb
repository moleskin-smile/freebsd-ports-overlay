--- lib/pkg-config.rb.orig	2014-11-18 09:09:37.045919000 +0100
+++ lib/pkg-config.rb	2014-11-18 09:16:01.461138370 +0100
@@ -91,13 +91,13 @@
           return nil
         end
         begin
-          extern "const char *dln_find_exe(const char *, const char *)"
+          extern "const char *dln_find_exe_r(const char *, const char *, char *, size_t)"
         rescue DL::DLError
           return nil
         end
       end
-      path = dln.dln_find_exe(pkg_config.to_s, nil)
-      if path.nil? or path.size.zero?
+      path = dln.dln_find_exe_r(pkg_config.to_s, nil, ' ' * 1024, 1024)
+      if path.nil? or path.null?
         nil
       else
         Pathname(path.to_s)
