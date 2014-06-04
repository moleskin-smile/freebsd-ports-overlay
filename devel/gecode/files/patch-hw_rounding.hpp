--- ./gecode/third-party/boost/numeric/interval/hw_rounding.hpp.orig	2014-06-04 17:58:03.847501385 +0200
+++ ./gecode/third-party/boost/numeric/interval/hw_rounding.hpp	2014-06-04 18:16:47.658505110 +0200
@@ -16,6 +16,11 @@
 
 #define BOOST_NUMERIC_INTERVAL_NO_HARDWARE
 
+// dirty hack to build dep_selector
+#if !defined(__USE_ISOC99)
+#define __USE_ISOC99 1
+#endif
+
 // define appropriate specialization of rounding_control for built-in types
 #if defined(__x86_64__) && (defined(__USE_ISOC99) || defined(__APPLE__))
 #  include <gecode/third-party/boost/numeric/interval/detail/c99_rounding_control.hpp>
