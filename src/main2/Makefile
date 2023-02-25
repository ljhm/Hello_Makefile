# build shared library with -fPIC, -shared
CFLAGS   = #-g # -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP -I../foo
LDFLAGS  = -L../foo -Wl,-rpath,'$$ORIGIN/../foo' # -shared
LDLIBS   = -lfoo
#CC      = $(CXX) # link with CXX for .cpp

LDFLAGS += -Wl,-rpath,'$$ORIGIN/../lib'

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS += -O3 -DNDEBUG
else
CFLAGS += -g
LDFLAGS += -fsanitize=address
endif

# target name is basename of one of the source files
main2 : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d main2
.PHONY : clean
