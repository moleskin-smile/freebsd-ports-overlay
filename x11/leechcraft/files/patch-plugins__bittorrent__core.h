--- ./plugins/bittorrent/core.h
+++ ./plugins/bittorrent/core.h
@@ -271,7 +271,7 @@ namespace BitTorrent
 				const QVector<bool>& files = QVector<bool> (),
 				LeechCraft::TaskParameters params = LeechCraft::NoParameters);
 		void KillTask (int);
-		void RemoveTorrent (int, int opt = libtorrent::session::none);
+		void RemoveTorrent (int, int opt = 0);
 		void PauseTorrent (int);
 		void ResumeTorrent (int);
 		void ForceReannounce (int);
