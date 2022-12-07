//#include "GameEngine/Components/TransformComponent.h"
#include "GameEngine.h"
#include "Entity.h"
#include "Components/TransformComponent.h"

#include <iostream>

class MyGame : public GameEngine
{
protected:
    void OnStart() override {
        Entity entity;
        entity.AddComponent<TransformComponent>(1.0f, 3.2f);
//        entity.AddComponent<TransformComponent>(1.0f, 3.2f);
//        entity.AddComponent<TransformComponent>(1.0f, 3.2f);
        auto a = entity.GetComponent<TransformComponent>();

    }

    void OnUpdate() override {
    }

    void OnEnd() override {
    }

    void OnHandleEvents(SDL_Event &event) override {
        auto button = event.button;
        if (button.button == SDL_BUTTON_LEFT){

            std::cout << "x: " << button.x << "y: " << button.y << std::endl;

        } else if (button.button == SDL_BUTTON_RIGHT){
//                    std::cout << "x: " << button.x << "y: " << button.y;
        }
    }

    void OnRender(SDL_Renderer* renderer) override {
//        SDL_RenderDrawPoint(renderer, button.x, button.y);
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_RenderPresent(renderer);
    }


};

int main()
{
    return MyGame().Run();
}