#include <gtest/gtest.h>
#include "Entity.h"
#include "Components/TransformComponent.h"

class TransformComponentTest : public ::testing::Test {
protected:
    Entity entity;
};

TEST_F(TransformComponentTest, AddComponent) {
    auto transform1 = entity.AddComponent<TransformComponent>();
    auto transform2 = entity.GetComponent<TransformComponent>();
    ASSERT_EQ(&*transform1, &*transform2);
    ASSERT_FLOAT_EQ(transform1->GetPosition().x, 0);
    ASSERT_FLOAT_EQ(transform1->GetPosition().y, 0);
    ASSERT_FLOAT_EQ(transform2->GetPosition().x, 0);
    ASSERT_FLOAT_EQ(transform2->GetPosition().y, 0);
    transform1->SetPosition(glm::vec2(1, 1));
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 1);
    ASSERT_FLOAT_EQ(transform1->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(transform1->GetPosition().y, 1);
    ASSERT_FLOAT_EQ(transform2->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(transform2->GetPosition().y, 1);
}

TEST_F(TransformComponentTest, GetComponent) {
    entity.AddComponent<TransformComponent>();
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 0);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 0);
    entity.GetComponent<TransformComponent>()->SetPosition(glm::vec2(1, 1));
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 1);
}

TEST_F(TransformComponentTest, DeleteComponent) {
    entity.AddComponent<TransformComponent>();
    auto transform = entity.GetComponent<TransformComponent>();
    ASSERT_FLOAT_EQ(transform->GetPosition().x, 0);
    ASSERT_FLOAT_EQ(transform->GetPosition().y, 0);
    transform->SetPosition(glm::vec2(1, 1));
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 1);
    ASSERT_FLOAT_EQ(transform->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(transform->GetPosition().y, 1);
    entity.DeleteComponent<TransformComponent>();
    entity.AddComponent<TransformComponent>();
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 0);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 0);
}

TEST_F(TransformComponentTest, vec2Test) {
    glm::vec2 vec2(1, 2);
    auto transform = entity.AddComponent<TransformComponent>(vec2);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 2);
    vec2 = glm::vec2(3, 4);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 1);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 2);
    transform->SetPosition(vec2);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().x, 3);
    ASSERT_FLOAT_EQ(entity.GetComponent<TransformComponent>()->GetPosition().y, 4);
}