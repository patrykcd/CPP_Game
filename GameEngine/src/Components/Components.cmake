add_library(Components
        ${CMAKE_CURRENT_LIST_DIR}/Component.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Component.h
        ${CMAKE_CURRENT_LIST_DIR}/TransformComponent.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TransformComponent.h
        )

target_include_directories(Components PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Components)