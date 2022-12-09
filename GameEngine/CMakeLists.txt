cmake_minimum_required(VERSION 3.23)
project(GameEngine)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/test/GameEngineTest.cmake)

include(FetchContent)
FetchContent_Declare(
        sdl2
        GIT_REPOSITORY git@github.com:libsdl-org/SDL.git
        GIT_TAG        release-2.26.0
)
FetchContent_Declare(
        glm
        GIT_REPOSITORY git@github.com:g-truc/glm.git
        GIT_TAG        0.9.9.8
)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(sdl2 glm googletest)

target_link_libraries(GameEngine
        PUBLIC Components
        PUBLIC SDL2::SDL2
        )
target_link_libraries(Components
        PUBLIC glm::glm
        )

enable_testing()
set(GTestTargets GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

target_link_libraries(AllTest
        PUBLIC GameEngine
        PUBLIC Components
        PUBLIC glm::glm
        PUBLIC ${GTestTargets}
        )
