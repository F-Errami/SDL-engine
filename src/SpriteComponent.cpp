#include "../include/ECS/SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{}
SpriteComponent::~SpriteComponent()
{
    SDL_DestroyTexture(texture);
}
SpriteComponent::SpriteComponent(const char* fileName)
{
    texture = TextureManager::LoadTexture(fileName);

}

