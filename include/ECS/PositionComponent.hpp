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

    }
    int x(){return xpos;}
    int y(){return ypos;}

    void init()
    {
        xpos=0;
        ypos=0;
    }
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

