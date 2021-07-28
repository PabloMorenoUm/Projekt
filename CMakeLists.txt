cmake_minimum_required(VERSION 3.19)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt main.cpp shapes/Bat.cpp shapes/Bat.hpp shapes/Ball.cpp shapes/Ball.hpp shapes/Bob.cpp shapes/Bob.hpp pages/Engine.cpp pages/Engine.hpp shapes/Thing.cpp shapes/Thing.hpp helpers/WindowSize.cpp helpers/WindowSize.hpp helpers/Direction.cpp helpers/Direction.hpp pages/MainMenu.cpp pages/MainMenu.hpp pages/BasicPage.cpp pages/BasicPage.hpp helpers/Basic.cpp helpers/Basic.hpp helpers/Words.cpp helpers/Words.hpp pages/Info.cpp pages/Info.hpp pages/Pong.cpp pages/Pong.hpp shapes/BallBat.cpp shapes/BallBat.hpp pages/Reaction.cpp pages/Reaction.hpp pages/GamePage.cpp pages/GamePage.hpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Projekt sfml-system sfml-window sfml-graphics sfml-audio sfml-network)