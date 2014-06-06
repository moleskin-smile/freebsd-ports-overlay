--- ext/bzip2.c.orig	2014-06-06 13:53:15.391502954 +0200
+++ ext/bzip2.c	2014-06-06 13:53:38.496503537 +0200
@@ -247,9 +247,6 @@
 
     Get_BZ2(obj, bzf);
     res = bz_writer_internal_close(bzf);
-    if (!NIL_P(res) && (bzf->flags & BZ2_RB_INTERNAL)) {
-        RBASIC(res)->klass = rb_cString;
-    }
     return res;
 }
 
