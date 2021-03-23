#pragma once

#ifndef SDL_GAME_MAP_HPP
#define SDL_GAME_MAP_HPP
#include "TextureManager.hpp"
#define WATER 0
#define GRASS 1
#define DIRT 2


class Map
{
public:
      Map();
      ~Map();
      void LoadMap(int arr[20][25]);
      void drawMap();

private:
    SDL_Rect src,dest;

    SDL_Texture *water;
    SDL_Texture *grass;
    SDL_Texture *dirt;

    int map[20][25];

};
#endif //SDL_GAME_MAP_HPP
