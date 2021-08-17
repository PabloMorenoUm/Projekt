add_executable(
        Doctest_tests_run
        BallTest.cpp
        BatTest.cpp
        BobTest.cpp
        BoardTest.cpp
        DirectionTest.cpp
        ThingTest.cpp
        WordsTest.cpp
        )
target_link_libraries(Doctest_tests_run helpers shapes)