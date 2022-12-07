cmake_minimum_required(VERSION 3.23)

project(Game)
set(CMAKE_CXX_STANDARD 20)

add_executable(Game
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/GameEngine)
target_link_libraries(${CMAKE_PROJECT_NAME} GameEngine)
