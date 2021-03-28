#pragma once

#ifndef SDL_ENGINE_COMPONENTS_H
#define SDL_ENGINE_COMPONENTS_H

#include "ECS/Coordinator.hpp"

class PositionComponent
{
private:
    int xpos;
    int ypos;

public:
    int x(){return xpos;}
    int y(){return ypos;}

    void setPos(int x,int y):
    xpos(x),ypos(y)
    {}
};

#endif //SDL_ENGINE_COMPONENTS_H
