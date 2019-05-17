/*
   Hydrogen Engine
       https://github.com/Epicalert/hydrogen-engine

   Copyright 2019 Amado Wilkins

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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