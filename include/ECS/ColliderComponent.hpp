#ifndef SDL_ENGINE_COLLIDERCOMPONENT_HPP
#define SDL_ENGINE_COLLIDERCOMPONENT_HPP

#include "Coordinator.hpp"
#include <SDL2/SDL.h>

class ColliderComponent
{
    SDL_Rect collider;
    std::string tag;
    TransformComponent& transform;

    ColliderComponent()
    {}
    init(TransformComponent& transform)
    {
        this->transfor m= transform;
    }

    void update()
    {
        colloder.x = transform.position.x;
        collider.y = transform.position.y;
        collider.w = transform.width * transform.scale;
        collider.h = transform.height * transform.scale;
    }





};
#endif //SDL_ENGINE_COLLIDERCOMPONENT_HPP
