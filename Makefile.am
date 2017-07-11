if HAVE_DOXYGEN
SUBDIRS = src test doc
EXTRA_DIST = README.md
else
SUBDIRS = src test

EXTRA_DIST = doc/Doxyfile.in doc/Makefile.am  doc/Makefile.in README.md

install-data-local:
	$(MKDIR_P) ${pkgdatadir} 
	cp ${top_srcdir}/README.md ${pkgdatadir}

uninstall-hook:
	-rmdir ${pkgdatadir}

endif

DIST_SUBDIRS = $(SUBDIRS)




