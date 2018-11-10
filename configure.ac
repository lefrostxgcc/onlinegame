#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([onlinegame], [1.0], [chipz68q@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_LANG([C++])
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_14
AC_PROG_INSTALL
AM_PROG_AR

LT_INIT

# Checks for libraries.
PKG_CHECK_MODULES([CATCH2], [catch2])
AC_CHECK_LIB([ncurses], [lib-ncurses])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
				lib/Makefile
				src/Makefile
				tests/Makefile])
AC_OUTPUT
