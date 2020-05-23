CC=$(CROSS)gcc
CXX=$(CROSS)gcc
LD=$(CROSS)ld
AR=$(CROSS)ar
PKG_CONFIG=$(CROSS)pkg-config

CPPFLAGS = -std=c++11 `$(CROSS)sdl2-config --cflags` `$(PKG_CONFIG) --cflags glew`
LDFLAGS = -shared
LDLIBS = -lstdc++ `$(CROSS)sdl2-config --libs` `$(PKG_CONFIG) --libs glew` -lm -lSDL2_image -ljpeg -lpng -lwebp -lz

CPPOBJ = main/engineSettings.o main/graphics.o main/input.o main/main.o platform/engine-x11.o main/camMovement.o

CCOBJ = thirdparty/inih/ini.o

all: HydrogenEngine

# binary
# for compiling on windows, set EXESUFFIX=.exe
HydrogenEngine: $(CPPOBJ) $(CCOBJ)
	$(CXX) $(CPPFLAGS) -o HydrogenEngine$(EXESUFFIX) $(CPPOBJ) $(CCOBJ) $(LDLIBS)

main/camMovement.cpp: main/camMovement.hpp main/input.hpp
main/engineSettings.cpp: main/engineSettings.hpp thirdparty/inih/ini.h
main/graphics.cpp: main/graphics.hpp
main/main.cpp: platform/engine-x11.hpp

platform/engine-x11.cpp: platform/engine-x11.hpp main/graphics.hpp

clean:
	$(RM) $(CPPOBJ) $(CCOBJ) HydrogenEngine
