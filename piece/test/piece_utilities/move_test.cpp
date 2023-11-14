#include "src/piece_utilities/move.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(MoveTest, IsWithinChessboard) {
  EXPECT_TRUE(Move::isWithinChessBoard(Position{0, 0}));
  EXPECT_TRUE(Move::isWithinChessBoard(Position{7, 7}));
  EXPECT_TRUE(Move::isWithinChessBoard(Position{5, 2}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{8, 0}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{0, 8}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{8, 8}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{-1, 1}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{7, -3}));
  EXPECT_FALSE(Move::isWithinChessBoard(Position{-10, -25}));
}

TEST(MoveTest, IsDiagonal) {
  EXPECT_FALSE(Move::isDiagonal(Position{0, 0}, Position{0, 0}));
  EXPECT_TRUE(Move::isDiagonal(Position{0, 0}, Position{1, 1}));
  EXPECT_TRUE(Move::isDiagonal(Position{0, 0}, Position{-1, -1}));
  EXPECT_TRUE(Move::isDiagonal(Position{0, 0}, Position{1, -1}));
  EXPECT_TRUE(Move::isDiagonal(Position{0, 0}, Position{-1, 1}));
  EXPECT_FALSE(Move::isDiagonal(Position{0, 0}, Position{0, 1}));
  EXPECT_FALSE(Move::isDiagonal(Position{0, 0}, Position{0, -1}));
  EXPECT_FALSE(Move::isDiagonal(Position{0, 0}, Position{-1, 0}));
  EXPECT_FALSE(Move::isDiagonal(Position{0, 0}, Position{1, 0}));
  EXPECT_TRUE(Move::isDiagonal(Position{2, 5}, Position{0, 7}));
  EXPECT_TRUE(Move::isDiagonal(Position{2, 5}, Position{4, 3}));
  EXPECT_FALSE(Move::isDiagonal(Position{2, 5}, Position{0, 6}));
  EXPECT_FALSE(Move::isDiagonal(Position{2, 5}, Position{4, 0}));
}

TEST(MoveTest, IsForward) {
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{0, 0}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{0, 0}, Color::White));
  EXPECT_TRUE(Move::isForward(Position{0, 0}, Position{1, 0}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{1, 0}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{-1, 0}, Color::Black));
  EXPECT_TRUE(Move::isForward(Position{0, 0}, Position{-1, 0}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{1, 3}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{0, 0}, Position{-1, -2}, Color::White));
  EXPECT_TRUE(Move::isForward(Position{4, 5}, Position{7, 5}, Color::Black));
  EXPECT_TRUE(Move::isForward(Position{4, 5}, Position{1, 5}, Color::White));
  EXPECT_TRUE(
      Move::isForward(Position{-4, -5}, Position{-1, -5}, Color::Black));
  EXPECT_TRUE(
      Move::isForward(Position{-4, -5}, Position{-7, -5}, Color::White));
}

TEST(MoveTest, IsBackward) {
  EXPECT_FALSE(Move::isBackward(Position{0, 0}, Position{0, 0}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{0, 0}, Position{0, 0}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{0, 0}, Position{1, 0}, Color::Black));
  EXPECT_TRUE(Move::isBackward(Position{0, 0}, Position{1, 0}, Color::White));
  EXPECT_TRUE(Move::isBackward(Position{0, 0}, Position{-1, 0}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{0, 0}, Position{-1, 0}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{0, 0}, Position{1, 3}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward(Position{0, 0}, Position{-1, -2}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{4, 5}, Position{7, 5}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{4, 5}, Position{1, 5}, Color::White));
  EXPECT_TRUE(Move::isBackward(Position{-1, 5}, Position{-3, 5}, Color::Black));
  EXPECT_TRUE(Move::isBackward(Position{4, 5}, Position{20, 5}, Color::White));
}

TEST(MoveTest, IsSide) {
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{0, 0}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{1, 1}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{-1, -1}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{1, -1}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{-1, 1}));
  EXPECT_TRUE(Move::isSide(Position{0, 0}, Position{0, 1}));
  EXPECT_TRUE(Move::isSide(Position{0, 0}, Position{0, -1}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{1, 0}));
  EXPECT_FALSE(Move::isSide(Position{0, 0}, Position{-1, 0}));
  EXPECT_TRUE(Move::isSide(Position{3, 1}, Position{3, 0}));
  EXPECT_TRUE(Move::isSide(Position{3, 1}, Position{3, 7}));
}

TEST(MoveTest, IsByOne) {
  EXPECT_FALSE(Move::isByOne(Position{0, 0}, Position{0, 0}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{1, 1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{-1, -1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{1, -1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{-1, 1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{0, 1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{0, -1}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{1, 0}));
  EXPECT_TRUE(Move::isByOne(Position{0, 0}, Position{-1, 0}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{0, 7}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{4, 3}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{0, 6}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{4, 0}));
  EXPECT_FALSE(Move::isByOne(Position{-30, 5}, Position{-32, 5}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{2, 3}));
}

// TODO: Add remaining Move class tests