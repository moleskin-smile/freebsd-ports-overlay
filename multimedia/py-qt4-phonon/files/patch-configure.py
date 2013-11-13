--- configure.py.orig	2013-08-21 07:50:47.000000000 +0200
+++ configure.py	2013-11-14 00:55:19.775591805 +0100
@@ -371,8 +371,8 @@
         check_module("QtTest", "QtTest", "QTest::qSleep(0)")
         check_module("QtWebKit", "qwebpage.h", "new QWebPage()")
         check_module("QtXmlPatterns", "qxmlname.h", "new QXmlName()")
-        check_module("phonon", "phonon/videowidget.h",
-                "new Phonon::VideoWidget()")
+        check_module("phonon", "phonon/mediacontroller.h",
+                "new Phonon::MediaController(0)")
         check_module("QtAssistant", "qassistantclient.h",
                 "new QAssistantClient(\"foo\")", extra_lib_dirs=ass_lib_dirs,
                 extra_libs=ass_libs)
