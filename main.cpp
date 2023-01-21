#include "GameEngine.h"
#include "Entity.h"
#include "Components/TransformComponent.h"
#include "Components/ImageComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/Shapes/RectangleShape.h"

using namespace Core;
using namespace Core::Components::Shapes;

class MyGame : public GameEngine {
protected:
    EntityGroup scene;

    std::shared_ptr<TransformComponent> transformComponent1;
    std::shared_ptr<TransformComponent> transformComponent2;

    void OnStart() override {
        Entity entity1("game object 1");
        transformComponent1 = entity1.AddComponent<TransformComponent>(glm::vec2i(0, 50));
        entity1.AddComponent<ShapeComponent>(
                std::make_shared<RectangleShape>(glm::vec2i(100, 100)),
                glm::vec4i(255, 0, 0, 255)
        );

        Entity entity2("game object 1");
        transformComponent2 = entity2.AddComponent<TransformComponent>(glm::vec2i(400, 300));
        entity2.AddComponent<ShapeComponent>(
                std::make_shared<RectangleShape>(glm::vec2i(100, 100)),
                glm::vec4i(0, 255, 0, 255)
        );


        scene = EntityGroup();
        scene.AddEntity(entity1);
        scene.AddEntity(entity2);
        SetScene(scene);
    }

    float step = 0.f;

    void OnUpdate(float deltaTime) override {
        auto position1 = transformComponent1->GetPosition();
        step += 1 * deltaTime;
        position1.x = (glm::sin(step) * 100) + (640 / 2);
        transformComponent1->SetPosition(position1);

        auto position2 = transformComponent2->GetPosition();
        position2.x = -(glm::sin(step) * 100) + (640 / 2);
        transformComponent2->SetPosition(position2);
    }

    void OnEnd() override {
    }

    void OnHandleEvents(SDL_Event &event) override {
        auto button = event.button;
        if (button.button == SDL_BUTTON_LEFT) {
        } else if (button.button == SDL_BUTTON_RIGHT) {
        }
    }
};

int main() {
    return MyGame().Run();
}

//        auto image = entity->AddComponent<ImageComponent>("Assets/Image.jpg");
