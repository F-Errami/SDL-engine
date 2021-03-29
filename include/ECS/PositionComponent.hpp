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
        xpos=0;
        ypos=0;
    }
    int x(){return xpos;}
    int y(){return ypos;}

    void update()
    {
        xpos++;
        ypos++;
    }
    void setPos(int x,int y)
    {
     xpos = x;
     ypos =y;
    }
};

