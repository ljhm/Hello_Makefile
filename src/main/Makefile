# build shared library with -fPIC, -shared
CFLAGS   = # -g -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP -I../foo
LDFLAGS  = -L../foo -Wl,-rpath,'$$ORIGIN/../foo' # -shared
LDLIBS   = -lfoo
#CC      = $(CXX) # link with CXX for .cpp

LDFLAGS += -Wl,-rpath,'$$ORIGIN/../lib'
#LDFLAGS += -Wl,-soname,$(soname)

# make # NDEBUG=1
ifdef NDEBUG
CPPFLAGS += -DNDEBUG
CFLAGS += -O3 # .cpp
else
CFLAGS += -g # .cpp
LDFLAGS += -fsanitize=address
endif

all : main # foo

# target name is basename of one of the source files
main : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d main
.PHONY : all clean
