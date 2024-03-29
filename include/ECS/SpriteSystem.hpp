#pragma once

#ifndef SDL_ENGINE_SPRITESYSTEM_HPP
#define SDL_ENGINE_SPRITESYSTEM_HPP
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "Coordinator.hpp"
#include "System.hpp"
#include <SDL2/SDL.h>


class SpriteSystem:public System
{
public:
 void init();
 void update();
 void draw();
};


#endif //SDL_ENGINE_SPRITESYSTEM_H
