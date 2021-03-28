
#pragma once
#include "PositionComponent.hpp"
#include "Components.hpp"
#include <SDL2/SDL.h>
#include "../Game.hpp"
#include"../TextureManager.hpp"


extern Coordinator gCoordinator;

class SpriteComponent
{
private:

    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;


public:
    SpriteComponent() = default;

    SpriteComponent(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }


    void init(Entity entity)
    {
     position = &gCoordinator.GetComponent<PositionComponent>(entity);

     position =
     srcRect.x=srcRect.y=0;
     srcRect.w=srcRect.h=32;
     destRect.w=destRect.h=64;
    }


    void update()
    {
     destRect.x = position->x;
     destRect.y = position->y;
    }

    void draw()
    {
        TextureManager::draw( texture,srcRect,destRect);
    }

};

