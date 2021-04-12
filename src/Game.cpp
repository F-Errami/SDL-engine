#include "../include/Game.hpp"






GameObject *enemy;

Map *map;

SDL_Renderer *Game::renderer= nullptr;
SDL_Event Game::event;


///////systems//////////////////////////////
std::shared_ptr<SpriteSystem> spriteSystem;

////////////////////////////////////////////


Coordinator gCoordinator;


Entity player ;

//constructor
Game::Game()
{}
//deconstructor
Game::~Game()
{}

void Game::init(char *title, int xpos, int ypos, int width, int height, bool fullScreen)
{
    int flag=0;
    if (fullScreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)>0) {
        std::cout << "Hey! SDL_Init failed..ERROR" << SDL_GetError() << std::endl;
        exit(1);
    }
    window=SDL_CreateWindow(title,xpos,ypos,width,height,flag);
    if (window == nullptr)
    {
      std::cout<<"SDL_CreateWindow failed.. ERROR"<<SDL_GetError()<<std::endl;
      exit(1);
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout<<"SDL_CreateRenderer failed.. ERROR"<<SDL_GetError()<<std::endl;
        exit(1);
    }
   SDL_SetRenderDrawColor(renderer,255,255,255,255);
    isRunning=true;

    gCoordinator.Init();
    gCoordinator.RegisterComponent<TransformComponent>();
    gCoordinator.RegisterComponent<SpriteComponent>();
    gCoordinator.RegisterComponent<ColliderComponent>();

    spriteSystem = gCoordinator.RegisterSystem<SpriteSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        signature.set(gCoordinator.GetComponentType<SpriteComponent>());
        gCoordinator.SetSystemSignature<SpriteSystem>(signature);
    }




    Entity const& player= gCoordinator.CreateEntity();


    gCoordinator.AddComponent<TransformComponent>(player,TransformComponent());

    gCoordinator.AddComponent<SpriteComponent>(player,SpriteComponent("images/player.png"));

    spriteSystem->init();






    enemy= new GameObject("images/enemy.png",50,50);
    map= new Map();







}

void Game::handleEvent()
{

    SDL_PollEvent(&event);
    switch (event.type)
    {

        case SDL_QUIT:
            isRunning=false;
            break;
        default :
            break;
    }
}


void Game::update()
{
 ++cnt;
 gCoordinator.GetComponent<TransformComponent>(player).position.Add(Vector2D());

 enemy->update();
 spriteSystem->update();


}


void Game::render()
{
    SDL_RenderClear(renderer);
    //this is where we would add stuff to render
    map->drawMap();
    spriteSystem->draw();
     enemy->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

