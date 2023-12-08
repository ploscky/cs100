CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(TerminalChess)

add_subdirectory(googletest)

ADD_EXECUTABLE(unitTests
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

    tests/printBoardTest.cpp
    tests/boardTest.cpp
    tests/kingTest.cpp
    tests/queenTest.cpp
    tests/bishopTest.cpp
    tests/knightTest.cpp
    tests/rookTest.cpp
    tests/pawnTest.cpp
)

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

ADD_EXECUTABLE(TerminalChess
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
    src/main.cpp
)

target_link_libraries(unitTests gtest gtest_main)
target_link_libraries(test gtest gtest_main)