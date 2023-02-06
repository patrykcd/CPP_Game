#include "RectangleShape.h"

namespace Core::Components::Shapes {
    RectangleShapeWrapperItem::RectangleShapeWrapperItem(glm::vec2i size)  {
        SetSize(size);
    }

    void RectangleShapeWrapperItem::SetSize(glm::vec2i size) {
        this->size = size;
    }

    glm::vec2i RectangleShapeWrapperItem::GetSize() {
        return size;
    }

    RectangleShapeWrapperItem::~RectangleShapeWrapperItem() {

    }

//    glm::vec2i RectangleShape::GetNormalizedRectSize() {
//        throw std::logic_error("Function not yet implemented");
//    }
}