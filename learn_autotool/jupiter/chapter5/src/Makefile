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
	gcc -g -o $@ main.c

clean: 
	-rm jupiter

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

.PHONY: all clean
