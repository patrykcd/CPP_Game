#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "EntityGroup.h"
#include <memory>

namespace Core {
    class GameEngine {
    public:
        GameEngine();

        int Run();

        void SetScene(EntityGroup& scene);

    protected:
        virtual void OnStart() {};

        virtual void OnUpdate(float deltaTime) {};

        virtual void OnEnd() {};

        virtual void OnHandleEvents(SDL_Event &event) {};

//        virtual void OnRender(SDL_Renderer *renderer) {};

        ~GameEngine();

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> sdlWindow;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> sdlRenderer;
        bool isRunning;

        EntityGroup scene;
    };
}