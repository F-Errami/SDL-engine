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
        PositionComponent& position = gCoordinator.GetComponent<PositionComponent>(entity);
        SpriteComponent& sprite = gCoordinator.GetComponent<SpriteComponent>(entity);

        SDL_Rect srcRect,destRect;
        srcRect.x= srcRect.y==0;

        position.setX(position.x()+1);
        position.setY(position.y()+1);





        sprite.srcRect.x= sprite.srcRect.y=0;
        sprite.srcRect.w= sprite.srcRect.h=32;
        sprite.destRect.x=position.x()*32;
        sprite.destRect.y=position.y()*32;
        sprite.destRect.w=64;
        sprite.destRect.h=64;

    }
}


void SpriteSystem::draw()
{
    for (Entity const& entity : Entities)
    {
        PositionComponent& position = gCoordinator.GetComponent<PositionComponent>(entity);
        SpriteComponent& sprite = gCoordinator.GetComponent<SpriteComponent>(entity);
        TextureManager::draw(sprite.texture,sprite.srcRect,sprite.destRect);
    }

}