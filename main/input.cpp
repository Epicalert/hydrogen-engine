#include "input.hpp"

std::map<int,bool> hKeymap;

void hKeyDownEvent(SDL_Keycode key)
{
    hKeymap[key] = true;
}

void hKeyUpEvent(SDL_Keycode key)
{
    hKeymap[key] = false;
}

bool hIsKeyDown(SDL_Keycode key)
{
    return hKeymap[key];
}