#include "ShapeComponent.h"
#include "Shapes/RectangleShape.h"
namespace Core::Components {
//    ShapeComponent::ShapeComponent() {}
    ShapeComponentWrapperItem::ShapeComponentWrapperItem(const Shapes::BaseShape& shape, glm::vec4i color) {
        SetShape(shape);
        SetColor(color);
    }

    Shapes::BaseShape ShapeComponentWrapperItem::GetShape() {
        return shape;
    }

    void ShapeComponentWrapperItem::SetShape(const Shapes::BaseShape& shape) {
        this->shape = shape;
    }

    glm::vec4i ShapeComponentWrapperItem::GetColor() {
        return color;
    }

    void ShapeComponentWrapperItem::SetColor(glm::vec4i color) {
        this->color = color;
    }

    ShapeComponentWrapperItem::~ShapeComponentWrapperItem() {

    }
}
