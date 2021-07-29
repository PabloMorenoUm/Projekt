cmake_minimum_required(VERSION 3.19)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Projekt
        main.cpp
        helpers/Basic.cpp
        helpers/Direction.cpp
        helpers/WindowSize.cpp
        helpers/Words.cpp
        pages/BasicPage.cpp
        pages/Engine.cpp
        pages/GamePage.cpp
        pages/Info.cpp
        pages/MainMenu.cpp
        pages/Pong.cpp
        pages/Reaction.cpp
        shapes/Ball.cpp
        shapes/BallBat.cpp
        shapes/Bat.cpp
        shapes/Bob.cpp
        shapes/Thing.cpp
)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Projekt sfml-system sfml-window sfml-graphics sfml-audio sfml-network)