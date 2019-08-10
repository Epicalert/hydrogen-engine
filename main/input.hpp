#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>

#include <map>

void hKeyDownEvent(SDL_Keycode key);
void hKeyUpEvent(SDL_Keycode key);

bool hIsKeyDown(SDL_Keycode key);

#endif