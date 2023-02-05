#include "GameEngine.h"
#include <iostream>
#include <utility>
#include "Components/TransformComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/Shapes/RectangleShape.h"
#include "Timer.h"

namespace Core {
    const int SCREEN_FPS = 30;
    const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

    GameEngine::GameEngine() :
            sdlWindow(nullptr, SDL_DestroyWindow),
            sdlRenderer(nullptr, SDL_DestroyRenderer),
            isRunning(false) {
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            sdlWindow.reset(SDL_CreateWindow("Game Engine",
                                             SDL_WINDOWPOS_UNDEFINED,
                                             SDL_WINDOWPOS_UNDEFINED,
                                             640, 480,
                                             0));

            sdlRenderer.reset(SDL_CreateRenderer(sdlWindow.get(), -1, SDL_RENDERER_SOFTWARE));
            SDL_SetRenderDrawColor(sdlRenderer.get(), 0, 0, 0, 255);
            SDL_RenderClear(sdlRenderer.get());
        }
    }

    int GameEngine::Run() {
        isRunning = true;
        SDL_Event event;

//        Timer fpsTimer;
        Timer capTimer;

        float countedFrames = 0;
//        fpsTimer.Start();
        Timer delta;

        OnStart();

        while (isRunning) {
            capTimer.Start();
//            float avgFPS = countedFrames / (fpsTimer.GetTicks() / 1000.0f);
//            std::cout << avgFPS << std::endl;
            ++countedFrames;

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    isRunning = false;
                } else {
                    OnHandleEvents(event);
                }
            }
            OnUpdate(static_cast<float>(delta.GetTicks()) / 1000.f);
            delta.Start();

            for (size_t i = 0; i < scene->Count(); i++) {
                auto entity = scene->GetEntityByIndex(i);
                auto transformComponent = entity->GetComponent<TransformComponent>();
                auto shapeComponent = entity->GetComponent<ShapeComponent>();
                SDL_SetRenderDrawColor(sdlRenderer.get(), 255, 0, 0, 255);
                SDL_Rect rect;
                auto position = transformComponent->GetPosition();
                rect.x = static_cast<int>(position.x);
                rect.y = static_cast<int>(position.y);
                auto shape = shapeComponent->GetShape();
                auto rectangleShape = std::dynamic_pointer_cast<Shapes::RectangleShape>(shape);
                auto rectangleSize = rectangleShape->GetSize();
                rect.w = rectangleSize.x;
                rect.h = rectangleSize.y;
                auto shapeColor = shapeComponent->GetColor();
                SDL_SetRenderDrawColor(sdlRenderer.get(), shapeColor.r, shapeColor.g, shapeColor.b, shapeColor.a);
                SDL_RenderFillRect(sdlRenderer.get(), &rect);
            }

            SDL_RenderPresent(sdlRenderer.get());
            SDL_SetRenderDrawColor(sdlRenderer.get(), 0, 0, 0, 255);
            SDL_RenderClear(sdlRenderer.get());

            Uint32 frameTicks = capTimer.GetTicks();
            if (frameTicks < SCREEN_TICK_PER_FRAME) {
                SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
            }
        }
        return 0;
    }

    void GameEngine::SetScene(std::shared_ptr<EntityGroup> scene) {
        this->scene = scene;
    }

    std::shared_ptr<EntityGroup> GameEngine::GetScene() {
        return this->scene;
    }

    GameEngine::~GameEngine() {
        SDL_Quit();
    }
}