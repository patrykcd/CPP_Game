#include "ShapeComponent.h"

namespace Core::Components {
//    ShapeComponent::ShapeComponent() {}
    ShapeComponent::ShapeComponent(std::shared_ptr<Shapes::BaseShape> shape, glm::vec4i color) {
        this->shape = shape;
        this->color = color;
    }

    std::shared_ptr<Shapes::BaseShape> ShapeComponent::GetShape() {
        return shape;
    }

    std::shared_ptr<Shapes::BaseShape> ShapeComponent::SetShape(std::shared_ptr<Shapes::BaseShape> shape) {
        this->shape = shape;
    }

    glm::vec4i ShapeComponent::GetColor() {
        return color;
    }

    glm::vec4i ShapeComponent::SetSColor(glm::vec4i color) {
        this->color = color;
    }

    ShapeComponent::~ShapeComponent() {

    }
}
