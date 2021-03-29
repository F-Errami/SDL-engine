#pragma once


#include "Coordinator.hpp"
#include "Components.hpp"


 class PositionComponent
{
private:
    int xpos;
    int ypos;
public:
    PositionComponent(int x,int y)
    {
        xpos=x;
        ypos=y;
    }
    int x(){return xpos;}
    int y(){return ypos;}
};

