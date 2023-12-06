CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(TerminalChess)

#add_subdirectory(googletest)

ADD_EXECUTABLE(test
    src/board.cpp
    src/game.cpp
    src/piece.cpp
    src/square.cpp
    src/pawn.cpp
    src/rook.cpp
    src/knight.cpp
    src/bishop.cpp
    src/queen.cpp
    src/king.cpp
    tests/test.cpp
)

#target_link_libraries(test gtest gtest_main)
