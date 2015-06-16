--- setup.py.orig	2015-06-16 13:35:14.000000000 +0000
+++ setup.py	2015-06-16 13:35:25.000000000 +0000
@@ -44,6 +44,6 @@
       license='BSD',
       packages=['tarsnapper'],
       package_dir = {'tarsnapper': 'src/tarsnapper'},
-      install_requires = ['argparse>=1.1', 'pyyaml>=3.09', 'python-dateutil>=2.4.0'],
+      install_requires = ['argparse>=1.1', 'pyyaml>=3.09', 'python-dateutil>=2.3.0'],
       **kw
 )
