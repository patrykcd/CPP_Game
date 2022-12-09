#include "Component.h"
#include "glm/glm.hpp"

class TransformComponent : public Component {
public:
    TransformComponent();
    TransformComponent(float x, float y);
    TransformComponent(glm::vec2 vec2);
    void SetPosition(glm::vec2 vec2);
    glm::vec2 GetPosition();
    void Update() override {};

private:
    glm::vec2 position;
};

