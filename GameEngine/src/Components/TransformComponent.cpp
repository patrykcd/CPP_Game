#include "TransformComponent.h"

namespace Core::Components {
    TransformComponentWrapperItem::TransformComponentWrapperItem() : TransformComponentWrapperItem(
            glm::vec2(0.f, 0.f)) {}

    TransformComponentWrapperItem::TransformComponentWrapperItem(glm::vec2 vec2) {
        SetPosition(vec2);
    }

    void TransformComponentWrapperItem::SetPosition(glm::vec2 vec2) {
        position = vec2;
    }

    glm::vec2 TransformComponentWrapperItem::GetPosition() {
        return position;
    }

    TransformComponentWrapperItem::~TransformComponentWrapperItem() {

    }
}