# build shared library with -fPIC, -shared
CFLAGS   = -fPIC # -g -O3 # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP -I../bar
LDFLAGS  = -shared -L../bar -Wl,-rpath,'$$ORIGIN/../bar'
LDLIBS   = -lbar
#CC      = $(CXX) # link with CXX for .cpp

LDFLAGS += -Wl,-rpath,'$$ORIGIN/../lib'
LDFLAGS += -Wl,-soname,$(soversion)

# make # NDEBUG=1
ifdef NDEBUG
CFLAGS += -O3 -DNDEBUG
else
CFLAGS += -g
LDFLAGS += -fsanitize=address
endif

# target name is basename of one of the source files
foo : $(patsubst %.c,%.o,$(wildcard *.c)) # .cpp
-include *.d
clean : ; -rm -fr *.o *.d foo *.so *.so.*
.PHONY : clean
