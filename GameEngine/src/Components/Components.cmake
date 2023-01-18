add_library(Components
        ${CMAKE_CURRENT_LIST_DIR}/Component.h
        ${CMAKE_CURRENT_LIST_DIR}/Component.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TransformComponent.h
        ${CMAKE_CURRENT_LIST_DIR}/TransformComponent.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ShapeComponent.h
        ${CMAKE_CURRENT_LIST_DIR}/ShapeComponent.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ImageComponent.h
        ${CMAKE_CURRENT_LIST_DIR}/ImageComponent.cpp
        )

target_include_directories(Components PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Components)

include(${CMAKE_CURRENT_LIST_DIR}/Shapes/Shapes.cmake)