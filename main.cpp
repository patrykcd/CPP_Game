#include "GameEngine.h"
#include "Entity.h"
#include "Components/TransformComponent.h"
#include "Components/ImageComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/Shapes/RectangleShape.h"

using namespace Core;
using namespace Core::Components::Shapes;

class MyGame : public GameEngine {
    Entity entityGlobal = Entity::Create("game object red"); //std::make_shared<Entity>("game object red");
    std::shared_ptr<TransformComponent> transformComponentGlobal;

protected:
    void OnStart() override {
        std::shared_ptr<EntityGroup> scene;
        Entity entityLocal = Entity::Create("game object green"); //std::make_shared<Entity>("game object green");

        entityLocal->AddComponent<TransformComponent>(glm::vec2i(0, 50));
        entityLocal->AddComponent<ShapeComponent>(
                std::make_shared<RectangleShape>(glm::vec2i(100, 100)),
                glm::vec4i(255, 0, 0, 255)
        );

        entityGlobal->AddComponent<TransformComponent>(glm::vec2i(400, 300));
        entityGlobal->AddComponent<ShapeComponent>(
                std::make_shared<RectangleShape>(glm::vec2i(100, 100)),
                glm::vec4i(0, 255, 0, 255)
        );


        scene = std::make_shared<EntityGroup>();
        scene->AddEntity(entityLocal);
        scene->AddEntity(entityGlobal);
        SetScene(scene);
    }

    float step = 0.f;

    void OnUpdate(float deltaTime) override {
        auto entityLocal = GetScene()->GetEntityByName("game object green");
        auto transformComponentLocal = entityLocal->GetComponent<TransformComponent>();
        auto positionLocal = transformComponentLocal->GetPosition();
        positionLocal.x = (glm::sin(step) * 100) + (640 / 2);
        transformComponentLocal->SetPosition(positionLocal);


        transformComponentGlobal = entityGlobal->GetComponent<TransformComponent>();
        auto positionGlobal = transformComponentGlobal->GetPosition();
        positionGlobal.x = -(glm::sin(step) * 100) + (640 / 2);
        transformComponentGlobal->SetPosition(positionGlobal);

        step += 1 * deltaTime;
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
