#pragma once

#ifndef SDL_ENGINE_SPRITESYSTEM_HPP
#define SDL_ENGINE_SPRITESYSTEM_HPP
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "Coordinator.hpp"
#include <SDL2/SDL.h>


class SpriteSystem:public System
{
public:
 void init();
 void update();
 void draw();
};


#endif //SDL_ENGINE_SPRITESYSTEM_H
