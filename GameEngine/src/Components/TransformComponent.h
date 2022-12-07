#include "Component.h"
#include "glm/glm.hpp"

class TransformComponent : public Component {
    glm::vec2 position;
public:
    TransformComponent(float x, float y);
    void update() override {};
};

