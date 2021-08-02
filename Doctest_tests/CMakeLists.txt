add_executable(Doctest_tests_run BallTest.cpp BatTest.cpp DirectionTest.cpp WordsTest.cpp)
target_link_libraries(Doctest_tests_run helpers shapes)