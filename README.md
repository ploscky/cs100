# Terminal-based Chess
 
 Authors: [Richard Zhou](https://github.com/rzhou052), [George Babik](https://github.com/gababik), [Nada Salib](https://github.com/nadasalib), [Selina Wu](https://github.com/ploscky)

## Project Description

### Motivation
The development of a terminal-based chess project is compelling because of the inherent complexities of the game that make it challenging to program. This project also gives us the opportunity to explore the principles of user interface design. It requires a thorough understanding of data structures and algorithms to implement.

### Languages, Tools, and Technologies
The project will primarily use C++ for programming the chess logic and interface. It will use the language’s standard input/output functionalities for handling moves and printing the game in the terminal. Beyond that, GitHub and Visual Studio Code will be used to create this program.

### Inputs and Outputs
The inputs will be moves entered in chess notation (e.g., " Qf7" to move the queen to f7). The output will display the current board state after each move within the terminal. The first output of the program is the starting screen that gives users the option to read instructions of the game, start a game, or exit. At the end of each game, a log of all the moves will be displayed in chess notation as well.
 
### Features
* Chess Logic: Implementing the traditional rules of chess, meaning legal moves for each piece, check, checkmate, and stalemate conditions.
* Move Validation: Verifying the legality of moves and providing messages for illegal moves.
* Game State Management: Tracking the current board position, the player turns, available moves, and displaying the updated chessboard after each move.
* Terminal User Interface: Displaying the chessboard and game interface directly in the terminal.
* Two-Player Mode: Allows for a local multiplayer.


## User Interface Specification

### Navigation Diagram
The navigation diagram shows the process of a user playing through a chess game and the different options they can choose throughout. First, they are met with a menu that gives them the choice to start the game or view a page of instructions and rules of the game. Should they choose to start the game, a chessboard with the pieces in the starting positions is printed. Then the user is prompted to input their desired move, which updates the chessboard. At certain points, a user also has the opportunity to make a special move like castling, pawn promotion, etc. Users are allowed to exit the game at any time, which brings them to the end-of-game page. Once they view the log of all the moves made up to that point in chess notation, they can play again, rerouting them back to the main menu, or end the program.

<img src="Navigation Diagram.png?raw=true" width="1000">

### Screen Layouts
Screen-Start:
```
---------------------------------        
              CHESS
---------------------------------
1. Start New Game
2. How to Play
3. Exit

Enter your choice: [input]
```
Components:
Title: Simply the name of the game "CHESS".

Options 1-3: Clear and concise menu options for the user.

Input Prompt: Where the user types their selection.

Purpose:

Start New Game: Begins a new chess game.

How to Play: Displays rules and controls for the game.

Exit: Closes the application.



Screen-HowToPlay:
```
---------------------------------   
           HOW TO PLAY    
---------------------------------

Chess is played on an 8x8 grid, with each player starting
with 16 pieces that move in distinct ways. To win, you must
checkmate your opponent's king.
Rules:
- Use chess notation for moves, e.g., "Ne6".
- A move is denoted by the piece's letter and its destination
  square, e.g., "Nf3" moves a knight to the f3 square.
- On the board each white piece is identified by an uppercase letter:
  R for Rook, N for Knight, B for Bishop, Q for Queen,
  K for King, and P for Pawn.
- On the board each black piece is identified by a lowercase letter:
  r for Rook, n for Knight, b for Bishop, q for Queen,
  k for King, and p for Pawn.
- The columns (files) are labeled a-h from left to right,
  and the rows (ranks) are labeled 1-8 from bottom to top.
- To capture, simply move your piece to the square occupied
  by an opponent's piece.
- Pawns are not denoted by letter, only by the destination
  square, e.g., "e4".
- Castling is indicated by "O-O" for kingside or "O-O-O" for
  queenside.

Special Moves:
- "en passant" is a special pawn capture.
- "promotion" occurs when a pawn reaches the farthest rank.

Commands:
- "e4": To move a pawn to e4.
- "exit": Exit the current game and return to the main menu.
- "help": Show a list of commands and rules.

Type your commands or moves when prompted during gameplay.
Press any key to return to the main menu
```
Components & Purpose:
Instructions: Basic rules and gameplay guidance.
Commands: A list of available commands for the player.
Return Prompt: Lets the player know they can return to the main menu.


Screen-Play:
```
---------------------------------
              BOARD
---------------------------------
   
    A   B   C   D   E   F   G   H
  ---------------------------------
8 | r | n | b | q | k | b | n | r |
  ---------------------------------
7 | p | p | p | p | p | p | p | p |
  ---------------------------------
6 | . | . | . | . | . | . | . | . |
  ---------------------------------
5 | . | . | . | . | . | . | . | . |
  ---------------------------------
4 | . | . | . | . | . | . | . | . |
  ---------------------------------
3 | . | . | . | . | . | . | . | . |
  ---------------------------------
2 | P | P | P | P | P | P | P | P |
  ---------------------------------
1 | R | N | B | K | Q | B | N | R |
  ---------------------------------
```
Components:

Chessboard: Represents the game state. Uppercase letters for white pieces, lowercase for black pieces. (R/r for Rooks, N/n for Knights, etc.)

Command Input: Where players input their moves, using a format like "e2 e4".

Options: Additional commands players can use.

Purpose:

Chessboard Display: To visualize the current state of the game.

Command Input: For players to make moves or use other commands.

exit: Return to the main menu.

help: View list of possible commands and game controls.

Screen-GameOver:
```
-----------------------------------------------------------
        GAME OVER - [WINNER WHITE/BLACK or STALEMATE]
------------------------------------------------------------
1. Continue
2. Quit

Enter your choice: [input]
```
Components & Purpose:

Game Over Message: Displays the game's outcome.

Continue: Goes to the game log.

Quit: Ends Program.

Screen-GameLog:
```
---------------------------------
            GAME LOG
---------------------------------
Moves are listed in chess notation. Each line represents
a full turn, with White's move listed first.
1. e4 e5
2. Nf3 Nc6
3. Bb5 a6
4. Ba4 Nf6
6. Re1 b5
7. Bb3 d6
...
Commands:
1. Return to Main Menu
2. Quit

Enter your choice: [input]
```
Components & Purpose:

Return to Main Menu: Go back to main menu to play again.

Quit: Ends program. 



## Class Diagram
<img src="UML Class Diagram.png?raw=true" width="1000">

Our game will be comprised of 4 main classes, the game itself, the board, the squares on the board, and the game pieces. The Game class has the primary controls over the game, such as switching turns and saving the game log afterwards. It will also hold the logic for determining whether inputs are valid, and when they are, whether they are legal moves or not. The Board class controls an 8x8 matrix of Squares, simulating a chessboard and holds the primary controls for moving the pieces themselves, and contains the graphics that the game will print out for the user. The Square class helps calculate all possible moves of the piece within the square, assisting in checking the legality of moves. Finally, the Piece class contains data that determines what each unique piece can do, and which side it belongs to, making sure it moves in the correct directions and captures the correct pieces.

UML Diagram Updates:
* We added two int type parameters to the getSquare function in Board class. These parameters are for the file and rank of the Square that the function is getting. The function returns a Square, which is the class associated with Board. It leads to better code because it now clarifies the specific Square parameters that are needed to return something for the function. Because a chessboard has ranks and files for coordinates, this also makes the process of finding a piece on the board more organized and direct.
* We split the chess pieces into 6 separate classes that derive from the abstract Piece class. As such, they all use the function getValidMoves() to find the legal moves that each piece can do. This adheres to the Interface Segregation Principle, as well as the Single Responsibility Principle. For example, the client is not forced to interact with a rook piece if they want to move the bishop. Furthermore, each piece has its own responsibility of moving and the Board class only has to deal with the actual matrix of Squares it contains. This change also follows the Open-Closed Principle, since now the pieces cannot be modified directly on Board, but are instead extensions of it.
* The UML diagram was also updated to express multiplicities. These can help further define the relationship between classes. This addition guides the design of the classes so that they follow the Dependency Inversion Principle, which states that high-level modules should not depend on low-level modules. Visualizing the associations between classes makes it easier to identify changes that need to be made to the class diagram in order to follow solid principles.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 In order to install our program, go ahead and fork the repository, or download the zip file, extract it, and open the repository on VS Code. After that, go ahead and run the command "cmake .", then "make", then "./TerminalChess" to play our game. Have fun!
 ## Testing
 Our project was tested using the GoogleTest framework. With GoogleTest, we ran unit tests on our functions like constructors, print(), movePiece(), the legal moves for each piece, etc. The unit tests are organized into separate files and testing suites for easier testing and cleaner code. We also ran Valgrind to check for any memory leaks and errors, making sure that each block of memory is being allocated and freed correctly in our program.
 


