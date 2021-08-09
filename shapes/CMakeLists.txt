project(shapes)

set(SOURCE_FILES
        BallBat.cpp
        Ball.cpp
        Bat.cpp
        Bob.cpp
        Thing.cpp
        Coin.cpp
        Board.cpp
        )

add_library(shapes STATIC ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(shapes sfml-graphics)