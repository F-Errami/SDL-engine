#include "../include/ECS/SpriteSystem.hpp"
#include "../include/Game.hpp"
extern Coordinator gCoordinator;
void SpriteSystem::init()
{

}


void SpriteSystem::update()
{
    for (Entity const& entity : Entities)
    {
        TransformComponent& transform = gCoordinator.GetComponent<TransformComponent>(entity);
        SpriteComponent& sprite = gCoordinator.GetComponent<SpriteComponent>(entity);

        SDL_Rect srcRect,destRect;
        srcRect.x= srcRect.y==0;






        sprite.srcRect.x= sprite.srcRect.y=0;
        sprite.srcRect.w= sprite.srcRect.h=32;
        sprite.destRect.x = (int)transform.position.x;
        sprite.destRect.y = (int)transform.position.y;
        sprite.destRect.w=64;
        sprite.destRect.h=64;

    }
}


void SpriteSystem::draw()
{
    for (Entity const& entity : Entities)
    {
        TransformComponent& position = gCoordinator.GetComponent<TransformComponent>(entity);
        SpriteComponent& sprite = gCoordinator.GetComponent<SpriteComponent>(entity);
        TextureManager::draw(sprite.texture,sprite.srcRect,sprite.destRect);
    }

}