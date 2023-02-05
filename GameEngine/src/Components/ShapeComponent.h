#pragma once
#include <memory>
#include "Component.h"
#include "Shapes/BaseShape.h"
#include "GameEngineMath.h"
#include <iostream>
namespace Core::Components {

    class ShapeComponent : public Component{
    public:
        ShapeComponent(const std::shared_ptr<Shapes::BaseShape>& shape, glm::vec4i color);
        ~ShapeComponent() override;
        std::shared_ptr<Shapes::BaseShape> GetShape();
        void SetShape(const std::shared_ptr<Shapes::BaseShape>& shape);
        glm::vec4i GetColor();
        void SetColor(glm::vec4i color);
    private:
        std::shared_ptr<Shapes::BaseShape> shape;
        glm::vec4i color;
    };
}