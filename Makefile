all:
	gcc main/*.cpp platform/engine-x11.cpp thirdparty/inih/*.c -std=c++11 -lstdc++ -lSDL2 -lSDL2_image -lGLEW -lGL -lm -o bin/HydrogenEngine