--- lib/backup/database/postgresql.rb	2013-05-21 18:21:47.339616737 +0200
+++ lib/backup/database/postgresql.rb	2013-05-21 19:31:09.766827400 +0200
@@ -31,6 +31,7 @@
       ##
       # Path to pg_dump utility (optional)
       attr_accessor :pg_dump_utility
+      attr_accessor :pg_dumpall_utility
 
       attr_deprecate :utility_path, :version => '3.0.21',
           :message => 'Use PostgreSQL#pg_dump_utility instead.',
@@ -49,7 +50,9 @@
 
         instance_eval(&block) if block_given?
 
+        @name ||= :all
         @pg_dump_utility ||= utility(:pg_dump)
+        @pg_dumpall_utility ||= utility(:pg_dumpall)
       end
 
       ##
@@ -61,14 +64,14 @@
         pipeline = Pipeline.new
         dump_ext = 'sql'
 
-        pipeline << pgdump
+        pipeline << (dump_all? ? pgdumpall : pgdump)
         if @model.compressor
           @model.compressor.compress_with do |command, ext|
             pipeline << command
             dump_ext << ext
           end
         end
-        pipeline << "cat > '#{ File.join(@dump_path, name) }.#{ dump_ext }'"
+        pipeline << "cat > '#{ File.join(@dump_path, name.to_s) }.#{ dump_ext }'"
 
         pipeline.run
         if pipeline.success?
@@ -88,6 +91,12 @@
         "#{ user_options } #{ tables_to_dump } #{ tables_to_skip } #{ name }"
       end
 
+      def pgdumpall
+        "#{ password_option }" +
+        "#{ pg_dumpall_utility } #{ username_option } " +
+        "#{ connectivity_options } #{ user_options }"
+      end
+ 
       ##
       # Builds the password syntax PostgreSQL uses to authenticate the user
       # to perform database dumping
@@ -139,6 +148,10 @@
         end.join(' ')
       end
 
+      def dump_all? 
+        name == :all 
+      end 
+
     end
   end
 end
