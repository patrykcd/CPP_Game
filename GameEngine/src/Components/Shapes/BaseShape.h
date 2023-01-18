#pragma once
#include "Components/Component.h"
#include "GameEngineMath.h"

namespace Core::Components::Shapes {
    class BaseShape : public Component {
    public:
        BaseShape();
//        virtual glm::vec2i GetNormalizedRectSize() = 0;
        ~BaseShape() override;
    };
}
