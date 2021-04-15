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



    void init(TransformComponent& transform);


    void update();

};
#endif //SDL_ENGINE_COLLIDERCOMPONENT_HPP
