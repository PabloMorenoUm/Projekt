add_executable(
        Doctest_tests_run
        BallTest.cpp
        BatTest.cpp
        DirectionTest.cpp
        WordsTest.cpp
        ThingTest.cpp
        BobTest.cpp
        )
target_link_libraries(Doctest_tests_run helpers shapes)