project(pages)

set(SOURCE_FILES
        BasicPage.cpp
        Engine.cpp
        GamePage.cpp
        Info.cpp
        MainMenu.cpp
        Pong.cpp
        Reaction.cpp
        ConnectFour.cpp
        )

add_library(pages STATIC ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(pages sfml-system sfml-window sfml-graphics sfml-audio sfml-network)