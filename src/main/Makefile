# Makefile for subdir

# library -fPIC -shared and executable -fPIE -pie
CFLAGS    = -g -fPIE # -fPIC -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP -I../foo
LDFLAGS   = -L../foo -pie # -shared
LDLIBS    = -lfoo
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../foo'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
#LDFLAGS += -Wl,-soname,$(soname)

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

all : main # foo

# target name is basename of one of the source files
main : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
#foo : $(patsubst %.c,%.o,foo.c) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d main
.PHONY : all clean
