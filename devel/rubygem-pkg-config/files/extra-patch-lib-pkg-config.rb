--- lib/pkg-config.rb.orig	2014-06-09 13:40:30.635922000 +0200
+++ lib/pkg-config.rb	2014-06-09 14:43:43.429919976 +0200
@@ -90,10 +90,10 @@
         rescue DL::DLError
           return nil
         end
-        extern "const char *dln_find_exe(const char *, const char *)"
+        extern "const char *dln_find_exe_r(const char *, const char *, char *, size_t)"
       end
-      path = dln.dln_find_exe(pkg_config.to_s, nil)
-      if path.nil? or path.size.zero?
+      path = dln.dln_find_exe_r(pkg_config.to_s, nil, ' ' * 1024, 1024)
+      if path.nil? or path.null?
         nil
       else
         Pathname(path.to_s)
