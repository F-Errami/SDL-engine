#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"


 class PositionComponent
{
private:
    int xpos;
    int ypos;
public:
    PositionComponent()
    {
        xpos = ypos = 0;
    }
    PositionComponent(int x,int y)
    {
        xpos=x;
        ypos=y;
    }
    int x(){return xpos;}
    int y(){return ypos;}

    void setX(int p_x)
    {
        xpos=p_x;
    }
    void setY(int p_y)
    {
        ypos=p_y;
    }
};

