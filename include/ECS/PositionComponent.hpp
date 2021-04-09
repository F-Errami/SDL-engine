#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"


class PositionComponent
{
public:

    float xpos;
    float ypos;
    PositionComponent()
    {
        xpos = ypos = 0;
    }
    PositionComponent(int x,int y)
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

