#include "../include/Map.hpp"

int lvl1[20][25] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,2,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,2,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};




Map::Map()
{
    water=TextureManager::LoadTexture("images/water.png");
    grass=TextureManager::LoadTexture("images/grass.png");
    dirt=TextureManager::LoadTexture("images/dirt.png");

    src.x=src.y=dest.x=dest.y=0;
    src.w=src.h=dest.w=dest.h=32;

    LoadMap(lvl1);
}

Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(dirt);
}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20 ; ++row)
    {
        for (int column = 0; column < 25 ; ++column)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::drawMap()
{
    int type=0;
    for (int row = 0; row < 20 ; ++row)
    {
        for (int column = 0; column <25 ; ++column)
        {
            type = map[row][column];
            dest.x = 32*column;
            dest.y = 32*row;
            switch (type)
            {
                case WATER:
                    TextureManager::draw(water,src,dest);
                    break;
                case GRASS:
                    TextureManager::draw(grass,src,dest);
                    break;
                case DIRT:
                    TextureManager::draw(dirt,src,dest);
                    break;

            }
        }
    }
}