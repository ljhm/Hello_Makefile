# build shared library with -fPIC, -shared
CFLAGS   = -g -fPIC # -O3 # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP # -I../foo
LDFLAGS  = -shared # -L../foo -Wl,-rpath,'$$ORIGIN/../foo' #
LDLIBS   = # -lfoo
#CC      = $(CXX) # link with CXX for .cpp

LDFLAGS += -Wl,-soname,$(soversion)

# target name is basename of one of the source files
bar : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d bar *.so *.so.*
.PHONY : clean
