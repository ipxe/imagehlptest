AC_INIT([imagehlptest], [0.1], [mbrown@fensystems.co.uk])
AC_CONFIG_SRCDIR([imagehlptest.c])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign subdir-objects tar-ustar])

AC_CHECK_HEADERS([windows.h], [], [AC_MSG_ERROR([Missing <windows.h>])])
AC_CHECK_HEADERS([imagehlp.h], [], [AC_MSG_ERROR([Missing <imagehlp.h>])], [
#include <windows.h>
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
