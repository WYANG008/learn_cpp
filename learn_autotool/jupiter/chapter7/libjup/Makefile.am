# The products this prefix references will be installed in the $(libdir) directory
# The use of LTLIBRARIES tells Automake to generate
# rules that use the libtool script, rather than calling the compiler (and possibly
# the librarian) directly to generate the products
lib_LTLIBRARIES = libjupiter.la

libjupiter_la_SOURCES = jup_print.c

# indicates a set of C-preprocessor flags that are to be used
# on the compiler command line for locating the associated shared-library
# header files
libjupiter_la_LIBADD = ../common/libjupcommon.la

# indicates a set of linker options for this product. In
# this case, we’re specifying that the libjupcommon.a static library should be linked
# into (i.e., become part of) the libjupiter.so shared library
libjupiter_la_CPPFLAGS = -I$(top_srcdir)/include \
  -I$(top_srcdir)/common