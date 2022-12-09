#include <gtest/gtest.h>
#include "Entity.h"
#include "Components/TransformComponent.h"

class EntityTest : public ::testing::Test {
protected:
    Entity entity;
};

TEST_F(EntityTest, AddComponent) {
    entity.AddComponent<TransformComponent>();
    ASSERT_THROW({
                     entity.AddComponent<TransformComponent>(1, 3);
                 }, std::exception);
}

TEST_F(EntityTest, DeleteComponent) {
    entity.AddComponent<TransformComponent>();
    entity.DeleteComponent<TransformComponent>();
    ASSERT_NO_THROW({
                        entity.AddComponent<TransformComponent>();
                    });
}

TEST_F(EntityTest, GetComponent) {
    entity.AddComponent<TransformComponent>();
    auto transform = entity.GetComponent<TransformComponent>();
    ASSERT_EQ(typeid(transform), typeid(std::shared_ptr<TransformComponent>));
}