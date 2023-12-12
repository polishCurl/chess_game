# Chess game
Chess game written in C++.

This project acts demonstrates the use of the best software engineering practices, which include:
1. Object-oriented programming (OOP) and design.
2. Design patterns.
3. SOLID principles.
4. Test-Drivern Development (TDD)
5. Containerization.


## Design patterns
A number of design patterns were used in the project:

### Factory method
The Factory Method separates product construction code from the code that actually uses the product. 
With Factory Methods for chess piece (`IPiece`) or chessboard (`IChessboard`), new types of chessboards of chess pieces can
be added without modifying the logic of the game.



## Test-Drivern Development 
Each class has been unit-tested with 100% coverage.
Unit tests are implemented using the GoogleTest framework.
Each interface has an associated mock created using the GoogleMock framework.
Each class is tested using only the public APIs (with minor exceptions).
