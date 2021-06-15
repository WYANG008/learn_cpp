pkglib_LTLIBRARIES = hithere.la
hithere_la_SOURCES = hithere.c
# -module option tells Libtool you want to call your library
# hithere, and not libhithere. The GNU Libtool Manual makes the statement that
# modules do not need to be prefixed with lib.
# using the Libtool -avoid-version option. This option
# causes Libtool to generate a shared library whose name is libname.so, rather
# than libname.so.0.0.0. It also suppresses generation of the libname.so.0 and
# libname.so soft links that refer to the binary image
# Because I’m using both
# options, my module will simply be named hithere.so
hithere_la_LDFLAGS = -module -avoid-version