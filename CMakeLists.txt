cmake_minimum_required(VERSION 3.19)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Projekt
        main.cpp
        helpers/Basic.cpp
        helpers/Basic.hpp
        helpers/Direction.cpp
        helpers/Direction.hpp
        helpers/WindowSize.cpp
        helpers/WindowSize.hpp
        helpers/Words.cpp
        helpers/Words.hpp
        pages/BasicPage.cpp
        pages/BasicPage.hpp
        pages/Engine.cpp
        pages/Engine.hpp
        pages/GamePage.cpp
        pages/GamePage.hpp
        pages/Info.cpp
        pages/Info.hpp
        pages/MainMenu.cpp
        pages/MainMenu.hpp
        pages/Pong.cpp
        pages/Pong.hpp
        pages/Reaction.cpp
        pages/Reaction.hpp
        shapes/Ball.cpp
        shapes/Ball.hpp
        shapes/BallBat.cpp
        shapes/BallBat.hpp
        shapes/Bat.cpp
        shapes/Bat.hpp
        shapes/Bob.cpp
        shapes/Bob.hpp
        shapes/Thing.cpp
        shapes/Thing.hpp
)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Projekt sfml-system sfml-window sfml-graphics sfml-audio sfml-network)