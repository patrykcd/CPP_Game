#include "TransformComponent.h"

namespace Core::Components {
    TransformComponent::TransformComponent() : TransformComponent(glm::vec2(0.f, 0.f)) {}

    TransformComponent::TransformComponent(glm::vec2 vec2) {
        SetPosition(vec2);
    }

    void TransformComponent::SetPosition(glm::vec2 vec2) {
        position = vec2;
    }

    glm::vec2 TransformComponent::GetPosition() {
        return position;
    }

    TransformComponent::~TransformComponent() {

    }
}