--- source3/client/smbspool_krb5_wrapper.c.orig	2016-04-13 19:37:54 UTC
+++ source3/client/smbspool_krb5_wrapper.c
@@ -195,7 +195,7 @@ int main(int argc, char *argv[])
 	 * Make sure we do not have LD_PRELOAD or other security relevant
 	 * environment variables set.
 	 */
-	clearenv();
+	environ[0] = NULL;
 
 	CUPS_SMB_DEBUG("Setting KRB5CCNAME to '%s'", gen_cc);
 	setenv("KRB5CCNAME", gen_cc, 1);
