file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.cpp)
add_executable(AllTest
        ${TEST_SOURCES}
        )