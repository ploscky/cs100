#include "../header/game.h"
#include <fstream>

Game::Game() {
    game = new Board();  // Initialize the board
    current_player = "White";  // Set the starting player
}


Game::~Game() {
    delete game;  // Clean up the allocated Board
}


void Game::play() {
    bool game_over = false;
    bool moveForward = false;
    while(!game_over) {
        moveForward = false;
        game->print();  // Print the current state of the board
        while(!moveForward){
            // Get the current player's move
            string move;
            cout << current_player << " player"<< ", enter your move: ";
            cin >> move;
            
            move = " " + move + " ";
            cout << move;
            // Process the move
            if (move == "exit" || move == "Exit" ) {
                cout << "Exiting the game." << endl;
                break;  // Exit the game loop
            } else if (move == "help" || move == "Help" ) {
                printInstructions();  // Show game instructions
                continue;  // Skip the rest of the loop to prompt for a move again
            } else {
                // Check if the move is legal
                if (isLegalMove(current_player == "White", move)) {
                    // If legal, make the move and log it
                    string moveTo = string(1, move[2]) + move[3];
                    //game->movePiece(getOriginal(move[1],move[2],move[3]), moveTo);  //doesnt work
                    gameLog.push_back(move);
                    moveForward = true;
                } else {
                    cout << "Illegal move. Try again." << endl;
                }
            }
        }

        // Check the game status (checkmate, stalemate, etc.)
        if (isCheckmate()) {
            cout << "Checkmate! Player " << current_player << " wins!" << endl;
            game_over = true;
        } else if (isStalemate()) {
            cout << "Stalemate! The game is a draw." << endl;
            game_over = true;
        } else if (inCheck()) {
            cout << "Check! Be careful, Player " << current_player << "." << endl;
        }

        // Switch turns between players
        current_player = (current_player == "White") ? "Black" : "White";
    }
}

string Game::getOriginal(char piece, char file, char rank){
   string fullPieceName;
   switch(piece) {
        case 'n': 
            fullPieceName = "knight";
            break;
        case 'b':
            fullPieceName = "bishop";
            break;
        case 'r':
            fullPieceName = "rook";
            break;
        case 'q':
            fullPieceName = "queen";
            break;
        case 'k':
            fullPieceName = "king";
            break;
        default:
            fullPieceName = "pawn";
    }

     

    return "";
}

void Game::printGameLog() {
    for (const string& move : gameLog) {
        cout << move << endl;
    }
}


void Game::saveGameLog(const string& fileName) {
    ofstream file(fileName.c_str());
    for (const string& move : gameLog) {
        file << move << endl;
    }
    file.close();
    cout << "Game log saved to " << fileName << endl;
}


void Game::mainMenu() {
    int choice = 0;
        while (true) { 
        cout <<
        "---------------------------------\n"
        "           CHESS GAME\n"
        "---------------------------------\n"
        "1. Start New Game\n"
        "2. How to Play\n"
        "3. Exit\n"
        "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                play();
                break;
            case 2:
                printInstructions();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                cin.clear();
                cin.ignore();
        }
    }
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

bool Game::isLegalMove(bool whiteTurn, string input) 
{

    if (whiteTurn)
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

bool Game::inCheck() {
   return false;
}

bool Game::isCheckmate() {
    return false;
}

bool Game::isStalemate() {
    return false;
}
