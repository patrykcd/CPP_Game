#include <gtest/gtest.h>
#include "Entity.h"
#include "Components/TransformComponent.h"
#include "glm/gtc/constants.hpp"

namespace Core::Components::UnitTests {
    class TransformComponentTest : public ::testing::Test {
    protected:
        Entity entity = Entity("Entity Name 1");

        const glm::vec2 VEC3_ZERO = glm::zero<glm::vec2>();
        const glm::vec2 VEC3_ONE = glm::one<glm::vec2>();
    };

    TEST_F(TransformComponentTest, AddComponent) {
        auto transform1 = entity.AddComponent<TransformComponent>();
        const auto position = transform1->GetPosition();
        ASSERT_TRUE(position == VEC3_ZERO);
        const auto transform2 = entity.GetComponent<TransformComponent>();
        ASSERT_EQ(&*transform1, &*transform2);
        transform1->SetPosition(VEC3_ONE);
        ASSERT_TRUE(transform2->GetPosition() == VEC3_ONE);
    }

    TEST_F(TransformComponentTest, GetComponent) {
        auto transform = entity.AddComponent<TransformComponent>();
        ASSERT_TRUE(transform->GetPosition() == VEC3_ZERO);
        transform->SetPosition(VEC3_ONE);
        ASSERT_TRUE(transform->GetPosition() == VEC3_ONE);
    }

    TEST_F(TransformComponentTest, DeleteComponent) {
        entity.AddComponent<TransformComponent>();
        auto transform = entity.GetComponent<TransformComponent>();
        ASSERT_TRUE(transform->GetPosition() == VEC3_ZERO);
        entity.DeleteComponent<TransformComponent>();
        const auto newPosition = glm::vec2(2, 3);
        transform = entity.AddComponent<TransformComponent>(newPosition);
        ASSERT_TRUE(transform->GetPosition() == newPosition);
    }
}