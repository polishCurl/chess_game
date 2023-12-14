#include "board/src/chessboard/chessboard.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;
using namespace chess::common;
using namespace chess::board;

TEST(ChessboardTest, InitialPiecePositions) {
  Chessboard board;
  EXPECT_NO_THROW(board.reset());

  for (int row = 0; row < 8; row++) {
    // Check Piece colors
    for (int col = 0; col < 8; col++) {
      if (row < 2) {
        EXPECT_EQ(Color::Black, board.getPiece(Position{row, col})->getColor());
      } else if (row > 5) {
        EXPECT_EQ(Color::White, board.getPiece(Position{row, col})->getColor());
      } else {
        EXPECT_FALSE(board.getPiece(Position{row, col}));
      }
    }
  }

  // Check Pawn positons
  for (const auto row : std::array<int, 2>{1, 6}) {
    for (int col = 0; col < 8; col++) {
      EXPECT_EQ(PieceType::Pawn, board.getPiece(Position{row, col})->getType());
    }
  }

  // Check other Piece positions
  const std::array<PieceType, 8> piece_types{
      PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen,
      PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook};

  for (const auto row : std::array<int, 2>{0, 7}) {
    for (int col = 0; col < 8; col++) {
      EXPECT_EQ(piece_types[col],
                board.getPiece(Position{row, col})->getType());
    }
  }
}

TEST(ChessboardTest, AddPiece) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Rook, Color::Black, Position{"A8"}));
  EXPECT_FALSE(board.addPiece(PieceType::Rook, Color::Black, Position{"A8"}));
  EXPECT_FALSE(board.addPiece(PieceType::King, Color::White, Position{"A8"}));
  EXPECT_EQ(PieceType::Rook, board.getPiece(Position{"A8"})->getType());
  EXPECT_EQ(Color::Black, board.getPiece(Position{"A8"})->getColor());

  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::White, Position{"A7"}));
  EXPECT_EQ(PieceType::Pawn, board.getPiece(Position{"A7"})->getType());
  EXPECT_EQ(Color::White, board.getPiece(Position{"A7"})->getColor());
}

TEST(ChessboardTest, RemovePiece) {
  Chessboard board{};
  EXPECT_FALSE(board.removePiece(Position{"G1"}));
  EXPECT_FALSE(board.getPiece(Position{"G1"}));
  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::White, Position{"G1"}));
  EXPECT_TRUE(board.removePiece(Position{"G1"}));
  EXPECT_FALSE(board.getPiece(Position{"G1"}));
  EXPECT_FALSE(board.removePiece(Position{"G1"}));
  EXPECT_TRUE(board.addPiece(PieceType::Queen, Color::Black, Position{"G1"}));
}

TEST(ChessboardTest, MovePieceWhichDontExist) {
  Chessboard board{};
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"B6"}, Position{"D4"}}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"B6"}, Position{"D4"}}));
  EXPECT_FALSE(board.getPiece(Position{"B6"}));
  EXPECT_FALSE(board.getPiece(Position{"D4"}));
}

TEST(ChessboardTest, MovePieceWhichDontBelongToThePlayer) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::White, Position{"G1"}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"G1"}, Position{"F3"}}));
  EXPECT_TRUE(board.getPiece(Position{"G1"}));
  EXPECT_FALSE(board.getPiece(Position{"F3"}));

  EXPECT_TRUE(board.addPiece(PieceType::Queen, Color::Black, Position{"D8"}));
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"D8"}, Position{"H4"}}));
  EXPECT_TRUE(board.getPiece(Position{"D8"}));
  EXPECT_FALSE(board.getPiece(Position{"H4"}));
}

TEST(ChessboardTest, ForbiddenPieceMove) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Bishop, Color::White, Position{"C1"}));
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"C1"}, Position{"C2"}}));
  EXPECT_TRUE(board.getPiece(Position{"C1"}));
  EXPECT_FALSE(board.getPiece(Position{"C2"}));

  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::Black, Position{"F7"}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"F7"}, Position{"F4"}}));
  EXPECT_TRUE(board.getPiece(Position{"F7"}));
  EXPECT_FALSE(board.getPiece(Position{"F4"}));
}

TEST(ChessboardTest, TargetPositionAlreadyOccupied) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Rook, Color::Black, Position{"A8"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::Black, Position{"A7"}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"A8"}, Position{"A7"}}));
  EXPECT_EQ(PieceType::Rook, board.getPiece(Position{"A8"})->getType());
  EXPECT_EQ(PieceType::Pawn, board.getPiece(Position{"A7"})->getType());

  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::White, Position{"G1"}));
  EXPECT_TRUE(board.addPiece(PieceType::Queen, Color::White, Position{"F3"}));
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"G1"}, Position{"F3"}}));
  EXPECT_EQ(PieceType::Knight, board.getPiece(Position{"G1"})->getType());
  EXPECT_EQ(PieceType::Queen, board.getPiece(Position{"F3"})->getType());
}

TEST(ChessboardTest, Capture) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Rook, Color::Black, Position{"A8"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::White, Position{"A7"}));
  EXPECT_TRUE(board.movePiece(Color::Black, {Position{"A8"}, Position{"A7"}}));
  EXPECT_FALSE(board.getPiece(Position{"A8"}));
  EXPECT_EQ(PieceType::Rook, board.getPiece(Position{"A7"})->getType());
  EXPECT_EQ(Color::Black, board.getPiece(Position{"A7"})->getColor());

  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::White, Position{"G1"}));
  EXPECT_TRUE(board.addPiece(PieceType::Queen, Color::Black, Position{"F3"}));
  EXPECT_TRUE(board.movePiece(Color::White, {Position{"G1"}, Position{"F3"}}));
  EXPECT_FALSE(board.getPiece(Position{"G1"}));
  EXPECT_EQ(PieceType::Knight, board.getPiece(Position{"F3"})->getType());
  EXPECT_EQ(Color::White, board.getPiece(Position{"F3"})->getColor());
}

TEST(ChessboardTest, Collision) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Rook, Color::Black, Position{"A8"}));
  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::Black, Position{"B8"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::White, Position{"A7"}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"A8"}, Position{"A6"}}));
  EXPECT_FALSE(board.getPiece(Position{"A6"}));
  EXPECT_FALSE(board.movePiece(Color::Black, {Position{"A8"}, Position{"C8"}}));
  EXPECT_FALSE(board.getPiece(Position{"C8"}));

  EXPECT_TRUE(board.addPiece(PieceType::Bishop, Color::White, Position{"C1"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::Black, Position{"B2"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::White, Position{"D2"}));
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"C1"}, Position{"A3"}}));
  EXPECT_FALSE(board.getPiece(Position{"A3"}));
  EXPECT_FALSE(board.movePiece(Color::White, {Position{"C1"}, Position{"H6"}}));
  EXPECT_FALSE(board.getPiece(Position{"H6"}));
}

TEST(ChessboardTest, JumpingPieceNoColission) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::Black, Position{"B8"}));
  EXPECT_TRUE(board.addPiece(PieceType::Bishop, Color::Black, Position{"B7"}));
  EXPECT_TRUE(board.addPiece(PieceType::Pawn, Color::White, Position{"B6"}));
  EXPECT_TRUE(board.addPiece(PieceType::King, Color::Black, Position{"C7"}));
  EXPECT_TRUE(board.movePiece(Color::Black, {Position{"B8"}, Position{"C6"}}));
  EXPECT_FALSE(board.getPiece(Position{"B8"}));
  EXPECT_TRUE(board.getPiece(Position{"C6"}));
}

TEST(ChessboardTest, NoCapture) {
  Chessboard board{};
  EXPECT_TRUE(board.addPiece(PieceType::Knight, Color::Black, Position{"G8"}));
  EXPECT_TRUE(board.movePiece(Color::Black, {Position{"G8"}, Position{"F6"}}));
  EXPECT_TRUE(board.movePiece(Color::Black, {Position{"F6"}, Position{"D5"}}));
  EXPECT_FALSE(board.getPiece(Position{"G8"}));
  EXPECT_FALSE(board.getPiece(Position{"F6"}));
  EXPECT_TRUE(board.getPiece(Position{"D5"}));

  EXPECT_TRUE(board.addPiece(PieceType::Queen, Color::White, Position{"D1"}));
  EXPECT_TRUE(board.movePiece(Color::White, {Position{"D1"}, Position{"A4"}}));
  EXPECT_TRUE(board.movePiece(Color::White, {Position{"A4"}, Position{"E4"}}));
  EXPECT_FALSE(board.getPiece(Position{"D1"}));
  EXPECT_FALSE(board.getPiece(Position{"A4"}));
  EXPECT_TRUE(board.getPiece(Position{"E4"}));
}

class ChessboardProtectedFixture : public Chessboard, public ::testing::Test {};

TEST_F(ChessboardProtectedFixture, DetectColision) {
  EXPECT_NO_THROW(Chessboard::reset());

  // No collision
  EXPECT_FALSE(Chessboard::detectColision({Position{"B7"}, Position{"B5"}}));
  EXPECT_FALSE(Chessboard::detectColision({Position{"A3"}, Position{"H3"}}));
  EXPECT_FALSE(Chessboard::detectColision({Position{"G6"}, Position{"D3"}}));
  EXPECT_FALSE(Chessboard::detectColision({Position{"C8"}, Position{"C8"}}));
  EXPECT_FALSE(Chessboard::detectColision({Position{"F7"}, Position{"E7"}}));

  // Collisions
  EXPECT_TRUE(Chessboard::detectColision({Position{"D8"}, Position{"D6"}}));
  EXPECT_TRUE(Chessboard::detectColision({Position{"H1"}, Position{"A1"}}));
  EXPECT_TRUE(Chessboard::detectColision({Position{"H8"}, Position{"H5"}}));
  EXPECT_TRUE(Chessboard::detectColision({Position{"A2"}, Position{"G8"}}));
}
