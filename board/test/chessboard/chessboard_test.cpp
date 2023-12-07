#include "src/chessboard/chessboard.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;
using namespace chess::common;
using namespace chess::board;

class ChessboardTest : public Chessboard, public ::testing::Test {};

TEST_F(ChessboardTest, InitialPiecePositions) {
  Chessboard board{};

  for (int row = 0; row < 8; row++) {
    // Check Piece colors
    for (int col = 0; col < 8; col++) {
      if (row < 2) {
        EXPECT_EQ(Color::Black,
                  Chessboard::getPiece(Position{row, col})->getColor());
      } else if (row > 5) {
        EXPECT_EQ(Color::White,
                  Chessboard::getPiece(Position{row, col})->getColor());
      } else {
        EXPECT_FALSE(Chessboard::getPiece(Position{row, col}));
      }
    }
  }

  // Check Pawn positons
  for (const auto row : std::array<int, 2>{1, 6}) {
    for (int col = 0; col < 8; col++) {
      EXPECT_EQ(PieceType::kPawn,
                Chessboard::getPiece(Position{row, col})->getType());
    }
  }

  // Check other Piece positions
  const std::array<PieceType, 8> piece_types{
      PieceType::kRook,   PieceType::kKnight, PieceType::kBishop,
      PieceType::kQueen,  PieceType::kKing,   PieceType::kBishop,
      PieceType::kKnight, PieceType::kRook};

  for (const auto row : std::array<int, 2>{0, 7}) {
    for (int col = 0; col < 8; col++) {
      EXPECT_EQ(piece_types[col],
                Chessboard::getPiece(Position{row, col})->getType());
    }
  }
}
