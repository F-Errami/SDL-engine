#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Game.hpp"

Game *game=nullptr;

int main() {
   const int FPS = 60;
   const int frameDelay = 1000/FPS;

   Uint32 frameStart;
   int frameTime;

   game = new Game();
   game->init("Game engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();
        game->handleEvent();
        game->update();
        game->render();


        frameTime = SDL_GetTicks()-frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay-frameTime);
    }

    game->clean();

}
