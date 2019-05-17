#include <SDL2/SDL.h>

#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>

#include "engine-x11.hpp"

Engine::Engine(){}
Engine::~Engine(){}

void Engine::initialize(const char* title)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
        
        glewExperimental = GL_TRUE;
        glewInit();

        glClearColor(0,0,1,1);
    }
    else
    {
        //oof, an error
        std::cout << "ERROR: SDL could not initialize." << std::endl;
        return;
    }
}