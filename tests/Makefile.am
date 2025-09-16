check_PROGRAMS = test_cli test_core test_list

test_cli_SOURCES = test_cli.c
test_core_SOURCES = test_core.c
test_list_SOURCES = test_list.c

# We need to link our tests against the object files from the src directory
test_cli_LDADD = $(top_builddir)/src/cli.o $(top_builddir)/src/core.o $(top_builddir)/src/list.o
test_core_LDADD = $(top_builddir)/src/core.o $(top_builddir)/src/list.o
test_list_LDADD = $(top_builddir)/src/list.o

TESTS = $(check_PROGRAMS)
