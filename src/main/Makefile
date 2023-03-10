# Makefile for subdir

# build shared library with -fPIC, -shared
CFLAGS    = # -g -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP -I../foo
LDFLAGS   = -L../foo # -shared
LDLIBS    = -lfoo
#CC       = $(CXX) # link with CXX for .cpp

LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../foo'
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../lib'
#LDFLAGS += -Wl,-soname,$(soname)

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
