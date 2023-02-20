#include "GameEngine.h"
#include <SDL_main.h>
#include <iostream>
#include <utility>
#include "Components/TransformComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/Shapes/RectangleShape.h"
#include "Timer.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

namespace Core {
    const int SCREEN_FPS = 30;
    const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

    GameEngine::GameEngine() :
            isRunning(false) {
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
            sdlWindow = SDL_CreateWindow("Game Engine",
                                         SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED,
                                         600, 600,
                                         0);

            if (sdlWindow == 0) {
                std::cout << "Could not initialize Window";
            }

            sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_SOFTWARE);

            if (!sdlRenderer) {
                std::cout << "Could not create renderer";
            }


            SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
            SDL_RenderClear(sdlRenderer);
        } else{
            std::cout << "Could not initialize SDL" << std::endl;
            std::cout << SDL_GetError() << std::endl;
        }
    }

    struct LoopData {
        SDL_Renderer *sdlRenderer;
        SDL_Event* event;

        std::function<void(float time)> onUpdateCallback;
        std::function<void(SDL_Event)> onHandleEvents;

        bool* isRunning;
        Timer* capTimer;
        float* countedFrames;
        Timer* delta;
        EntityGroup* scene;
    };

    void Loop(void *data) {
        auto *loopData = static_cast<LoopData *>(data);
        SDL_Renderer *&sdlRenderer = loopData->sdlRenderer;
        bool& isRunning = *loopData->isRunning;;
        SDL_Event &event = *loopData->event;;
        Timer &capTimer = *loopData->capTimer;;
        float &countedFrames = *loopData->countedFrames;;
        Timer &delta = *loopData->delta;;
        auto onUpdate = loopData->onUpdateCallback;
        auto onHandleEvents = loopData->onHandleEvents;
        EntityGroup &scene = *loopData->scene;

        capTimer.Start();
//            float avgFPS = countedFrames / (fpsTimer.GetTicks() / 1000.0f);
//            std::cout << avgFPS << std::endl;
        ++countedFrames;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
#ifdef __EMSCRIPTEN__
                emscripten_cancel_main_loop();
#endif
            } else {
                onHandleEvents(event);
            }
        }

//        loopData->onUpdate();
        onUpdate(static_cast<float>(delta.GetTicks()) / 1000.f);
        delta.Start();

        for (size_t i = 0; i < scene->Count(); i++) {
            auto entity = scene->GetEntityByIndex(i);
            auto transformComponent = entity->GetComponent<TransformComponent>();
            auto shapeComponent = entity->GetComponent<ShapeComponent>();
            SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, 255);
            SDL_Rect rect;
            auto position = transformComponent->GetPosition();
            rect.x = static_cast<int>(position.x);
            rect.y = static_cast<int>(position.y);
            auto shape = shapeComponent->GetShape();
            Shapes::RectangleShape rectangleShape = shape;
            auto rectangleSize = rectangleShape->GetSize();
            rect.w = rectangleSize.x;
            rect.h = rectangleSize.y;
            auto shapeColor = shapeComponent->GetColor();
            SDL_SetRenderDrawColor(sdlRenderer, shapeColor.r, shapeColor.g, shapeColor.b, shapeColor.a);
            SDL_RenderFillRect(sdlRenderer, &rect);
        }

        SDL_RenderPresent(sdlRenderer);
        SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
        SDL_RenderClear(sdlRenderer);

        Uint32 frameTicks = capTimer.GetTicks();
        if (frameTicks < SCREEN_TICK_PER_FRAME) {
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }

    int GameEngine::Run() {
        void (*fun)(void *data) = &Loop;
        isRunning = true;
        float countedFrames = 0;
        LoopData data;
        data.isRunning = &isRunning;

        data.sdlRenderer = sdlRenderer;
        SDL_Event event;
        data.event = &event;
        Timer capTimer;
        data.capTimer = &capTimer;
        data.countedFrames = &countedFrames;
        Timer delta;
        data.delta = &delta;

        OnStart();

        data.onUpdateCallback = [&](float time) { OnUpdate(time); };
        data.onHandleEvents = [&](SDL_Event event) { OnHandleEvents(event); };
        data.scene = &scene;


#ifdef __EMSCRIPTEN__
        emscripten_set_main_loop_arg(Loop, &data, -1, 1);
#endif
        while (isRunning) {
            Loop(&data);
        }
        return 0;
    }

    void GameEngine::SetScene(const EntityGroup &scene) {
        this->scene = scene;
    }

    EntityGroup GameEngine::GetScene() {
        return this->scene;
    }

    GameEngine::~GameEngine() {
        SDL_DestroyRenderer(sdlRenderer);
        SDL_DestroyWindow(sdlWindow);
        SDL_Quit();
    }
}