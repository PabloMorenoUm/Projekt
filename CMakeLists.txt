cmake_minimum_required(VERSION 3.19)
project(Projekt_run)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt_run main.cpp)

include_directories(helpers)
add_subdirectory(helpers)

include_directories(shapes)
add_subdirectory(shapes)

include_directories(pages)
add_subdirectory(pages)
target_link_libraries(Projekt_run helpers shapes pages)

add_subdirectory(Doctest_tests)