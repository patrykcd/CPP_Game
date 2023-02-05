#include <gtest/gtest.h>
#include "Entity.h"
#include "Components/TransformComponent.h"
#include "Components/ImageComponent.h"

namespace Core::UnitTests {

    class EntityTest : public ::testing::Test {
    protected:
        Entity entity = Entity::Create("Entity Name 1");
    };

    TEST_F(EntityTest, Init) {
        ASSERT_STREQ(entity->GetName().c_str(), "Entity Name 1");
        std::string entity2name = "Entity Name 2";
        Entity entity2 = Entity::Create(entity2name);
        ASSERT_STREQ(entity2->GetName().c_str(), entity2name.c_str());
    }

    TEST_F(EntityTest, AddComponent) {
        entity->AddComponent<TransformComponent>();
        entity->AddComponent<ImageComponent>();
        ASSERT_THROW({
                         entity->AddComponent<TransformComponent>(glm::vec2i(1, 3));
                     }, std::exception);
    }

    TEST_F(EntityTest, DeleteComponent) {
        entity->AddComponent<TransformComponent>();
        entity->AddComponent<ImageComponent>();
        entity->DeleteComponent<TransformComponent>();
        entity->DeleteComponent<ImageComponent>();
        ASSERT_NO_THROW({
                            entity->AddComponent<TransformComponent>();
                        });
    }

    TEST_F(EntityTest, GetComponent) {
        entity->AddComponent<TransformComponent>();
        auto transformComponent = entity->GetComponent<TransformComponent>();
        ASSERT_EQ(typeid(transformComponent), typeid(std::shared_ptr<TransformComponent>));

        entity->AddComponent<ImageComponent>();
        auto imageComponent = entity->GetComponent<ImageComponent>();
        ASSERT_EQ(typeid(imageComponent), typeid(std::shared_ptr<ImageComponent>));
    }
}