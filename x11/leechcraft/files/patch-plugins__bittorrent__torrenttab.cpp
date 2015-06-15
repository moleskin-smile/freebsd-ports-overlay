--- ./plugins/bittorrent/torrenttab.cpp
+++ ./plugins/bittorrent/torrenttab.cpp
@@ -450,7 +450,7 @@ namespace BitTorrent
 
 		confirm.exec ();
 
-		int roptions = libtorrent::session::none;
+		int roptions = 0;
 		if (confirm.clickedButton () == deleteTorrentsAndFilesButton)
 			roptions |= libtorrent::session::delete_files;
 		else if (confirm.clickedButton () == deleteTorrentsButton)
