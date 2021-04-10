#pragma once
#ifndef SDL_GAME_GAME_HPP
#define SDL_GAME_GAME_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS/Coordinator.hpp"
#include "ECS/TransformComponent.hpp"
#include "ECS/SpriteComponent.hpp"
#include "ECS/SpriteSystem.hpp"





class Game
{
public:
    Game();
    ~Game();

    void init(char*title,int xpos,int ypos,int width,int height,bool fullscreen);
    void handleEvent();
    void update();
    void render();
    void clean();

    bool running()
    {
        return isRunning;
    };
    static SDL_Renderer* renderer;
    static SDL_Event event;

private:
    int cnt;
    bool isRunning;
    SDL_Window* window;




};













#endif //SDL_GAME_GAME_HPP
