#pragma once
#include "Components/Component.h"
#include "GameEngineMath.h"

namespace Core::Components::Shapes {
    class BaseShapeWrapperItem : public WrapperItem {
    public:
        BaseShapeWrapperItem();
//        virtual glm::vec2i GetNormalizedRectSize() = 0;
        virtual ~BaseShapeWrapperItem();
    };

    using BaseShape = Wrapper<BaseShapeWrapperItem>;
}
