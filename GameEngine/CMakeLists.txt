cmake_minimum_required(VERSION 3.23)
project(GameEngine)
set(CMAKE_CXX_STANDARD 20)

include(src/GameEngine.cmake)
include(src/Components/Components.cmake)

include(FetchContent)
FetchContent_Declare(
        glm
        GIT_REPOSITORY git@github.com:g-truc/glm.git
        GIT_TAG        0.9.9.8
)
FetchContent_Declare(
        sdl2
        GIT_REPOSITORY git@github.com:libsdl-org/SDL.git
        GIT_TAG        release-2.26.0
)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(sdl2 glm googletest)
target_link_libraries(GameEngine SDL2::SDL2 GTest::gmock GTest::gtest)
