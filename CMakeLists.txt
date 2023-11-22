CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

add_subdirectory(googletest)

ADD_EXECUTABLE(inputValidation
    src/inputValidation.cpp
    tests/inputTests.cpp
)

target_link_libraries(inputValidation gtest gtest_main)