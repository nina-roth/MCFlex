AC_INIT([MCFlex], [0.1], [http://github.com/nina-roth/MCFlex])
AM_INIT_AUTOMAKE([foreign])
dnl AC_CONFIG_MACRO_DIRS([m4])

AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
dnl AC_PROG_LIBTOOL

AC_CONFIG_FILES([Makefile src/Makefile test/Makefile]) dnl test/Makefile])

AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([boost/test/included/unit_test.hpp], [], dnl takes rather long!
    [AC_MSG_WARN(You need the Boost Unit Test libraries to run 'make check'.)])
AC_LANG_POP([C++])

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], 
[test -n "$DOXYGEN"])AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Makefile doc/Doxyfile])])

AC_OUTPUT
