AC_INIT([MCFlex], [0.1], [http://github.com/nina-roth/MCFlex])
AM_INIT_AUTOMAKE([foreign])
AC_PROG_CXX
AC_PROG_CC
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile]) dnl test/Makefile])
AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], 
[test -n "$DOXYGEN"])AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Makefile doc/Doxyfile])])
AC_OUTPUT
