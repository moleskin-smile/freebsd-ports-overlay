--- ext/dep_gecode/dep_selector_to_gecode.cpp.orig	2014-03-18 23:27:37.369519000 +0100
+++ ext/dep_gecode/dep_selector_to_gecode.cpp	2014-03-18 23:33:28.780519124 +0100
@@ -340,30 +340,30 @@
   DEBUG_STREAM.flush();
   }
   // This branching starts as far as possible from the solution, in order to exercise the optimization functions.
-  branch(*this, disabled_package_variables, INT_VAR_SIZE_MIN, INT_VAL_MAX);
-  branch(*this, package_versions, INT_VAR_SIZE_MIN, INT_VAL_MIN);
-  branch(*this, total_required_disabled, INT_VAL_MAX);
-  branch(*this, total_induced_disabled, INT_VAL_MAX);
-  branch(*this, total_suspicious_disabled, INT_VAL_MAX);
-  branch(*this, total_disabled, INT_VAL_MAX);
-  branch(*this, at_latest, INT_VAR_SIZE_MIN, INT_VAL_MIN);
-  branch(*this, total_preferred_at_latest, INT_VAL_MIN);
-  branch(*this, total_not_preferred_at_latest, INT_VAL_MIN);
+  branch(*this, disabled_package_variables, INT_VAR_SIZE_MIN(), INT_VAL_MAX());
+  branch(*this, package_versions, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
+  branch(*this, total_required_disabled, INT_VAL_MAX());
+  branch(*this, total_induced_disabled, INT_VAL_MAX());
+  branch(*this, total_suspicious_disabled, INT_VAL_MAX());
+  branch(*this, total_disabled, INT_VAL_MAX());
+  branch(*this, at_latest, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
+  branch(*this, total_preferred_at_latest, INT_VAL_MIN());
+  branch(*this, total_not_preferred_at_latest, INT_VAL_MIN());
 #else // USE_DUMB_BRANCHING
   if (debug_logging) {
   DEBUG_STREAM << "Adding branching (BEST)" << std::endl;
   DEBUG_STREAM.flush();
   }
   // This branching is meant to start with most probable solution
-  branch(*this, disabled_package_variables, INT_VAR_SIZE_MIN, INT_VAL_MIN);
-  branch(*this, package_versions, INT_VAR_SIZE_MIN, INT_VAL_MAX);
-  branch(*this, total_required_disabled, INT_VAL_MIN);
-  branch(*this, total_induced_disabled, INT_VAL_MIN);
-  branch(*this, total_suspicious_disabled, INT_VAL_MIN);
-  branch(*this, total_disabled, INT_VAL_MIN);
-  branch(*this, at_latest, INT_VAR_SIZE_MIN, INT_VAL_MAX);
-  branch(*this, total_preferred_at_latest, INT_VAL_MAX);
-  branch(*this, total_not_preferred_at_latest, INT_VAL_MAX);
+  branch(*this, disabled_package_variables, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
+  branch(*this, package_versions, INT_VAR_SIZE_MIN(), INT_VAL_MAX());
+  branch(*this, total_required_disabled, INT_VAL_MIN());
+  branch(*this, total_induced_disabled, INT_VAL_MIN());
+  branch(*this, total_suspicious_disabled, INT_VAL_MIN());
+  branch(*this, total_disabled, INT_VAL_MIN());
+  branch(*this, at_latest, INT_VAR_SIZE_MIN(), INT_VAL_MAX());
+  branch(*this, total_preferred_at_latest, INT_VAL_MAX());
+  branch(*this, total_not_preferred_at_latest, INT_VAL_MAX());
 #endif // USE_DUMB_BRANCHING
 
   if (debug_logging) {
@@ -570,7 +570,9 @@
     DEBUG_STREAM << "Creating solver" << std::endl << std::flush;
 #endif
     VersionProblem *best_solution = NULL;
-    Restart<VersionProblem> solver(problem);
+    Search::Options o;
+    o.cutoff = Search::Cutoff::geometric();
+    RBS<DFS,VersionProblem> solver(problem, o);
     
 #ifdef MEMORY_DEBUG
     DEBUG_STREAM << "Starting Solve" << std::endl << std::flush;
@@ -591,7 +593,7 @@
             DEBUG_STREAM << "Trial Solution #" << itercount << "===============================" << std::endl;
             const Search::Statistics & stats = solver.statistics();
             DEBUG_STREAM << "Solver stats: Prop:" << stats.propagate << " Fail:" << stats.fail << " Node:" << stats.node;
-            DEBUG_STREAM << " Depth:" << stats.depth << " memory:" << stats.memory << std::endl;
+            DEBUG_STREAM << " Depth:" << stats.depth << " memory:" << std::endl;
             solution->Print(DEBUG_STREAM);
         }
     }
@@ -605,7 +607,6 @@
         std::cerr << "Time: " << elapsed_time << "ms ";
         const Search::Statistics & final_stats = solver.statistics();
         std::cerr << "Stats: " << itercount << " steps, ";
-        std::cerr << final_stats.memory << " bytes, ";
         std::cerr << final_stats.propagate << " props, " << final_stats.node << " nodes, " << final_stats.depth << " depth ";
         std::cerr << std::endl << std::flush;
     }
