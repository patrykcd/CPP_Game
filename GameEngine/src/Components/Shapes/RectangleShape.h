#pragma once

#include "GameEngineMath.h"
#include "BaseShape.h"
#include <iostream>

namespace Core::Components::Shapes {
    class RectangleShapeWrapperItem : public BaseShapeWrapperItem {
    public:
        RectangleShapeWrapperItem(glm::vec2i size);

        void SetSize(glm::vec2i size);

        glm::vec2i GetSize();

//        glm::vec2i GetNormalizedRectSize() override;
        ~RectangleShapeWrapperItem() override;

    private:
        glm::vec2i size;
    };

    using RectangleShape = Wrapper<RectangleShapeWrapperItem>;
}