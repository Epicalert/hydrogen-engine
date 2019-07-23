CC=$(CROSS)gcc
CXX=$(CROSS)gcc
LD=$(CROSS)ld
AR=$(CROSS)ar
PKG_CONFIG=$(CROSS)pkg-config

CPPFLAGS = -std=c++11 `$(CROSS)sdl2-config --cflags` `$(PKG_CONFIG) --cflags glew`
LDFLAGS = -shared
LDLIBS = -lstdc++ `$(CROSS)sdl2-config --libs` `$(PKG_CONFIG) --libs glew` -lm -lSDL2_image -ljpeg -lpng -lwebp -lz

CPPOBJ = main/engineSettings.o main/graphics.o main/main.o platform/engine-x11.o
CPPDEPS = main/engineSettings.hpp main/graphics.hpp platform/engine-x11.hpp

CCOBJ = thirdparty/inih/ini.o
CCDEPS = thirdparty/inih/ini.h

all: bin/HydrogenEngine

# binary
# for compiling on windows, set EXESUFFIX=.exe
bin/HydrogenEngine: $(CPPOBJ) $(CCOBJ)
	echo $(LDLIBS)
	$(CXX) $(CPPFLAGS) -o bin/HydrogenEngine$(EXESUFFIX) $(CPPOBJ) $(CCOBJ) $(LDLIBS)

# c++ code
$(CPPOBJ): %.o : %.cpp $(CPPDEPS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

# c code
$(CCOBJ): %.o : %.c $(CCDEPS)
	$(CC) -c $< -o $@

clean:
	$(RM) $(CPPOBJ) $(CCOBJ) bin/HydrogenEngine