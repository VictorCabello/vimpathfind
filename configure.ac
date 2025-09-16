# Initialize Autoconf and define the package name and version
AC_INIT([vimpathfind], [0.1], [vmeca87@gmail.com])

# Automake setup
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Check for a C compiler
AC_PROG_CC

# Check for program features
AC_CHECK_HEADERS([stdio.h])

# Create the output files
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])

# Complete the configuration
AC_OUTPUT
