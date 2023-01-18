#include <gtest/gtest.h>

namespace Core::UnitTests {
    class GameEngineTest : public ::testing::Test {
    protected:
        GameEngineTest() {}

        ~GameEngineTest() override {}

        void SetUp() override {}

        void TearDown() override {}
    };

    TEST_F(GameEngineTest, _) {
        GTEST_SKIP();
    }
}