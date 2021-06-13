# SUBDIRS = modules

bin_PROGRAMS = jupiter
jupiter_SOURCES = main.c
jupiter_CPPFLAGS = -I$(top_srcdir)/include
# library extension .la stands for libtool archive
jupiter_LDADD = ../libjup/libjupiter.la

check_SCRIPTS = greptest.sh
TESTS = $(check_SCRIPTS)

greptest.sh:
	echo './jupiter | grep \
	  "Hello from .*jupiter!"' > greptest.sh
	chmod +x greptest.sh

CLEANFILES	= greptest.sh