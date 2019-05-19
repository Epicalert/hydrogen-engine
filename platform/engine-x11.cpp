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
#include "../main/graphics.hpp"

Engine::Engine(){}
Engine::~Engine(){}

bool Engine::isRunning()
{
    return running;
}

void Engine::initialize(const char* title)
{
    settings = new EngineSettings();

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(settings->GetTitle(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings->GetResX(), settings->GetResY(), SDL_WINDOW_OPENGL);

        if(!window)
        {
            std::cout << "ERROR: SDL could not create window." << std::endl;
            return;
        }

        SDL_GL_CreateContext(window);
        
        glewExperimental = GL_TRUE;
        glewInit();

        hInitGraphics();

        std::cout << "Hydrogen Engine initialized. Hello World!!" << std::endl;
    }
    else
    {
        //oof, an error
        std::cout << "ERROR: SDL could not initialize." << std::endl;
        return;
    }
}

void Engine::quit()
{
    running = false;

    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(glcontext);
    SDL_Quit();

    hCleanupGraphics();

    settings->~EngineSettings();

    std::cout << "Hydrogen Engine quit. Bye~!" << std::endl;
}

void Engine::render()
{
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(window);
}