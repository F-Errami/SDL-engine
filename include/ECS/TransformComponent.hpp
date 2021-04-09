#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"
#include "../Math.hpp"


class TransformComponent
{
public:

    Vector2D position;
    TransformComponent()
    {
        position.x= 0.0f;
        position.y = 0.0f;
    }
    TransformComponent(float x,float y)
    {
        position.x=x;
        position.y=y;
    }

};

