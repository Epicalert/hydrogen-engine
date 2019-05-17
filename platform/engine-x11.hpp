#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

class Engine{
    public:
        Engine();
        ~Engine();
        void initialize(const char* title);
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};
#endif