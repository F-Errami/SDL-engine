#include "../include/ECS/SpriteSystem.hpp"
#include "../include/Game.hpp"
extern Coordinator gCoordinator;
void SpriteSystem::init()
{
    for (Entity const &entity : Entities) {
        TransformComponent &transform = gCoordinator.GetComponent<TransformComponent>(entity);
        SpriteComponent &sprite = gCoordinator.GetComponent<SpriteComponent>(entity);
        transform.init();

        sprite.srcRect.x = sprite.srcRect.y = 0;
        sprite.srcRect.w = sprite.srcRect.h = 32;
        sprite.destRect.x = (int) transform.position.x;
        sprite.destRect.y = (int) transform.position.y;
        sprite.destRect.w = 64;
        sprite.destRect.h = 64;
    }

    }


void SpriteSystem::update() {
    for (Entity const &entity : Entities) {
        TransformComponent &transform = gCoordinator.GetComponent<TransformComponent>(entity);
        SpriteComponent &sprite = gCoordinator.GetComponent<SpriteComponent>(entity);




            //keyboard Controller

            if (Game::event.type == SDL_KEYDOWN) {
                switch (Game::event.key.keysym.sym) {
                    case SDLK_w:
                        transform.velocity.y = -1;
                        break;
                    case SDLK_a:
                        transform.velocity.x = -1;
                        break;
                    case SDLK_d:
                        transform.velocity.x = 1;
                        break;
                    case SDLK_s:
                        transform.velocity.y = 1;
                        break;
                    default :
                        break;

                }
                if (Game::event.type == SDL_KEYUP) {
                    switch (Game::event.key.keysym.sym) {
                        case SDLK_w:
                            transform.velocity.y = 0;
                            break;
                        case SDLK_a:
                            transform.velocity.x = 0;
                            break;
                        case SDLK_d:
                            transform.velocity.x = 0;
                            break;
                        case SDLK_s:
                            transform.velocity.y = 0;
                            break;
                        default :
                            break;

                    }
                }


                transform.update();



                sprite.srcRect.x = sprite.srcRect.y = 0;
                sprite.srcRect.w = sprite.srcRect.h = 32;
                sprite.destRect.x = (int) transform.position.x;
                sprite.destRect.y = (int) transform.position.y;
                sprite.destRect.w = 64;
                sprite.destRect.h = 64;

            }
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