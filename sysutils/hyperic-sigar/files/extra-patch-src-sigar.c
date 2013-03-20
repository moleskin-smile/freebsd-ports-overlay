--- src/sigar.c	2010-04-29 01:59:59.000000000 +0200
+++ src/sigar.c	2013-01-07 17:13:36.340476274 +0100
@@ -30,6 +30,11 @@
 #ifndef WIN32
 #include <arpa/inet.h>
 #endif
+#if defined(HAVE_UTMPX_H)
+# include <utmpx.h>
+#elif defined(HAVE_UTMP_H)
+# include <utmp.h>
+#endif
 
 #include "sigar.h"
 #include "sigar_private.h"
@@ -994,30 +999,7 @@
     return SIGAR_OK;
 }
 
-#if defined(__sun)
-#  include <utmpx.h>
-#  define SIGAR_UTMP_FILE _UTMPX_FILE
-#  define ut_time ut_tv.tv_sec
-#elif defined(WIN32)
-/* XXX may not be the default */
-#define SIGAR_UTMP_FILE "C:\\cygwin\\var\\run\\utmp"
-#define UT_LINESIZE	16
-#define UT_NAMESIZE	16
-#define UT_HOSTSIZE	256
-#define UT_IDLEN	2
-#define ut_name ut_user
-
-struct utmp {
-    short ut_type;	
-    int ut_pid;		
-    char ut_line[UT_LINESIZE];
-    char ut_id[UT_IDLEN];
-    time_t ut_time;	
-    char ut_user[UT_NAMESIZE];	
-    char ut_host[UT_HOSTSIZE];	
-    long ut_addr;	
-};
-#elif defined(NETWARE)
+#if defined(NETWARE)
 static char *getpass(const char *prompt)
 {
     static char password[BUFSIZ];
@@ -1027,106 +1009,48 @@
 
     return (char *)&password;
 }
-#else
-#  include <utmp.h>
-#  ifdef UTMP_FILE
-#    define SIGAR_UTMP_FILE UTMP_FILE
-#  else
-#    define SIGAR_UTMP_FILE _PATH_UTMP
-#  endif
-#endif
-
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(DARWIN)
-#  define ut_user ut_name
-#endif
-
-#ifdef DARWIN
-/* XXX from utmpx.h; sizeof changed in 10.5 */
-/* additionally, utmpx does not work on 10.4 */
-#define SIGAR_HAS_UTMPX
-#define _PATH_UTMPX     "/var/run/utmpx"
-#define _UTX_USERSIZE   256     /* matches MAXLOGNAME */
-#define _UTX_LINESIZE   32
-#define _UTX_IDSIZE     4
-#define _UTX_HOSTSIZE   256
-struct utmpx {
-    char ut_user[_UTX_USERSIZE];    /* login name */
-    char ut_id[_UTX_IDSIZE];        /* id */
-    char ut_line[_UTX_LINESIZE];    /* tty name */
-    pid_t ut_pid;                   /* process id creating the entry */
-    short ut_type;                  /* type of this entry */
-    struct timeval ut_tv;           /* time entry was created */
-    char ut_host[_UTX_HOSTSIZE];    /* host name */
-    __uint32_t ut_pad[16];          /* reserved for future use */
-};
-#define ut_xtime ut_tv.tv_sec
-#define UTMPX_USER_PROCESS      7
-/* end utmpx.h */
-#define SIGAR_UTMPX_FILE _PATH_UTMPX
 #endif
 
-#if !defined(NETWARE) && !defined(_AIX)
-
 #define WHOCPY(dest, src) \
     SIGAR_SSTRCPY(dest, src); \
     if (sizeof(src) < sizeof(dest)) \
         dest[sizeof(src)] = '\0'
 
-#ifdef SIGAR_HAS_UTMPX
-static int sigar_who_utmpx(sigar_t *sigar,
-                           sigar_who_list_t *wholist)
+static int sigar_who_utmp(sigar_t *sigar,
+                          sigar_who_list_t *wholist)
 {
-    FILE *fp;
-    struct utmpx ut;
+#if defined(HAVE_UTMPX_H)
+    struct utmpx *ut;
 
-    if (!(fp = fopen(SIGAR_UTMPX_FILE, "r"))) {
-        return errno;
-    }
+    setutxent();
 
-    while (fread(&ut, sizeof(ut), 1, fp) == 1) {
+    while ((ut = getutxent()) != NULL) {
         sigar_who_t *who;
 
-        if (*ut.ut_user == '\0') {
+        if (*ut->ut_user == '\0') {
             continue;
         }
 
-#ifdef UTMPX_USER_PROCESS
-        if (ut.ut_type != UTMPX_USER_PROCESS) {
+        if (ut->ut_type != USER_PROCESS) {
             continue;
         }
-#endif
 
         SIGAR_WHO_LIST_GROW(wholist);
         who = &wholist->data[wholist->number++];
 
-        WHOCPY(who->user, ut.ut_user);
-        WHOCPY(who->device, ut.ut_line);
-        WHOCPY(who->host, ut.ut_host);
+        WHOCPY(who->user, ut->ut_user);
+        WHOCPY(who->device, ut->ut_line);
+        WHOCPY(who->host, ut->ut_host);
 
-        who->time = ut.ut_xtime;
+        who->time = ut->ut_tv.tv_sec;
     }
 
-    fclose(fp);
-
-    return SIGAR_OK;
-}
-#endif
-
-static int sigar_who_utmp(sigar_t *sigar,
-                          sigar_who_list_t *wholist)
-{
+    endutxent();
+#elif defined(HAVE_UTMP_H)
     FILE *fp;
-#ifdef __sun
-    /* use futmpx w/ pid32_t for sparc64 */
-    struct futmpx ut;
-#else
     struct utmp ut;
-#endif
-    if (!(fp = fopen(SIGAR_UTMP_FILE, "r"))) {
-#ifdef SIGAR_HAS_UTMPX
-        /* Darwin 10.5 */
-        return sigar_who_utmpx(sigar, wholist);
-#endif
+
+    if (!(fp = fopen(_PATH_UTMP, "r"))) {
         return errno;
     }
 
@@ -1146,7 +1070,7 @@
         SIGAR_WHO_LIST_GROW(wholist);
         who = &wholist->data[wholist->number++];
 
-        WHOCPY(who->user, ut.ut_user);
+        WHOCPY(who->user, ut.ut_name);
         WHOCPY(who->device, ut.ut_line);
         WHOCPY(who->host, ut.ut_host);
 
@@ -1154,12 +1078,11 @@
     }
 
     fclose(fp);
+#endif
 
     return SIGAR_OK;
 }
 
-#endif /* NETWARE */
-
 #if defined(WIN32)
 
 int sigar_who_list_get_win32(sigar_t *sigar,
