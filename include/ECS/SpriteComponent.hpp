
#pragma once


#include "../Game.hpp"
#include "../TextureManager.hpp"
#include <SDL2/SDL.h>
#include "TransformComponent.hpp"
#include "TransformComponent.hpp"


class SpriteComponent
{
public:
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;

    SpriteComponent(const char* fileName);
    SpriteComponent();


};

