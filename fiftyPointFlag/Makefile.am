lib_LTLIBRARIES = fiftyPointFlag.la

fiftyPointFlag_la_SOURCES = fiftyPointFlag.cpp
fiftyPointFlag_la_CPPFLAGS= -I$(top_srcdir)/include -I$(top_srcdir)/plugins/plugin_utils
fiftyPointFlag_la_LDFLAGS = -module -avoid-version -shared
fiftyPointFlag_la_LIBADD = $(top_builddir)/plugins/plugin_utils/libplugin_utils.la

AM_CPPFLAGS = $(CONF_CPPFLAGS)
AM_CFLAGS = $(CONF_CFLAGS)
AM_CXXFLAGS = $(CONF_CXXFLAGS)

EXTRA_DIST = \
	README.fiftyPointFlag.txt \
	fiftyPointFlag.sln \
	fiftyPointFlag.vcxproj	\
	fiftyPointFlag.vcxproj.filters

MAINTAINERCLEANFILES =	\
	Makefile.in
