#include "../header/game.h"

Game::Game()
    {game = new Board();}

Game::~Game()
    {delete game;}

void Game::play()
{
    delete game;
    game = new Board();
    gameLog.clear();

    bool gameOver = false;
    bool moveMade = false;
    bool isWhiteTurn = true;
    string move;

    while (true)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        moveMade = false; // is used to end while loop after valid move made
        game->print();    // Print the current state of the board

        // Check the game status (checkmate, stalemate, etc.)
        if (isCheckmate(isWhiteTurn))
        {
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << "------------------------------------------------------------ \n"
                    "                     GAME OVER - WINNER"; 
                    if (isWhiteTurn) {cout << " BLACK\n";}
                    else             {cout << " WHITE\n";}
            cout << "------------------------------------------------------------ \n";

            cout << "1. Return to menu\n"
                    "2. Show game log\n\n"
                    "Enter your choice: ";
                    while (true)
                    {
                        int choice = 0;
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                            return;
                        case 2:
                            printGameLog();
                            return;
                        default:
                            cout << "Invalid choice, please try again:\n";
                            cin.clear();
                            cin.ignore();
                        }
                    }
                    return; // moves to next
        }
        else if (isStalemate(isWhiteTurn))
        {
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << "------------------------------------------------------------ \n"
                            "               GAME OVER - STALEMATE "
                            "\n"
                            "------------------------------------------------------------ \n"
                            "1. Return to menu\n"
                            "2. Show game log\n\n"
                            "Enter your choice: ";
            while (true)
            {
                int choice = 0;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    return;
                case 2:
                    printGameLog();
                    return;
                default:
                    cout << "Invalid choice, please try again: \n";
                    cin.clear();
                    cin.ignore();
                }
            }
            return; // this is when the game is over
        }
        else if (inCheck(isWhiteTurn))
        {
            cout << "Check! Be careful!" << endl;
        }

        while (!moveMade)
        {
            // Get the current player's move
            if (isWhiteTurn) {cout << "White ";}
            else             {cout << "Black ";}
            cout << "player, enter your move: ";

            cin >> move;
            move = " " + move + " ";

            // Process the move
            if (move == " exit " || move == " Exit ")
            {
                cout << "WARNING: Exiting the game will result in draw" << endl;
                if (isWhiteTurn) {cout << "Black ";}
                else             {cout << "White ";}
                cout << "player, enter \"exit\" accept draw or any other key to deny: ";

                cin >> move;
                move = " " + move + " ";
                if (move == " exit " || move == " Exit ")
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    cout << "------------------------------------------------------------ \n"
                            "                     GAME OVER - DRAW "
                            "\n"
                            "------------------------------------------------------------ \n"
                            "1. Return to menu \n"
                            "2. Show game log \n\n"
                            "Enter your choice: ";
                    while (true)
                    {
                        int choice = 0;
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                            return;
                        case 2:
                            printGameLog();
                            saveGameLog("GameLog.txt");
                            return;
                        default:
                            cout << "Invalid choice, please try again.\n";
                            cin.clear();
                            cin.ignore();
                        }
                    }
                    return; // this is when the game is over
                }
                else
                    {continue;} // Skip the rest of the loop to prompt for a move again
            }
            else if (move == " help " || move == " Help ")
            {
                printInstructions(); // Show game instructions
                continue;            // Skip the rest of the loop to prompt for a move again
            }
            else
            {
                // Check if the move is legal
                if (move.find('*') != string::npos)
                    {cout << "Illegal move. Try again." << endl;}
                else if (isLegalMove(isWhiteTurn, move))
                {
                    if (move == " O-O ")
                    {
                        if (isWhiteTurn == true)
                        {
                            game->movePiece("e1", "g1");
                            game->movePiece("h1", "f1");
                        }
                        else
                        {
                            game->movePiece("e8", "g8");
                            game->movePiece("h8", "f8");
                        }

                        gameLog.push_back(move);
                    }
                    else if (move == " O-O-O ")
                    {
                        if (isWhiteTurn == true)
                        {
                            game->movePiece("e1", "c1");
                            game->movePiece("a1", "d1");
                        }
                        else
                        {
                            game->movePiece("e8", "e8");
                            game->movePiece("a8", "d8");
                        }

                        gameLog.push_back(move);
                    }
                    else
                    {
                        game->movePiece(movingPieceCoordinates(isWhiteTurn, move), move.substr(move.size() - 3, 2));
                        gameLog.push_back(move);
                    }

                    if (inCheck(isWhiteTurn)) // if revealing check, undo and prompt again
                    {
                        undoLastMove();
                        cout << "Illegal move. Try again." << endl;
                    }
                    else
                        {moveMade = true;}
                }
                else
                    {cout << "Illegal move. Try again." << endl;}
            }
        }
        
        // check for pawn promotion
        game->pawnPromotion();

        // Switch turns between players
        isWhiteTurn = !isWhiteTurn;
    }
}

void Game::printGameLog()
{
    cout << "--------------------------------- \n"
            "             GAME LOG \n"
            "--------------------------------- \n"
            "Moves are listed in chess notation.\n"
            "Each line represents a full turn, with White's move listed first.\n";
    for (unsigned i = 1; i < gameLog.size(); i++)
    {
        cout << i << "." << gameLog[i - 1] << gameLog[i] << endl;
    }
    cout << "Commands: \n"
            "1. Return to Main Menu\n"
            "2. Quit\n"
            "Enter command: ";

    
    while (true)
    {
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
        case 1:
            return;
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            cin.clear();
            cin.ignore();
        }
    }
}


void Game::saveGameLog(const string& fileName) {
    int curr = 1;
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Unable to open file: " << fileName << endl;  
        return;  
    }
    file << "Game #" << curr << endl;
    curr ++;
    for (unsigned i = 1; i < gameLog.size(); i++) {
        file << i << "." << gameLog[i - 1] << " " << gameLog[i] << endl;
    }
}

void Game::mainMenu() {
    cout << "\n\n\n\n\n\n\n\n\n\n"
    "---------------------------------\n"
    "              CHESS\n"
    "---------------------------------\n"
    "1. Start New Game\n"
    "2. How to Play\n"
    "3. Exit\n\n"
    "Enter your choice: ";
}

void Game::printInstructions() {
    cout <<  
    "---------------------------------\n"
    "           HOW TO PLAY\n"
    "---------------------------------\n\n"
    "Chess is played on an 8x8 grid, with each player starting\n"
    "with 16 pieces that move in distinct ways. To win, you must\n"
    "checkmate your opponent's king.\n"
    "Rules:\n"
    "- Use chess notation for moves, e.g., \"Ne6\".\n"
    "- A move is denoted by the piece's letter and its destination\n"
    "  square, e.g., \"Nf3\" moves a knight to the f3 square.\n"
    "- On the board each white piece is identified by an uppercase letter:\n"
    "  R for Rook, N for Knight, B for Bishop, Q for Queen,\n"
    "  K for King, and P for Pawn.\n"
    "- On the board each black piece is identified by a lowercase letter:\n"
    "  r for Rook, n for Knight, b for Bishop, q for Queen,\n"
    "  k for King, and p for Pawn.\n"
    "- The columns (files) are labeled a-h from left to right,\n"
    "  and the rows (ranks) are labeled 1-8 from bottom to top.\n"
    "- To capture, simply move your piece to the square occupied\n"
    "  by an opponent's piece.\n"
    "- Pawns are not denoted by letter, only by the destination\n"
    "  square, e.g., \"e4\".\n"
    "- Castling is indicated by \"O-O\" for kingside or \"O-O-O\" for\n"
    "  queenside.\n\n"
    "Special Moves:\n"
    "- \"en passant\" is a special pawn capture.\n"
    "- \"promotion\" occurs when a pawn reaches the farthest rank.\n\n"
    "Commands:\n"
    "- \"e4\": To move a pawn to e4.\n"
    "- \"exit\": Exit the current game and return to the main menu.\n"
    "- \"help\": Show a list of commands and rules.\n\n"
    "Type your commands or moves when prompted during gameplay.\n"
    "Press any key to return to the main menu\n";
    cin.ignore(); cin.get();
}

void Game::undoLastMove()
{
    if (gameLog.empty())
        {return;}

    bool isWhiteTurn = true;
    string currMove;

    delete game;
    game = new Board();

    for (int i = 0; i < gameLog.size() - 1; ++i)
    {
        currMove = gameLog.at(i);
        game->movePiece(movingPieceCoordinates(isWhiteTurn, currMove), currMove.substr(currMove.size() - 3, 2));
        isWhiteTurn = !isWhiteTurn;
    }

    gameLog.pop_back();
}

string Game::movingPieceCoordinates(bool movingWhitePiece, string input)
{
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            if (movingWhitePiece == true &&
                !game->getSquare(i, j)->empty() &&
                game->getSquare(i, j)->getPiece()->getColor() == 'w' &&
                game->getLegalMoves(i, j).find(input) != string::npos)
                {return game->getSquare(i, j)->getCoordinates();}
            
            if (movingWhitePiece == false &&
                !game->getSquare(i, j)->empty() &&
                game->getSquare(i, j)->getPiece()->getColor() == 'b' &&
                game->getLegalMoves(i, j).find(input) != string::npos)
                {return game->getSquare(i, j)->getCoordinates();}
        }
    }

    return "FUCK";
}

bool Game::isCheckmate(bool isWhiteTurn) 
{
    if (!inCheck(isWhiteTurn))
        {return false;}
    if (isStalemate(isWhiteTurn))
        {return true;}

    string currPieceLegalMoves;
    string currMove;

    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            if (isWhiteTurn == true &&
                !game->getSquare(i, j)->empty() &&
                game->getSquare(i, j)->getPiece()->getColor() == 'w')
            {
                currPieceLegalMoves = game->getLegalMoves(i, j);

                while (currPieceLegalMoves.size() > 1)
                {
                    currPieceLegalMoves.erase(currPieceLegalMoves.begin());
                    currMove = currPieceLegalMoves.substr(0, currPieceLegalMoves.find(' '));
                    currPieceLegalMoves.erase(0, currPieceLegalMoves.find(' '));

                    if (currMove.find('*') != string::npos)
                        {continue;}

                    if (currMove == "O-O-O" || "O-O")
                        {continue;}

                    game->movePiece(movingPieceCoordinates(isWhiteTurn, currMove), currMove.substr(currMove.size() - 2, 2));
                    gameLog.push_back(" " + currMove + " ");

                    if (!inCheck(isWhiteTurn))
                    {
                        undoLastMove();
                        return false;
                    }                    

                    undoLastMove();
                }
            }

            if (isWhiteTurn == false &&
                !game->getSquare(i, j)->empty() &&
                game->getSquare(i, j)->getPiece()->getColor() == 'b')
            {
                currPieceLegalMoves = game->getLegalMoves(i, j);

                while (currPieceLegalMoves.size() > 1)
                {
                    currPieceLegalMoves.erase(currPieceLegalMoves.begin());
                    currMove = currPieceLegalMoves.substr(0, currPieceLegalMoves.find(' '));
                    currPieceLegalMoves.erase(0, currPieceLegalMoves.find(' '));

                    if (currMove.find('*') != string::npos)
                        {continue;}

                    game->movePiece(movingPieceCoordinates(isWhiteTurn, currMove), currMove.substr(currMove.size() - 2, 2));
                    gameLog.push_back(" " + currMove + " ");

                    if (!inCheck(isWhiteTurn))
                    {
                        undoLastMove();
                        return false;
                    }
                    
                    undoLastMove();
                }
            }
        }
    }
    
    return true;
}

bool Game::isStalemate(bool isWhiteTurn)
{
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            if (isWhiteTurn == true && 
            !game->getSquare(i, j)->empty() &&
            game->getSquare(i, j)->getPiece()->getColor() == 'w' &&
            !(game->getLegalMoves(i, j).size() < 2))
                {return false;}

            if (isWhiteTurn == false && 
            !game->getSquare(i, j)->empty() &&
            game->getSquare(i, j)->getPiece()->getColor() == 'b' &&
            !(game->getLegalMoves(i, j).size() < 2))
                {return false;}
        }
    }

    return true;
}

bool Game::isLegalMove(bool isWhiteTurn, string input) 
{
    if (isWhiteTurn == true)
    {
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                if (game->getSquare(i, j)->getPiece() != nullptr &&
                    game->getSquare(i, j)->getPiece()->getColor() == 'w' && 
                    game->getLegalMoves(i, j).find(input) != string::npos)
                    {return true;}
            }
        }
    }
    else
    {
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                if (game->getSquare(i, j)->getPiece() != nullptr &&
                    game->getSquare(i, j)->getPiece()->getColor() == 'b' && 
                    game->getLegalMoves(i, j).find(input) != string::npos)
                    {return true;}
            }
        }
    }

    return false;
}

bool Game::inCheck(bool isWhiteTurn) 
{
    string kingCoordinates;

    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            if (isWhiteTurn == true &&
                !game->getSquare(i, j)->empty() &&               // finding white king square if white turn
                game->getSquare(i, j)->getPiece()->getNotation() == 'K' &&
                game->getSquare(i, j)->getPiece()->getColor() == 'w')
                {kingCoordinates = game->getSquare(i, j)->getCoordinates();}

            if (isWhiteTurn == false &&
                !game->getSquare(i, j)->empty() &&               // finding black king square if black turn
                game->getSquare(i, j)->getPiece()->getNotation() == 'K' &&
                game->getSquare(i, j)->getPiece()->getColor() == 'b')
                {kingCoordinates = game->getSquare(i, j)->getCoordinates();}
        }
    }

    if (isWhiteTurn == true)
    {
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                if (!game->getSquare(i, j)->empty() &&
                    game->getSquare(i, j)->getPiece()->getColor() == 'b' && 
                    game->getLegalMoves(i, j).find("x" + kingCoordinates) != string::npos)
                    {return true;}
            }
        }
    }
    else
    {
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                if (!game->getSquare(i, j)->empty() &&
                    game->getSquare(i, j)->getPiece()->getColor() == 'w' && 
                    game->getLegalMoves(i, j).find("x" + kingCoordinates) != string::npos)
                    {return true;}
            }
        }
    }

    return false;
}