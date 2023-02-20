cmake_minimum_required(VERSION 3.23)
project(GameEngine)
set(CMAKE_CXX_STANDARD 20)


# ==================================================================================================
# Sources and headers
# ==================================================================================================

include(${CMAKE_CURRENT_SOURCE_DIR}/src/GameEngine.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/test/GameEngineTest.cmake)


# ==================================================================================================
# 3rd party
# ==================================================================================================

# Skip install() globally because of using FetchContent.
# There were problems with building dependencies that use find_package.
# FetchContent builds from source and doesn't work with already installed 3d-party projects (find_package).
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY ON)
set(CMAKE_SKIP_INSTALL_RULES ON)

include(FetchContent)
FetchContent_Declare(
        sdl2
        GIT_REPOSITORY git@github.com:libsdl-org/SDL.git
        GIT_TAG        release-2.26.0
)
#FetchContent_Declare(
#        SDL2_image
#        GIT_REPOSITORY git@github.com:libsdl-org/SDL_image.git
#        GIT_TAG        release-2.6.2
#)
FetchContent_Declare(
        glm
        GIT_REPOSITORY git@github.com:g-truc/glm.git
        GIT_TAG        0.9.9.8
)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        release-1.12.1
#)

FetchContent_MakeAvailable(sdl2  glm )
#SDL2_image googletest

# ==================================================================================================
# Dependencies
# ==================================================================================================

target_link_libraries(Math
        INTERFACE
            glm
        Components
        )

target_link_libraries(GameEngine
        PUBLIC
            Components
            Shapes
            SDL2::SDL2
#            SDL2_image::SDL2_image
        )

target_link_libraries(Shapes
        PUBLIC
        GameEngine
        Math
        Components
        )

target_link_libraries(Components
        PUBLIC
            GameEngine
            Shapes
            Math
        )


# ==================================================================================================
# Tests
# ==================================================================================================

#set(GTestTargets GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
#
#target_link_libraries(AllTest
#        PUBLIC
#            GameEngine
#            Components
#            Math
#            ${GTestTargets}
#        )