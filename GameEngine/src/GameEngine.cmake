add_library(GameEngine
        ${CMAKE_CURRENT_LIST_DIR}/Entity.h
        ${CMAKE_CURRENT_LIST_DIR}/Entity.cpp
        ${CMAKE_CURRENT_LIST_DIR}/EntityGroup.h
        ${CMAKE_CURRENT_LIST_DIR}/EntityGroup.cpp
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.h
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Timer.h
        ${CMAKE_CURRENT_LIST_DIR}/Timer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Wrapper.h
        ${CMAKE_CURRENT_LIST_DIR}/Wrapper.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WrapperBase.h
        ${CMAKE_CURRENT_LIST_DIR}/WrapperBase.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WrapperItem.h
        ${CMAKE_CURRENT_LIST_DIR}/WrapperItem.cpp
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