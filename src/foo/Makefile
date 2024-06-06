# Makefile for subdir

# library -fPIC -shared and executable -fPIE -pie
CFLAGS    = -g -fPIC # -fPIE -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP # -I../bar
LDFLAGS   = -shared # -pie -L../bar
LDLIBS    = # -lbar
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../bar'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
LDFLAGS  += -Wl,-soname,$(soname)

# turn off sanitizer to build a debug version for gdb
# LeakSanitizer does not work under ptrace (strace, gdb, etc)

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS   += -O3 # .cpp
CPPFLAGS += -DNDEBUG
else
CFLAGS   += -g # .cpp
LDFLAGS  += -fsanitize=address
endif

all : foo # bar

# target name is basename of one of the source files
foo : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
#bar : $(patsubst %.c,%.o,bar.c) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d foo *.so*
.PHONY : all clean
