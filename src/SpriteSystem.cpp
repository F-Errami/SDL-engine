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


    std:: cout<<position.xpos<<" "<<position.ypos<<std::endl;
        position.ypos =0.0001+position.ypos ;
        position.xpos++;





        sprite.srcRect.x= sprite.srcRect.y=0;
        sprite.srcRect.w= sprite.srcRect.h=32;
        sprite.destRect.x=position.xpos*32;
        sprite.destRect.y=position.ypos*32;
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