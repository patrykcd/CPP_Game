#include <gtest/gtest.h>
#include "glm/glm.hpp"
//#include "Entity.h"
//#include "Components/Shapes/RectangleShape.h"
#include "GameEngineMath.h"

namespace Core::Components::Shapes::UnitTests {

    class RectangleShapeTest : public ::testing::Test {
    protected:
//        Entity entity = Entity("Entity Name 1");
    };

    TEST_F(RectangleShapeTest, __){
//        RectangleShape rectangleShape;
        EXPECT_TRUE(glm::vec2i(0,0) == glm::vec2i(0,0));
    }
}