#common definitions for use in several Makefiles

AM_CXXFLAGS = -std=c++14
AM_LDFLAGS = -lm -lgsl -lgslcblas

GIT_VERSION = $(shell git rev-parse --short HEAD)
GIT_MODIFIED = $(shell git diff --name-only --diff-filter=M | tr '\n' ' ')
CUSTOMDEFINES = -DGIT_VERSION='"$(GIT_VERSION)"' -DGIT_MODIFIED='"$(GIT_MODIFIED)"'
INCLUDEDIR = $(top_srcdir)/include