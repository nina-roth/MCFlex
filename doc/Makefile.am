##AUTOMAKE_OPTIONS = foreign
if HAVE_DOXYGEN
directory = $(top_srcdir)/doc/man/man3/

#dist_man_MANS = $(directory)/man_page_1.3 $(directory)/man_page_2.3
#$(directory)/man_page_1.3: doxyfile.stamp
#$(directory)/man_page_2.3: doxyfile.stamp

doxyfile.stamp:
	$(DOXYGEN) Doxyfile
	echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

#all: doxyfile.stamp
#clean:
#	rm -rf $(top_srcdir)/doc/html
all-local: doxyfile.stamp
clean-local:
	rm -rf $(top_srcdir)/doc/man
	rm -rf $(top_srcdir)/doc/html
	rm -rf $(top_srcdir)/doc/latex
endif


