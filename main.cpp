#include "GameEngine.h"
#include "Components/TransformComponent.h"
#include "Entity.h"
#include "Components/ImageComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/Shapes/RectangleShape.h"
using namespace Core;
using namespace Core::Components::Shapes;

class MyGame : public GameEngine {
    Entity entityGlobal = Entity::Create("game object red");
    TransformComponent transformComponentGlobal;

protected:
    void OnStart() override {
        std::cout << "start" << std::endl;
        Entity entityLocal = Entity::Create("game object green");
        entityLocal->AddComponent<TransformComponent>(glm::vec2i(0, 50));
        entityLocal->AddComponent<ShapeComponent>(
                RectangleShape::Create(glm::vec2i(100, 100)),
                glm::vec4i(255, 0, 0, 255)
        );

        entityGlobal->AddComponent<TransformComponent>(glm::vec2i(400, 300));
        entityGlobal->AddComponent<ShapeComponent>(
                RectangleShape::Create(glm::vec2i(100, 100)),
                glm::vec4i(0, 255, 0, 255)
        );


        EntityGroup scene = EntityGroup::Create();
        scene->AddEntity(entityLocal);
        SetScene(scene);
        scene->AddEntity(entityGlobal);
    }

    float step = 0.f;

    void OnUpdate(float deltaTime) override {
        auto entityLocal = GetScene()->GetEntityByName("game object green");
        auto transformComponentLocal = entityLocal->GetComponent<TransformComponent>();
        auto positionLocal = transformComponentLocal->GetPosition();
        positionLocal.x = (glm::sin(step) * 100) + (300 / 2);
        transformComponentLocal->SetPosition(positionLocal);


        transformComponentGlobal = entityGlobal->GetComponent<TransformComponent>();
        auto positionGlobal = transformComponentGlobal->GetPosition();
        positionGlobal.x = -(glm::sin(step) * 100) + (300 / 2);
        transformComponentGlobal->SetPosition(positionGlobal);
//        std::cout << positionGlobal.x << std::endl;

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

int main(int argc, char * argv[]) {
    return MyGame().Run();
}
