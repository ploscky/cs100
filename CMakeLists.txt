CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(TerminalChess)

add_subdirectory(googletest)

project(chessGame)

ADD_EXECUTABLE(test
    src/board.cpp
    src/game.cpp
    src/piece.cpp
    src/square.cpp
    tests/test.cpp
)

ADD_EXECUTABLE(testingMain
    src/board.cpp
    src/game.cpp
    src/piece.cpp
    src/square.cpp
    tests/testMain.cpp
)


target_link_libraries(test gtest gtest_main)
target_link_libraries(testingMain gtest gtest_main)