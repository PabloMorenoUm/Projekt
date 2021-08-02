project(helpers)

set(SOURCE_FILES
        Basic.cpp
        Direction.cpp
        WindowSize.cpp
        Words.cpp
        )

add_library(helpers STATIC ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(helpers sfml-graphics)