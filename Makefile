CPPFLAGS = -std=c++11
LDFLAGS = -shared
LDLIBS = -lstdc++ -lSDL2 -lSDL2_image -lGLEW -lGL -lm

CPPOBJ = main/engineSettings.o main/graphics.o main/main.o platform/engine-x11.o
CPPDEPS = main/engineSettings.hpp main/graphics.hpp platform/engine-x11.hpp

CCOBJ = thirdparty/inih/ini.o
CCDEPS = thirdparty/inih/ini.h

all: bin/HydrogenEngine

# linux binary
bin/HydrogenEngine: $(CPPOBJ) $(CCOBJ)
	$(CXX) $(CPPFLAGS) -o bin/HydrogenEngine $(CPPOBJ) $(CCOBJ) $(LDLIBS)

# c++ code
$(CPPOBJ): %.o : %.cpp $(CPPDEPS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

# c code
$(CCOBJ): %.o : %.c $(CCDEPS)
	$(CC) -c $< -o $@

clean:
	$(RM) $(CPPOBJ) $(CCOBJ)