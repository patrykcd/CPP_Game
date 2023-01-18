add_library(GameEngine
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.h
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Scene.h
        ${CMAKE_CURRENT_LIST_DIR}/Scene.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Entity.h
        ${CMAKE_CURRENT_LIST_DIR}/Entity.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Timer.h
        ${CMAKE_CURRENT_LIST_DIR}/Timer.cpp
        )

add_library(Math INTERFACE)
target_sources(Math
        INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/GameEngineMath.h
        )

target_include_directories(Math
        INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}
        )

target_include_directories(GameEngine
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
        )

include(${CMAKE_CURRENT_LIST_DIR}/Components/Components.cmake)