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

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

class Engine{
    public:
        Engine();
        ~Engine();

        //returns true if the game loop should be running
        bool isRunning();

        //initializes the engine
        void initialize(const char* title);
        //cleans up everything and quits
        void quit();

        //renders a frame (call in main loop, once per frame)
        void render();
    private:
        bool running = true;
        
        SDL_Window *window;
        SDL_GLContext *glcontext;
};
#endif