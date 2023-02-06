#pragma once
#include <memory>
#include "Component.h"
#include "Shapes/BaseShape.h"
#include <GameEngineMath.h>
#include <iostream>
namespace Core::Components {
    class ShapeComponentWrapperItem : public ComponentWrapperItem{
    public:
        ShapeComponentWrapperItem(const Shapes::BaseShape& shape, glm::vec4i color);
        virtual ~ShapeComponentWrapperItem();
        Shapes::BaseShape GetShape();
        void SetShape(const Shapes::BaseShape& shape);
        glm::vec4i GetColor();
        void SetColor(glm::vec4i color);
    private:
        Shapes::BaseShape shape;
        glm::vec4i color;
    };

    using ShapeComponent = Wrapper<ShapeComponentWrapperItem>;
}