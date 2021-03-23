#pragma once
#ifndef SDL_GAME_GAMEOBJECT_HPP
#define SDL_GAME_GAMEOBJECT_HPP
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"

class GameObject
{
public:
    GameObject(const char* filename,float x,float y);
    ~GameObject();
    void update();
    void render();

private:
    SDL_Texture* ObjectTexture;
    float xpos,ypos;
    SDL_Rect srcRect,destRect;

};

#endif //SDL_GAME_GAMEOBJECT_HPP
