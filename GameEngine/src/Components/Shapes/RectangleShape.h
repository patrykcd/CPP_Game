#pragma once

#include "GameEngineMath.h"
#include "BaseShape.h"
#include <iostream>

namespace Core::Components::Shapes {
    class RectangleShape : public BaseShape {
    public:
        RectangleShape(glm::vec2i size);

        void SetSize(glm::vec2i size);

        glm::vec2i GetSize();

//        glm::vec2i GetNormalizedRectSize() override;
        ~RectangleShape() override;

    private:
        glm::vec2i size;
    };
}