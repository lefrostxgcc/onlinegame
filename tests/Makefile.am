TESTS = coord_tests
check_PROGRAMS = coord_tests
coord_tests_SOURCES = main_tests.cpp coord_tests.cpp \
$(top_srcdir)/lib/coord.h \
$(top_srcdir)/lib/coord.cpp
coord_tests_CFLAGS = -DUNIT_TEST @CATCH2_CFLAGS@ $(AM_CFLAGS)
coord_tests_CPPFLAGS = -I$(top_srcdir)/lib/ $(AM_CPPFLAGS)
coord_tests_LDADD = @CATCH2_LIBS@ $(AM_LDFLAGS)
