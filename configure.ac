AC_INIT([MCFlex],[0.1],[http://github.com/nina-roth/MCFlex])
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])

AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([boost/test/included/unit_test.hpp], [], dnl takes rather long!
	[AC_MSG_WARN(You need the Boost Unit Test libraries to run 'make check')])
AC_LANG_POP([C++])

AC_ARG_ENABLE(doxygen,
  [  --disable-doxygen       Disable compilation with doxygen],
  [case "${enableval}" in
     yes | no ) WITH_DOXYGEN="${enableval}" ;;
     *) AC_MSG_ERROR(bad value ${enableval} for --disable-doxygen) ;;
   esac],
  [WITH_DOXYGEN="yes"]
)

if test "x$WITH_DOXYGEN" = "xyes"; then
	AC_CHECK_PROGS([DOXYGEN], [doxygen])
	if test -z "$DOXYGEN";
   		then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
	fi
	AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
	AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Makefile doc/Doxyfile])])
else
	AM_CONDITIONAL([HAVE_DOXYGEN], [test "x$WITH_DOXYGEN" = "xyes"])
	AC_MSG_NOTICE([doxygen disabled by user and will not be used to create documentation]) 
fi

AC_OUTPUT
