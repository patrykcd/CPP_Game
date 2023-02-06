#pragma once

#include "Component.h"
#include "GameEngineMath.h"

namespace Core::Components {
    class TransformComponentWrapperItem : public ComponentWrapperItem {
    public:
        TransformComponentWrapperItem();

        explicit TransformComponentWrapperItem(glm::vec2 vec2);

        void SetPosition(glm::vec2 vec2);

        glm::vec2 GetPosition();

        virtual ~TransformComponentWrapperItem() override;

    private:
        glm::vec2 position;
        glm::vec2 scale;
    };

    using TransformComponent = Wrapper<TransformComponentWrapperItem>;
}

