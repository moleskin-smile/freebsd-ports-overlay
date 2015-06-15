--- ./plugins/bittorrent/torrentplugin.cpp
+++ ./plugins/bittorrent/torrentplugin.cpp
@@ -555,7 +555,7 @@ namespace LeechCraft
 
 				confirm.exec ();
 
-				int roptions = libtorrent::session::none;
+				int roptions = 0;
 				if (confirm.clickedButton () == deleteTorrentsAndFilesButton)
 					roptions |= libtorrent::session::delete_files;
 				else if (confirm.clickedButton () == deleteTorrentsButton)
