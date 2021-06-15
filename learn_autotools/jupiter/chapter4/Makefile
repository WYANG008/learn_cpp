# Makefile.  Generated from Makefile.in by configure.

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
INSTALL_SCRIPT	= ${INSTALL}

# VPATH-related substitution variables
top_builddir	= .
builddir	= .
srcdir		= .


dist: distclean $(distdir).tar.gz

distclean:
	-rm -rf $(distdir).tar.gz
	-rm -rf $(distdir)

distcheck: $(distdir).tar.gz
	gzip -cd $(distdir).tar.gz | tar xvf -
	cd $(distdir) && ./configure
	cd $(distdir) && $(MAKE) all
	cd $(distdir) && $(MAKE) check
	cd $(distdir) && $(MAKE) DESTDIR=$${PWD}/_inst install
	cd $(distdir) && $(MAKE) DESTDIR=$${PWD}/_inst uninstall
	@remaining="`find $${PWD}/$(distdir)/_inst -type  | wc -l`"; \
	if test "$${remaining}" -ne 0; then \
		echo "*** $${remaining} files remaining in teh stage directory"; \
		exit 1; \
	fi
	cd $(distdir) && $(MAKE) clean
	rm -rf $(distdir)
	@echo "*** Package $(distdir).tar.gz is ready for distribution";

$(distdir).tar.gz: $(distdir)
    # create tarball
	tar chof - $(distdir) | gzip -9 -c > $@ 
	rm -rf $(distdir)

$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp $(srcdir)/configure $(distdir)
	cp $(srcdir)/config.h.in $(distdir)
	cp $(srcdir)/install-sh $(distdir)
	cp $(srcdir)/Makefile.in $(distdir)
	cp $(srcdir)/src/Makefile.in $(distdir)/src
	cp $(srcdir)/src/main.c $(distdir)/src

FORCE:
	-rm $(distdir).tar.gz >/dev/null 2>&1
	-rm -rf $(distdir) >/dev/null 2>&1

Makefile: Makefile.in config.status
	./config.status $@

config.status: configure
	./config.status -- recheck


# jupiter: main.c
# 	gcc -g -o $@ main.c

# all check clean jupiter:
# 	cd src && $(MAKE) $@

all clean check install uninstall jupiter:
	$(MAKE) -C src $@

.PHONY: FORCE
.PHONY: all clean check dist distcheck distclean
.PHONY: install uninstall
