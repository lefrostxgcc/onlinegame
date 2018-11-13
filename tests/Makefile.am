TESTS = coord_tests level_tests game_tests
check_PROGRAMS = coord_tests level_tests game_tests
coord_tests_SOURCES = main_tests.cpp coord_tests.cpp \
$(top_srcdir)/lib/coord.h \
$(top_srcdir)/lib/coord.cpp
coord_tests_CFLAGS = -DUNIT_TEST @CATCH2_CFLAGS@ $(AM_CFLAGS)
coord_tests_CPPFLAGS = -I$(top_srcdir)/lib/ $(AM_CPPFLAGS)
coord_tests_LDADD = @CATCH2_LIBS@ $(AM_LDFLAGS)

level_tests_SOURCES = main_tests.cpp level_tests.cpp \
$(top_srcdir)/lib/level.h \
$(top_srcdir)/lib/level.cpp \
$(top_srcdir)/lib/coord.h \
$(top_srcdir)/lib/coord.cpp \
$(top_srcdir)/lib/subject.h \
$(top_srcdir)/lib/matrix.hpp
level_tests_CFLAGS = -DUNIT_TEST @CATCH2_CFLAGS@ $(AM_CFLAGS)
level_tests_CPPFLAGS = -I$(top_srcdir)/lib/ $(AM_CPPFLAGS)
level_tests_LDADD = @CATCH2_LIBS@ $(AM_LDFLAGS)

game_tests_SOURCES = main_tests.cpp game_tests.cpp \
$(top_srcdir)/lib/iview.h \
$(top_srcdir)/lib/game.h \
$(top_srcdir)/lib/game.cpp \
$(top_srcdir)/lib/level.h \
$(top_srcdir)/lib/level.cpp \
$(top_srcdir)/lib/coord.h \
$(top_srcdir)/lib/coord.cpp \
$(top_srcdir)/lib/subject.h \
$(top_srcdir)/lib/matrix.hpp
game_tests_CFLAGS = -DUNIT_TEST @CATCH2_CFLAGS@ $(AM_CFLAGS)
game_tests_CPPFLAGS = -I$(top_srcdir)/lib/ $(AM_CPPFLAGS)
game_tests_LDADD = @CATCH2_LIBS@ $(AM_LDFLAGS)
