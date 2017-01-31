AC_PREREQ(2.59)
AC_INIT([Minecraft Mod Manager Beta], [1.0.1], [https://sourceforge.net/p/minecraftmodman/tickets/], [minecraftmodman_cc], [https://sourceforge.net/projects/minecraftmodman/])
LT_PREREQ([2.4.0])
LT_INIT
AC_SUBST([LIBTOOL_DEPS])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_SYSTEM
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR(src/Minecraft_Mod_ManagerApp.cpp)
AM_INIT_AUTOMAKE()
AC_PROG_CC
AC_PROG_CXX

AC_DISABLE_SHARED
AC_ENABLE_STATIC

m4_include(m4/m4_ax_compare_version.m4)
m4_include(m4/m4_ax_path_generic.m4)
m4_include(m4/m4_ax_lib_curl.m4)
m4_include(m4/m4_ax_check_openssl.m4)
m4_include(m4/wxwin.m4)
m4_include(m4/m4_ax_pthread.m4)
#m4_include(m4/m4_ax_lib_xerces.m4)
m4_include(m4/m4_ax_lib_expat.m4)

AX_LIB_EXPAT
#AX_LIB_XERCES


#m4_include(m4/m4_ax_prog_java.m4)
#m4_include(m4/m4_ax_prog_javac.m4)
#m4_include(m4/m4_ax_jni_include_dir.m4)
#m4_include(m4/libcurl.m4)

#LIBCURL_CHECK_CONFIG(,,,[AC_MSG_ERROR([compiling requires libcurl >= 7.19.4])])


AM_PATH_WXCONFIG(2.9.4, wxWin=1)
     if test "$wxWin" != 1; then
        AC_MSG_ERROR([
                wxWidgets must be installed on your system
                but wx-config script couldn't be found.

                Please check that wx-config is in path, the directory
                where wxWidgets libraries are installed (returned by
                'wx-config --libs' command) is in LD_LIBRARY_PATH or
                equivalent variable and wxWidgets version is 2.9.0 or above.
                
                wxwidgets can be obtained from:
                https://sourceforge.net/projects/wxwindows/
        ])
     fi
     CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
     CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
     CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"

     LIBS="$LIBS $WX_LIBS"
AX_LIB_CURL
#AX_CHECK_OPENSSL

#CPPFLAGS="$CPPFLAGS $JNI_INCLUDE_DIRS $OPENSSL_INCLUDES $EXPAT_CFLAGS"
CPPFLAGS="$CPPFLAGS $JNI_INCLUDE_DIRS $EXPAT_CFLAGS"
CXXFLAGS="$CXXFLAGS $CURL_CFLAGS $EXPAT_CFLAGS"
CFLAGS="$CFLAGS $CURL_CFLAGS $EXPAT_CFLAGS"
#LDFLAGS="$OPENSSL_LDFLAGS $CURL_LDFLAGS"
LDFLAGS="$CURL_LDFLAGS"
LIBS="$LIBS $CURL_LIBS $EXPAT_LIBS"

echo "CPPFLAGS: \"$CPPFLAGS\""
echo "CXXFLAGS: \"$CXXFLAGS\""
echo "CFLAGS: \"$CFLAGS\""
echo "LDFLAGS: \"$LDFLAGS\""
echo "LIBS: \"$LIBS\""

AC_CONFIG_FILES(Makefile src/Makefile src/GUI/Makefile src/tabs/Makefile)
AC_OUTPUT
