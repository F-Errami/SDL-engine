
#pragma once


#include "../Game.hpp"
#include "../TextureManager.hpp"
#include <SDL2/SDL.h>
#include "PositionComponent.hpp"
#include "PositionComponent.hpp"

extern Coordinator gCoordinator;

class SpriteComponent
{
public:
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;

};

