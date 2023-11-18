#include "src/piece_utilities/move.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(MoveTest, IsDiagonal) {
  EXPECT_FALSE(Move::isDiagonal(Position{1, 1}, Position{1, 1}));
  EXPECT_TRUE(Move::isDiagonal(Position{1, 1}, Position{2, 2}));
  EXPECT_TRUE(Move::isDiagonal(Position{1, 1}, Position{0, 0}));
  EXPECT_TRUE(Move::isDiagonal(Position{1, 1}, Position{2, 0}));
  EXPECT_TRUE(Move::isDiagonal(Position{1, 1}, Position{0, 2}));
  EXPECT_FALSE(Move::isDiagonal(Position{1, 1}, Position{1, 2}));
  EXPECT_FALSE(Move::isDiagonal(Position{1, 1}, Position{1, 0}));
  EXPECT_FALSE(Move::isDiagonal(Position{1, 1}, Position{2, 1}));
  EXPECT_FALSE(Move::isDiagonal(Position{1, 1}, Position{0, 1}));

  EXPECT_TRUE(Move::isDiagonal(Position{2, 5}, Position{0, 7}));
  EXPECT_TRUE(Move::isDiagonal(Position{2, 5}, Position{4, 3}));
  EXPECT_FALSE(Move::isDiagonal(Position{2, 5}, Position{0, 6}));
  EXPECT_FALSE(Move::isDiagonal(Position{2, 5}, Position{4, 0}));
}

TEST(MoveTest, IsForward) {
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{1, 1}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{1, 1}, Color::White));
  EXPECT_TRUE(Move::isForward(Position{1, 1}, Position{2, 1}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{2, 1}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{0, 1}, Color::Black));
  EXPECT_TRUE(Move::isForward(Position{1, 1}, Position{0, 1}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{2, 4}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{1, 1}, Position{2, 4}, Color::White));
  EXPECT_TRUE(Move::isForward(Position{4, 5}, Position{7, 5}, Color::Black));
  EXPECT_TRUE(Move::isForward(Position{4, 5}, Position{1, 5}, Color::White));

  EXPECT_TRUE(Move::isForward(Position{"B2"}, Position{"B5"}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{"B2"}, Position{"B5"}, Color::Black));
  EXPECT_FALSE(Move::isForward(Position{"F1"}, Position{"G7"}, Color::White));
  EXPECT_FALSE(Move::isForward(Position{"B2"}, Position{"B5"}, Color::Black));
}

TEST(MoveTest, IsBackward) {
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{1, 1}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{1, 1}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{2, 1}, Color::Black));
  EXPECT_TRUE(Move::isBackward(Position{1, 1}, Position{2, 1}, Color::White));
  EXPECT_TRUE(Move::isBackward(Position{1, 1}, Position{0, 1}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{0, 1}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{2, 4}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{1, 1}, Position{2, 4}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{4, 5}, Position{7, 5}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{4, 5}, Position{1, 5}, Color::White));

  EXPECT_TRUE(Move::isBackward(Position{"D4"}, Position{"D1"}, Color::White));
  EXPECT_TRUE(Move::isBackward(Position{"H1"}, Position{"H8"}, Color::Black));
  EXPECT_FALSE(Move::isBackward(Position{"B6"}, Position{"A1"}, Color::White));
  EXPECT_FALSE(Move::isBackward(Position{"F7"}, Position{"E8"}, Color::Black));
}

TEST(MoveTest, IsSide) {
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{1, 1}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{2, 2}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{0, 0}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{2, 0}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{0, 2}));
  EXPECT_TRUE(Move::isSide(Position{1, 1}, Position{1, 2}));
  EXPECT_TRUE(Move::isSide(Position{1, 1}, Position{1, 0}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{2, 1}));
  EXPECT_FALSE(Move::isSide(Position{1, 1}, Position{0, 1}));

  EXPECT_TRUE(Move::isSide(Position{3, 1}, Position{3, 0}));
  EXPECT_TRUE(Move::isSide(Position{3, 1}, Position{3, 7}));
  EXPECT_FALSE(Move::isSide(Position{2, 2}, Position{4, 1}));
}

TEST(MoveTest, IsByOne) {
  EXPECT_FALSE(Move::isByOne(Position{1, 1}, Position{1, 1}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{2, 2}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{0, 0}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{2, 0}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{0, 2}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{1, 2}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{1, 0}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{2, 1}));
  EXPECT_TRUE(Move::isByOne(Position{1, 1}, Position{0, 1}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{0, 7}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{4, 3}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{0, 6}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{4, 0}));
  EXPECT_FALSE(Move::isByOne(Position{2, 5}, Position{2, 3}));
}

// TODO: Add remaining Move class tests