#include "../include/GameObject.hpp"


GameObject::GameObject( const char *filename, float x, float y)
{
    ObjectTexture = TextureManager::LoadTexture(filename);
    xpos=x;
    ypos=y;
}

GameObject::~GameObject()
{}



void GameObject::update()
{
    xpos++;
    ypos++;

    srcRect.x=0;
    srcRect.y=0;
    srcRect.w=32;
    srcRect.h=32;

    destRect.x=xpos;
    destRect.y=ypos;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;
}

void GameObject::render()
{
 SDL_RenderCopy(Game::renderer,ObjectTexture,&srcRect,&destRect);
}