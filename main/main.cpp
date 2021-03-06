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

#define PLAT_X11
#ifdef PLAT_X11
#include "../platform/engine-x11.hpp"
#endif

#include "input.hpp"

#include <SDL2/SDL.h>
#include <glm/vec3.hpp>

#include <iostream>

int main(int argc, char *argv[])
{
    Engine *engine = new Engine();

    engine->initialize("Hydrogen Engine");

    while(engine->isRunning())
    {
        SDL_Event event;
		while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    engine->quit();
                    break;

                case SDL_KEYDOWN:
                    hKeyDownEvent(event.key.keysym.sym);
                    break;

                case SDL_KEYUP:
                    hKeyUpEvent(event.key.keysym.sym);
                    break;

            }
        }

        engine->render();
    }

    engine->~Engine();

    return 0;
}