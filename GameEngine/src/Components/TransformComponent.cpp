#include "TransformComponent.h"

TransformComponent::TransformComponent() {
    position.x = 0;
    position.y = 0;
}

TransformComponent::TransformComponent(float x, float y) {
    position.x = x;
    position.y = y;
}

TransformComponent::TransformComponent(glm::vec2 vec2) {
    SetPosition(vec2);
}

void TransformComponent::SetPosition(glm::vec2 vec2)
{
    position = vec2;
}

glm::vec2 TransformComponent::GetPosition()
{
    return position;
}