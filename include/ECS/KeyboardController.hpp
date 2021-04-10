
#ifndef SDL_ENGINE_KEYBOARDCONTROLLER_HPP
#define SDL_ENGINE_KEYBOARDCONTROLLER_HPP

#include "../Game.hpp"
#include "Coordinator.hpp"

extern Coordinator gCoordinator;
class keyboardController :public system
{
    void init()
    {

    }


    void update()
    {
        for (Entity const& entity : Entities)
        {
            TransformComponent& transform = gCoordinator.GetComponent<TransformComponent>(entity);
            SpriteComponent& sprite = gCoordinator.GetComponent<SpriteComponent>(entity);

            if (Game::event.type == SDL_KEYDOWN)
            {
                switch(Game::event.key.keysym.sym)
                {
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
                        transform.velocity.y = -1;
                        break;
                    default :
                        break

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
                            break

                    }
                }
            }

        }
    }





};
#endif //SDL_ENGINE_KEYBOARDCONTROLLER_HPP
