#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"
#include "../Math.hpp"


class TransformComponent
{
public:

    Vector2D position;
    Vector2D velocity;

    int speed =10;

    TransformComponent()
    {
        position.x= 0.0f;
        position.y = 0.0f;
    }
    void init()
    {
        velocity.x=0;
        velocity.y=0;
    }
    void update()
    {
        position.x += velocity.x*speed;
        position.y += velocity.y*speed;
    }

    TransformComponent(float x,float y)
    {
        position.x=x;
        position.y=y;
    }

};

