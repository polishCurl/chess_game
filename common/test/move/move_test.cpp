#include "common/src/move/move.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace chess::common;

TEST(MoveTest, IsDiagonal) {
  EXPECT_FALSE(Move::isDiagonal({Position{1, 1}, Position{1, 1}}));
  EXPECT_TRUE(Move::isDiagonal({Position{1, 1}, Position{2, 2}}));
  EXPECT_TRUE(Move::isDiagonal({Position{1, 1}, Position{0, 0}}));
  EXPECT_TRUE(Move::isDiagonal({Position{1, 1}, Position{2, 0}}));
  EXPECT_TRUE(Move::isDiagonal({Position{1, 1}, Position{0, 2}}));
  EXPECT_FALSE(Move::isDiagonal({Position{1, 1}, Position{1, 2}}));
  EXPECT_FALSE(Move::isDiagonal({Position{1, 1}, Position{1, 0}}));
  EXPECT_FALSE(Move::isDiagonal({Position{1, 1}, Position{2, 1}}));
  EXPECT_FALSE(Move::isDiagonal({Position{1, 1}, Position{0, 1}}));

  EXPECT_TRUE(Move::isDiagonal({Position{2, 5}, Position{0, 7}}));
  EXPECT_TRUE(Move::isDiagonal({Position{2, 5}, Position{4, 3}}));
  EXPECT_FALSE(Move::isDiagonal({Position{2, 5}, Position{0, 6}}));
  EXPECT_FALSE(Move::isDiagonal({Position{2, 5}, Position{4, 0}}));
}

TEST(MoveTest, IsForward) {
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{1, 1}}, Color::Black));
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{1, 1}}, Color::White));
  EXPECT_TRUE(Move::isForward({Position{1, 1}, Position{2, 1}}, Color::Black));
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{2, 1}}, Color::White));
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{0, 1}}, Color::Black));
  EXPECT_TRUE(Move::isForward({Position{1, 1}, Position{0, 1}}, Color::White));
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{2, 4}}, Color::Black));
  EXPECT_FALSE(Move::isForward({Position{1, 1}, Position{2, 4}}, Color::White));
  EXPECT_TRUE(Move::isForward({Position{4, 5}, Position{7, 5}}, Color::Black));
  EXPECT_TRUE(Move::isForward({Position{4, 5}, Position{1, 5}}, Color::White));

  EXPECT_TRUE(Move::isForward({Position{"B2"}, Position{"B5"}}, Color::White));
  EXPECT_FALSE(Move::isForward({Position{"B2"}, Position{"B5"}}, Color::Black));
  EXPECT_FALSE(Move::isForward({Position{"F1"}, Position{"G7"}}, Color::White));
  EXPECT_FALSE(Move::isForward({Position{"B2"}, Position{"B5"}}, Color::Black));
}

TEST(MoveTest, IsBackward) {
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{1, 1}}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{1, 1}}, Color::White));
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{2, 1}}, Color::Black));
  EXPECT_TRUE(Move::isBackward({Position{1, 1}, Position{2, 1}}, Color::White));
  EXPECT_TRUE(Move::isBackward({Position{1, 1}, Position{0, 1}}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{0, 1}}, Color::White));
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{2, 4}}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward({Position{1, 1}, Position{2, 4}}, Color::White));
  EXPECT_FALSE(
      Move::isBackward({Position{4, 5}, Position{7, 5}}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward({Position{4, 5}, Position{1, 5}}, Color::White));

  EXPECT_TRUE(Move::isBackward({Position{"D4"}, Position{"D1"}}, Color::White));
  EXPECT_TRUE(Move::isBackward({Position{"H1"}, Position{"H8"}}, Color::Black));
  EXPECT_FALSE(
      Move::isBackward({Position{"B6"}, Position{"A1"}}, Color::White));
  EXPECT_FALSE(
      Move::isBackward({Position{"F7"}, Position{"E8"}}, Color::Black));
}

TEST(MoveTest, IsSide) {
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{1, 1}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{2, 2}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{0, 0}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{2, 0}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{0, 2}}));
  EXPECT_TRUE(Move::isSide({Position{1, 1}, Position{1, 2}}));
  EXPECT_TRUE(Move::isSide({Position{1, 1}, Position{1, 0}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{2, 1}}));
  EXPECT_FALSE(Move::isSide({Position{1, 1}, Position{0, 1}}));

  EXPECT_TRUE(Move::isSide({Position{3, 1}, Position{3, 0}}));
  EXPECT_TRUE(Move::isSide({Position{3, 1}, Position{3, 7}}));
  EXPECT_FALSE(Move::isSide({Position{2, 2}, Position{4, 1}}));
}

TEST(MoveTest, IsByOne) {
  EXPECT_FALSE(Move::isByOne({Position{1, 1}, Position{1, 1}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{2, 2}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{0, 0}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{2, 0}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{0, 2}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{1, 2}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{1, 0}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{2, 1}}));
  EXPECT_TRUE(Move::isByOne({Position{1, 1}, Position{0, 1}}));
  EXPECT_FALSE(Move::isByOne({Position{2, 5}, Position{0, 7}}));
  EXPECT_FALSE(Move::isByOne({Position{2, 5}, Position{4, 3}}));
  EXPECT_FALSE(Move::isByOne({Position{2, 5}, Position{0, 6}}));
  EXPECT_FALSE(Move::isByOne({Position{2, 5}, Position{4, 0}}));
  EXPECT_FALSE(Move::isByOne({Position{2, 5}, Position{2, 3}}));
}

TEST(MoveTest, IsPawnStartingMove) {
  EXPECT_TRUE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E4"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E4"}}, Color::Black));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E3"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E3"}}, Color::Black));

  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"G7"}, Position{"G5"}}, Color::White));
  EXPECT_TRUE(
      Move::isPawnStartingMove({Position{"G7"}, Position{"G5"}}, Color::Black));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"G7"}, Position{"G6"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"G7"}, Position{"G6"}}, Color::Black));

  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E1"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E1"}}, Color::Black));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"F3"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"F3"}}, Color::Black));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"D3"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"D3"}}, Color::Black));

  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E8"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"E8"}}, Color::Black));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"A2"}}, Color::White));
  EXPECT_FALSE(
      Move::isPawnStartingMove({Position{"E2"}, Position{"A2"}}, Color::Black));
}

TEST(MoveTest, IsKnightMove) {
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{1, 1}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{2, 2}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{0, 0}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{2, 0}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{0, 2}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{1, 2}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{1, 0}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{2, 1}}));
  EXPECT_FALSE(Move::isKnightMove({Position{1, 1}, Position{0, 1}}));

  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"B6"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"C6"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"D6"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"E6"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"F6"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"F5"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"F4"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"F3"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"F2"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"E2"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"D2"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"C2"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"B2"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"B3"}}));
  EXPECT_FALSE(Move::isKnightMove({Position{"D4"}, Position{"B4"}}));
  EXPECT_TRUE(Move::isKnightMove({Position{"D4"}, Position{"B5"}}));
}

TEST(MoveTest, Revert) {
  const auto original_move{Move{Position{"D4"}, Position{"C2"}}};
  const auto reverted_move{Move::revert(original_move)};
  EXPECT_EQ(original_move.curr_pos_, reverted_move.next_pos_);
  EXPECT_EQ(original_move.next_pos_, reverted_move.curr_pos_);
}

TEST(MoveTest, GetIntermediatePositions) {
  // Move by 0 positions
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"D4"}}).size(),
      0);

  // Move by 1 position in all directions
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"D5"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"D3"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"E4"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"C4"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"C5"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"E5"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"C3"}}).size(),
      0);
  EXPECT_EQ(
      Move::getIntermediatePositions({Position{"D4"}, Position{"E3"}}).size(),
      0);

  // Move by 2 positions in all directions
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"D6"}}),
              ::testing::ElementsAreArray({Position{"D5"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"D2"}}),
              ::testing::ElementsAreArray({Position{"D3"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"F4"}}),
              ::testing::ElementsAreArray({Position{"E4"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"B4"}}),
              ::testing::ElementsAreArray({Position{"C4"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"B6"}}),
              ::testing::ElementsAreArray({Position{"C5"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"F6"}}),
              ::testing::ElementsAreArray({Position{"E5"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"B2"}}),
              ::testing::ElementsAreArray({Position{"C3"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"D4"}, Position{"F2"}}),
              ::testing::ElementsAreArray({Position{"E3"}}));

  // Move by 3+ positions in all directions
  EXPECT_THAT(Move::getIntermediatePositions({Position{"A1"}, Position{"H8"}}),
              ::testing::ElementsAreArray({Position{"B2"}, Position{"C3"},
                                           Position{"D4"}, Position{"E5"},
                                           Position{"F6"}, Position{"G7"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"A1"}, Position{"A5"}}),
              ::testing::ElementsAreArray(
                  {Position{"A2"}, Position{"A3"}, Position{"A4"}}));
  EXPECT_THAT(Move::getIntermediatePositions({Position{"E5"}, Position{"B5"}}),
              ::testing::ElementsAreArray({Position{"D5"}, Position{"C5"}}));
}
