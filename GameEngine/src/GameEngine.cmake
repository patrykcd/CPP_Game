add_library(GameEngine
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.cpp
        ${CMAKE_CURRENT_LIST_DIR}/GameEngine.h
        ${CMAKE_CURRENT_LIST_DIR}/Entity.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Entity.h
        )
target_include_directories(GameEngine PUBLIC ${CMAKE_CURRENT_LIST_DIR})



