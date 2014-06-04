--- ext/dep_gecode/dep_selector_to_gecode.h.orig	2014-03-18 23:27:37.369519000 +0100
+++ ext/dep_gecode/dep_selector_to_gecode.h	2014-03-18 23:32:54.778519604 +0100
@@ -151,7 +151,7 @@
   Solver(VersionProblem *s);
   VersionProblem GetNextSolution();
  private:
-  Restart<VersionProblem> solver;
+  RBS<DFS,VersionProblem> solver;
 };
 
 #endif // dep_selector_to_gecode_h
