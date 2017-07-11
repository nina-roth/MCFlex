AUTOMAKE_OPTIONS = foreign
if HAVE_DOXYGEN

doxyfile.stamp:
	${DOXYGEN} Doxyfile
	echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

HTMLDIR = ${DESTDIR}${pkgdatadir}/html

install-data-local:
	${MKDIR_P} ${HTMLDIR} 
	for f in ${top_builddir}/doc/html/*; do \
	cp -r $$f ${HTMLDIR}; done
	cp ${top_srcdir}/README.md ${DESTDIR}${pkgdatadir}

uninstall-local: 
	-rm -rf ${DESTDIR}${pkgdatadir}

all-local: doxyfile.stamp
clean-local:
	rm -rf ${top_builddir}/doc/html
	rm -rf ${top_builddir}/doc/latex

endif


