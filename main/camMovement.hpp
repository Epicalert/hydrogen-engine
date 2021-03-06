#ifndef CAMMOVEMENT_HPP
#define CAMMOVEMENT_HPP

#include "SDL2/SDL.h"
#include "glm/glm.hpp"

#include "input.hpp"

// get movement for controlling with WASD
glm::vec3 hGetWASDMovement();

// get up/down movement with Q & E
glm::vec3 hGetQEMovement();

#endif