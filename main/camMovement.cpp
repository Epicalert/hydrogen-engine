#include "camMovement.hpp"

glm::vec3 hGetWASDMovement()
{
    glm::vec3 deltaPos = glm::vec3(0,0,0);
    if (hIsKeyDown(SDLK_w))
    {
        deltaPos += glm::vec3(0,0,1);
    }
    if (hIsKeyDown(SDLK_s))
    {
        deltaPos += glm::vec3(0,0,-1);
    }
    if (hIsKeyDown(SDLK_a))
    {
        deltaPos += glm::vec3(1,0,0);
    }
    if (hIsKeyDown(SDLK_d))
    {
        deltaPos += glm::vec3(-1,0,0);
    }

    return deltaPos;
}

glm::vec3 hGetQEMovement()
{
    glm::vec3 deltaPos = glm::vec3(0,0,0);
    if (hIsKeyDown(SDLK_q))
    {
        deltaPos += glm::vec3(0,-1,0);
    }
    if (hIsKeyDown(SDLK_e))
    {
        deltaPos += glm::vec3(0,1,0);
    }

    return deltaPos * 0.5f;
}