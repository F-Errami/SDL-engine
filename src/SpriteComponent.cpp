#include "../include/ECS/SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{}
SpriteComponent::~SpriteComponent()
{}
SpriteComponent::SpriteComponent(const char* fileName)
{
    texture = TextureManager::LoadTexture(fileName);

}

