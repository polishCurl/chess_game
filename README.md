# Chess game
Chess game written in C++.

This project acts demonstrates the use of the best software engineering practices, which include:
1. Object-oriented programming (OOP) and design.
2. Design patterns.
3. SOLID principles.
4. Test-Drivern Development (TDD)
5. Containerization.

## Setup
The chess game is containerized to provide seemless delivery.
`Dockefile` contains instructions to build an image with all required dependencies to build and run the application.

Build the docker image:
```
docker build -t chess_game .
```

Run the container:
```
docker run --name chess_game_container -v $(pwd):/chess_game -it chess_game
```

Start an existing container:
```
docker start -i chess_game_container
```

Remove unnecessary images and containers:
```
docker image prune -a
docker container prune
```

## Useful commands
Execute all unit tests:
```
bazel test //... --test_output=all 
```

Generate code coverage report (located in `genhtml/index.html`):
```
bazel coverage //...
genhtml bazel-out/_coverage/_coverage_report.dat -o genhtml
```

Generate Doxygen docummentation (located in `doxydoc/html/index.html`):
```
doxygen
```

## Design patterns
A number of design patterns were used in the project:

### Factory method
The Factory Method separates product construction code from the code that actually uses the product. 
With Factory Methods for chess piece (`IPiece`) or chessboard (`IChessboard`), new types of chessboards of chess pieces can
be added without modifying the logic of the game.


## Testing
Each class has been unit-tested with ~100% coverage.
Unit tests are implemented using the GoogleTest framework.
Each interface has an associated mock created using the GoogleMock framework.
Each class is tested using only the public APIs (with minor exceptions).
