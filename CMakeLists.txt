CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

add_subdirectory(googletest)

ADD_EXECUTABLE(inputValidation
    src/inputValidation.cpp
    tests/inputTests.cpp
)

target_link_libraries(inputValidation gtest gtest_main)