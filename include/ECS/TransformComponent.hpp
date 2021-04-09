#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"


class TransformComponent
{
public:

    float xpos;
    float ypos;
    TransformComponent()
    {
        xpos = ypos = 0;
    }
    TransformComponent(int x,int y)
    {
        xpos=x;
        ypos=y;
    }

    void setX(int p_x)
    {
        xpos=p_x;
    }
    void setY(int p_y)
    {
        ypos=p_y;
    }
};

