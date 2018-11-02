bin_PROGRAMS = onlinegame
onlinegame_SOURCES = main.cpp view_basic.h view_basic.cpp \
	view_color.h view_color.cpp controller.h controller.cpp\
	view_alter.h view_alter.cpp
onlinegame_CPPFLAGS = -I$(top_srcdir)/lib $(AM_CPPFLAGS)
onlinegame_CXXFLAGS = $(AM_CXXFLAGS)
onlinegame_LDADD = ../lib/libonlinegamecore.la $(AM_LDADD) -lncurses
