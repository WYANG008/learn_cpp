AC_PREREQ([2.61])
AC_INIT([jupiter], [1.0], [yangweitaohustntu@gmail.com])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# LT_INIT accepts a single, optional argument: a whitespace-separated list of keywords
# such as dlopen: There’s only one reason for using the -dlopen  or -dlpreopen flags: 
#                 You intend to dynamically load and import shared-library functionality 
#                 at runtime by calling into the ltdl library within your project’s source code.
# disable-fast-install
# shared and disable-shared
# static and disable-static
# pic-only and no-pic
LT_INIT([dlopen])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
# AC_PROG_RANLIB

# Checks for header files. (1)
AC_HEADER_STDC

# Checks for libraries.


# Checks for command line options
AC_ARG_ENABLE([async-exec],
  [AS_HELP_STRING([--disable-async-exec],
    [disable asynchronous execution @<:@default: no@:>@])],
  [async_exec=${enableval}],
  [async_exec=yes])

if test "x${async_exec}" = xyes; then
  have_pthreads=no
  AC_SEARCH_LIBS([pthread_create], [pthread], [have_pthreads=yes])

  if test "x${have_pthreads}" = xyes; then
    AC_CHECK_HEADERS([pthread.h], [], [have_pthreads=no])
  fi

  if test "x${have_pthreads}" = xno; then
    echo "---------------------------------------"
    echo "Unable to find pthreads on this system."
    echo "Building a single-threaded version.    "
    echo "---------------------------------------"
    async_exec=no
  fi
fi

if test "x${async_exec}" = xyes; then
  AC_DEFINE([ASYNC_EXEC], 1, [async exec enabled])
fi

# Checks for header files. (2)
AC_CHECK_HEADERS([stdlib.h], [],
  [AC_MSG_ERROR([no stdlib.h, cannot proceed.])])
AC_CHECK_HEADERS([dlfcn.h], [],
  [AC_MSG_ERROR([no stdlib.h, cannot proceed.])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_SEARCH_LIBS([dlopen], [dl])

CFLAGS="-std=c99 $CFLAGS"

AC_CONFIG_FILES([Makefile
                common/Makefile
                include/Makefile
                libjup/Makefile
                src/Makefile])

AC_OUTPUT

echo \
"-------------------------------------------------

 ${PACKAGE_NAME} Version ${PACKAGE_VERSION}

 Prefix: '${prefix}'.
 Compiler: '${CC} ${CFLAGS} ${CPPFLAGS}'
 Libraries: '${LIBS}'

 Package features:
   Async Execution: ${async_exec}

 Now type 'make @<:@<target>@:>@'
   where the optional <target> is:
     all                - build all binaries
     install            - install everything

--------------------------------------------------"