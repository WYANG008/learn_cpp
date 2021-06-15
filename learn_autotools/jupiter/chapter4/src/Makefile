# src/Makefile.  Generated from Makefile.in by configure.

# Package-specific substitution variables
package = jupiter
version = 1.0
tarname = jupiter
distdir = $(tarname)-$(version)

# Prefix-specific substitution variables
prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin

# Tool-related substitution variables
CC		= gcc
DEFS		= -DHAVE_CONFIG_H
LIBS		= -lpthread 
CFLAGS		= -g -O2
CPPFLAGS	= 
INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_SCRIPT	= ${INSTALL}

# VPATH-related substitution variables
top_builddir	= ..
builddir	= .
srcdir		= .


$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp configure.ac $(distdir)
	cp configure $(distdir)
	cp Makefile.in $(distdir)
	cp src/Makefile.in $(distdir)/src
	cp src/main.c $(distdir)/src

Makefile: Makefile.in ../config.status
	cd .. && ./config.status src/$@

../config.status: ../configure
	cd .. && ./config.status -- recheck

all: jupiter

jupiter: main.c
	$(CC) $(CFLAGS) $(DEFS) $(CPPFLAGS) -I. -I$(srcdir) -I.. -o $@ $(srcdir)/main.c $(LIBS)

clean: 
	-rm -rf jupiter

install:
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) -m 0755 jupiter $(DESTDIR)$(bindir)

uninstall:
	-rm $(DESTDIR)$(bindir)/bin/jupiter

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

.PHONY: all clean check install uninstall
