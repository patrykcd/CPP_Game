#include <gtest/gtest.h>

#include "Entity.h"
#include "EntityGroup.h"

namespace Core::UnitTests {
    class EntityGroupTest : public ::testing::Test {
    protected:
        EntityGroup entityGroup;
        size_t entitiesCount;

        EntityGroupTest() {}

        ~EntityGroupTest() override {}

        void SetUp() override {
            size_t i;
            for (i = 0; i < 5; i++) {
                entityGroup.AddEntity(Entity("entity_" + std::to_string(i)));
            }
            entitiesCount = i;
        }

        void TearDown() override {}
    };

    TEST_F(EntityGroupTest, AddEntity) {
        for (int i = 0; i < 2; i++) {
            std::string entityName = "entity_" + std::to_string(entitiesCount);
            entityGroup.AddEntity(Entity(entityName));
            ++entitiesCount;
            EXPECT_EQ(entityGroup.Count(), entitiesCount);
        }
        --entitiesCount;

        for (int i = 1; i < 3; i++) {
            std::string entityName = "entity_" + std::to_string(entitiesCount) + " (" + std::to_string(i) + ")";
            entityGroup.AddEntity(Entity(entityName));
            ASSERT_NO_THROW({
                                entityGroup.GetEntityByName(entityName);
                            });
        }
    }

    TEST_F(EntityGroupTest, DeleteEntity) {
        entityGroup.DeleteEntity("entity_" + std::to_string(entitiesCount));
        EXPECT_EQ(entityGroup.Count(), entitiesCount);
    }

    TEST_F(EntityGroupTest, GetEntityByName) {
        std::string entityName = "entity_" + std::to_string(entitiesCount - 1);
        Entity entity = entityGroup.GetEntityByName(entityName);
        EXPECT_EQ(entity.GetName(), entityName);
    }

    TEST_F(EntityGroupTest, Count) {
        EXPECT_EQ(entityGroup.Count(), entitiesCount);
    }

    TEST_F(EntityGroupTest, GetEntityByIndex) {
        Entity entity = entityGroup.GetEntityByIndex(0);
        EXPECT_EQ(entity.GetName(), "entity_0");
    }
}