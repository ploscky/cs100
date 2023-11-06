# Terminal-based Chess
 
 Authors: [Richard Zhou](https://github.com/rzhou052), [George Babik](https://github.com/gababik), [Nada Salib](https://github.com/nadasalib), [Selina Wu](https://github.com/ploscky)

## Project Description

* Why is it important or interesting to you?



* What are the features that the project provides?


 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification

### Navigation Diagram
The navigation diagram shows the process of a user playing through a chess game and the different options they can choose throughout. First, they are met with a page of instructions and rules of the game. This is followed by a printed chessboard with the pieces in the starting positions. Then the user is prompted to input their desired move, which updates the chessboard. At certain points, a user also has the opportunity to make a special move like castling, pawn promotion, etc. Users are allowed to exit the game at any time, which brings them to the end-of-game page that displays the chess notation of all the moves made up to that point. This page also appears after a game that has reached checkmate or stalemate. After the log of chess notation is printed, the program resets.

<img src="Navigation Diagram.png?raw=true" width="1000">

### Screen Layouts
Screen-Start:
```
---------------------------------        
           CHESS GAME
---------------------------------
1. Start New Game
2. How to Play
3. Exit
Enter your choice: [input]
```
Components:
Title: Simply the name of the game "CHESS GAME".

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
Notation:
- Use chess notation for moves, e.g., "Ne6".
- Each piece is identified by an uppercase letter for black:
  R for Rook, N for Knight, B for Bishop, Q for Queen,
  K for King, and P for Pawn.
- Each piece is identified by an uppercase letter for white:
  r for Rook, n for Knight, b for Bishop, q for Queen,
  k for King, and p for Pawn.
- The columns (files) are labeled a-h from left to right,
  and the rows (ranks) are labeled 1-8 from bottom to top
  from White's perspective.
- A move is denoted by the piece's letter and its destination
  square, e.g., "Nf3" moves a knight to the f3 square.
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
- " e2 e4": Make a move from e2 to e4.
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
Status: [Game Status, ex( "White's Turn", "Check", "Checkmate")]
   
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
1 | R | N | B | Q | K | B | N | R |
  ---------------------------------
```
Components:

Status: Displays the current game status.

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
        GAME OVER - [WINNER White/Black or Stalemate
------------------------------------------------------------
1. Continue
2. Quit
Choose an option: [input]
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
1. e5
2. Nf3 Nc6
3. Bb5 a6
4. Ba4 Nf6
6. Re1 b5
7. Bb3 d6
...
Commands:
1. Return to Main Menu
2. Quit
Enter command: [input]
```
Components & Purpose:

Return to Main Menu: Go back to main menu to play again.

Quit: Ends program. 



## Class Diagram
<img src="UML Class Diagram.png?raw=true" width="1000">

Our game will be comprised of 4 main classes, the game itself, the board, the squares on the board, and the game pieces. The Game class has the primary controls over the game, such as switching turns and saving the game log afterwards. It will also hold the logic for determining whether inputs are valid, and when they are, whether they are legal moves or not. The Board class controls an 8x8 matrix of Squares, simulating a chessboard and holds the primary controls for moving the pieces themselves, and contains the graphics that the game will print out for the user. The Square class helps calculate all possible moves of the piece within the square, assisting in checking the legality of moves. Finally, the Piece class contains data that determines what each unique piece can do, and which side it belongs to, making sure it moves in the correct directions and captures the correct pieces.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 


