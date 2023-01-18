#include "RectangleShape.h"

namespace Core::Components::Shapes {
    RectangleShape::RectangleShape(glm::vec2i size)  {
        SetSize(size);
    }

    void RectangleShape::SetSize(glm::vec2i size) {
        this->size = size;
    }

    glm::vec2i RectangleShape::GetSize() {
        return size;
    }

    RectangleShape::~RectangleShape() {

    }

//    glm::vec2i RectangleShape::GetNormalizedRectSize() {
//        throw std::logic_error("Function not yet implemented");
//    }
}