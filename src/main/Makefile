# Makefile for subdir

# executable -fPIE -pie and library -fPIC -shared
CFLAGS    = -g -fPIE # -fPIC -O3 # CXXFLAGS for .cpp
CPPFLAGS  = -MMD -MP -I../foo
LDFLAGS   = -L../foo -pie # -shared
LDLIBS    = -lfoo
#CC       = $(CXX) # link with CXX for .cpp

#LDFLAGS += -Wl,-soname,$(MAJOR)
#LDFLAGS += -install_name libfoo.so.$(MAJOR) -current_version $(VER) -compatibility_version $(MAJOR) # macos

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS   += -O3 # .cpp
CPPFLAGS += -DNDEBUG
else
CFLAGS   += -fsanitize=address -g # .cpp
LDFLAGS  += -fsanitize=address
endif

all : main # foo

# target name is basename of one of the source files
main : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
#foo : $(patsubst %.c,%.o,foo.c) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d main
.PHONY : all clean
