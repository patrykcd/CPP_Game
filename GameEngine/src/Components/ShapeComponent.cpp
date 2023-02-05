#include "ShapeComponent.h"
#include "Shapes/RectangleShape.h"
namespace Core::Components {
//    ShapeComponent::ShapeComponent() {}
    ShapeComponent::ShapeComponent(const std::shared_ptr<Shapes::BaseShape>& shape, glm::vec4i color) {
        SetShape(shape);
        SetColor(color);
    }

    std::shared_ptr<Shapes::BaseShape> ShapeComponent::GetShape() {
        return shape;
    }

    void ShapeComponent::SetShape(const std::shared_ptr<Shapes::BaseShape>& shape) {
        this->shape = shape;
    }

    glm::vec4i ShapeComponent::GetColor() {
        return color;
    }

    void ShapeComponent::SetColor(glm::vec4i color) {
        this->color = color;
    }

    ShapeComponent::~ShapeComponent() {

    }
}
