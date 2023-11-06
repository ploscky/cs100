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
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

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
 


