#include "GameEngine.h"
#include <iostream>

int Game()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *screen = SDL_CreateWindow("My application",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          0);
    SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    // A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;
    int i = 0;
    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
            {
                auto button = event.button;
                if (button.button == SDL_BUTTON_LEFT){
                    SDL_RenderDrawPoint(renderer, button.x, button.y);
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderPresent(renderer);
                    std::cout << "x: " << button.x << "y: " << button.y << std::endl;

                } else if (button.button == SDL_BUTTON_RIGHT){
//                    std::cout << "x: " << button.x << "y: " << button.y;
                }
            }
        }
//        SDL_RenderClear(renderer);
    }

    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 0;
}

int GameEngine::Run()
{
    isRunning = true;
    SDL_Event event;
    OnStart();
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else
            {
                OnHandleEvents(event);
            }
        }
//        SDL_SetRenderDrawColor(sdlRenderer.get(), 255, 0,0, 255);
//        SDL_Rect rect;
//        rect.x= 100;
//        rect.y=100;
//        rect.h = 100;
//        rect.w=100;
//        SDL_RenderFillRect(sdlRenderer.get(), &rect);
        OnRender(sdlRenderer.get());
        SDL_RenderPresent(sdlRenderer.get());
    }
    return 0;
}

GameEngine::GameEngine() :
    sdlWindow(nullptr, SDL_DestroyWindow),
    sdlRenderer(nullptr, SDL_DestroyRenderer),
    isRunning(false)
{
    if(SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        sdlWindow.reset(SDL_CreateWindow("Game Engine",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              640, 480,
                                              0));

        sdlRenderer.reset(SDL_CreateRenderer(sdlWindow.get(),-1,SDL_RENDERER_SOFTWARE));
        SDL_SetRenderDrawColor(sdlRenderer.get(), 0, 0, 0, 255);
        SDL_RenderClear(sdlRenderer.get());
    }
}

GameEngine::~GameEngine()
{
    SDL_Quit();
}