add_library(Components
        src/Components/Component.cpp
        src/Components/Component.h
        src/Components/TransformComponent.cpp
        src/Components/TransformComponent.h
        )

target_include_directories(Components PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Components)

target_link_libraries(Components glm::glm)
target_link_libraries(GameEngine Components)