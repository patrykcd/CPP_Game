#pragma once
#include <memory>
#include "Component.h"
#include "Shapes/BaseShape.h"
#include "GameEngineMath.h"
#include <iostream>
namespace Core::Components {

    class ShapeComponent : public Component{
    public:
        ShapeComponent(std::shared_ptr<Shapes::BaseShape> shape, glm::vec4i color);
        ~ShapeComponent() override;
        std::shared_ptr<Shapes::BaseShape> GetShape();
        std::shared_ptr<Shapes::BaseShape> SetShape(std::shared_ptr<Shapes::BaseShape>);
        glm::vec4i GetColor();
        glm::vec4i SetSColor(glm::vec4i color);
    private:
        std::shared_ptr<Shapes::BaseShape> shape;
        glm::vec4i color;
    };
}