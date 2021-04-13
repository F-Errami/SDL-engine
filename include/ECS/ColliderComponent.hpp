#ifndef SDL_ENGINE_COLLIDERCOMPONENT_HPP
#define SDL_ENGINE_COLLIDERCOMPONENT_HPP

#include "Coordinator.hpp"
#include <SDL2/SDL.h>
#include "TransformComponent.hpp"


class ColliderComponent
{
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent& transform;



    void init(TransformComponent& transform)
    {
        this->transform= transform;
    }

    void update()
    {
        collider.x = transform.position.x;
        collider.y = transform.position.y;
        collider.w = transform.width * transform.scale;
        collider.h = transform.height * transform.scale;
    }


};
#endif //SDL_ENGINE_COLLIDERCOMPONENT_HPP
