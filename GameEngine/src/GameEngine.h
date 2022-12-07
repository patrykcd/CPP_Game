#pragma once
#include "SDL.h"
#include <memory>

class GameEngine {
private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> sdlWindow;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> sdlRenderer;
    bool isRunning;

public:
    GameEngine();
    int Run();

protected:
    virtual void OnStart() {};
    virtual void OnUpdate() {};
    virtual void OnEnd() {};
    virtual void OnHandleEvents(SDL_Event& event) {};
    virtual void OnRender(SDL_Renderer* renderer) {};
    ~GameEngine();
};
