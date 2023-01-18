cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Game)
set(CMAKE_CXX_STANDARD 20)

add_executable(Game
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/GameEngine)
target_link_libraries(${CMAKE_PROJECT_NAME} GameEngine)


file(GLOB ALL_FILES Assets/*)
file(COPY ${ALL_FILES} DESTINATION ${CMAKE_BINARY_DIR}/Assets)
message(${ALL_FILES})