--- boost/atomic/detail/gcc-atomic.hpp	2013-07-20 20:01:35.000000000 +0200
+++ boost/atomic/detail/gcc-atomic.hpp	2014-04-03 18:03:30.000000000 +0200
@@ -958,14 +958,16 @@
 
 public:
     BOOST_DEFAULTED_FUNCTION(base_atomic(void), {})
-    explicit base_atomic(value_type const& v) BOOST_NOEXCEPT : v_(0)
+    explicit base_atomic(value_type const& v) BOOST_NOEXCEPT
     {
+        memset(&v_, 0, sizeof(v_));
         memcpy(&v_, &v, sizeof(value_type));
     }
 
     void store(value_type const& v, memory_order order = memory_order_seq_cst) volatile BOOST_NOEXCEPT
     {
-        storage_type tmp = 0;
+        storage_type tmp;
+        memset(&tmp, 0, sizeof(tmp));
         memcpy(&tmp, &v, sizeof(value_type));
         __atomic_store_n(&v_, tmp, atomics::detail::convert_memory_order_to_gcc(order));
     }
@@ -980,7 +982,8 @@
 
     value_type exchange(value_type const& v, memory_order order = memory_order_seq_cst) volatile BOOST_NOEXCEPT
     {
-        storage_type tmp = 0;
+        storage_type tmp;
+        memset(&tmp, 0, sizeof(tmp));
         memcpy(&tmp, &v, sizeof(value_type));
         tmp = __atomic_exchange_n(&v_, tmp, atomics::detail::convert_memory_order_to_gcc(order));
         value_type res;
@@ -994,7 +997,9 @@
         memory_order success_order,
         memory_order failure_order) volatile BOOST_NOEXCEPT
     {
-        storage_type expected_s = 0, desired_s = 0;
+        storage_type expected_s, desired_s;
+        memset(&expected_s, 0, sizeof(expected_s));
+        memset(&desired_s, 0, sizeof(desired_s));
         memcpy(&expected_s, &expected, sizeof(value_type));
         memcpy(&desired_s, &desired, sizeof(value_type));
         const bool success = __atomic_compare_exchange_n(&v_, &expected_s, desired_s, false,
@@ -1010,7 +1015,9 @@
         memory_order success_order,
         memory_order failure_order) volatile BOOST_NOEXCEPT
     {
-        storage_type expected_s = 0, desired_s = 0;
+        storage_type expected_s, desired_s;
+        memset(&expected_s, 0, sizeof(expected_s));
+        memset(&desired_s, 0, sizeof(desired_s));
         memcpy(&expected_s, &expected, sizeof(value_type));
         memcpy(&desired_s, &desired, sizeof(value_type));
         const bool success = __atomic_compare_exchange_n(&v_, &expected_s, desired_s, true,
