#pragma once
#include <memory>
#include "Component.h"
#include "GameEngineMath.h"

namespace Core::Components {
    class TransformComponent : public Component {
    public:
        TransformComponent();

        explicit TransformComponent(glm::vec2 vec2);

        void SetPosition(glm::vec2 vec2);

        glm::vec2 GetPosition();

        ~TransformComponent() override;

    private:
        glm::vec2 position;
        glm::vec2 scale;
    };
}

