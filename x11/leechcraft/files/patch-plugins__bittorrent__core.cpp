--- ./plugins/bittorrent/core.cpp
+++ ./plugins/bittorrent/core.cpp
@@ -230,9 +230,11 @@ namespace BitTorrent
 			setLoggingSettings ();
 			tcpPortRangeChanged ();
 
+#if LIBTORRENT_VERSION_NUM < 010000
 			if (XmlSettingsManager::Instance ()->
 					property ("EnableMetadata").toBool ())
 				Session_->add_extension (&libtorrent::create_metadata_plugin);
+#endif
 			if (XmlSettingsManager::Instance ()->
 					property ("EnablePEX").toBool ())
 				Session_->add_extension (&libtorrent::create_ut_pex_plugin);
@@ -1932,10 +1934,17 @@ namespace BitTorrent
 			atp.paused = pause;
 			atp.duplicate_is_error = true;
 #endif
+
+#if LIBTORRENT_VERSION_NUM >= 010000
+			std::copy (resumeData.constData (),
+					resumeData.constData () + resumeData.size (),
+					std::back_inserter (atp.resume_data));
+#else
 			atp.resume_data = new std::vector<char>;
 			std::copy (resumeData.constData (),
 					resumeData.constData () + resumeData.size (),
 					std::back_inserter (*atp.resume_data));
+#endif
 
 			handle = Session_->add_torrent (atp);
 			if (XmlSettingsManager::Instance ()->property ("ResolveCountries").toBool ())
