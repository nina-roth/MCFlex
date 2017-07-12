if HAVE_DOXYGEN
SUBDIRS = src test doc
EXTRA_DIST = README.md
else
SUBDIRS = src test

EXTRA_DIST = doc/Doxyfile.in doc/Makefile.am  doc/Makefile.in README.md

install-data-local:
	${MKDIR_P} ${DESTDIR}${pkgdatadir} 
	cp ${top_srcdir}/README.md ${DESTDIR}${pkgdatadir}

uninstall-hook:
	-rm -rf ${DESTDIR}${pkgdatadir}

endif

DIST_SUBDIRS = ${SUBDIRS}




