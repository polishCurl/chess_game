#include "src/piece_utilities/position.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(PositionTest, Constructor) {
  Position position{2, 3};
  EXPECT_EQ(position.row, 2);
  EXPECT_EQ(position.col, 3);
}

TEST(PositionTest, Assignment) {
  Position position{2, 3};
  position.row = -1;
  position.col = 32;
  EXPECT_EQ(position.row, -1);
  EXPECT_EQ(position.col, 32);
}

TEST(PositionTest, Equality) {
  EXPECT_EQ((Position{1, 3}), (Position{1, 3}));
  EXPECT_NE((Position{1, 3}), (Position{3, 1}));
  EXPECT_EQ((Position{0, 0}), (Position{0, 0}));
  EXPECT_NE((Position{-1, 0}), (Position{1, 0}));
  EXPECT_EQ((Position{-1, 0}), (Position{-1, 0}));
  EXPECT_NE((Position{3, -10}), (Position{3, 10}));
  EXPECT_EQ((Position{-3, -10}), (Position{-3, -10}));
}

TEST(PositionTest, Addition) {
  EXPECT_EQ((Position{1, 3}), (Position{1, 3} + Position{0, 0}));
  EXPECT_EQ((Position{2, 4}), (Position{1, 3} + Position{1, 1}));
  EXPECT_EQ((Position{0, 0}), (Position{1, 3} + Position{-1, -3}));
  EXPECT_EQ((Position{1, 1} + Position{1, 3}),
            (Position{1, 3} + Position{1, 1}));
  EXPECT_EQ((Position{4, -9}), (Position{-1, -7} + Position{5, -2}));
}

TEST(PositionTest, Subtraction) {
  EXPECT_EQ((Position{1, 3}), (Position{1, 3} - Position{0, 0}));
  EXPECT_EQ((Position{0, 2}), (Position{1, 3} - Position{1, 1}));
  EXPECT_EQ((Position{2, 6}), (Position{1, 3} - Position{-1, -3}));
  EXPECT_NE((Position{1, 1} + Position{1, 3}),
            (Position{1, 3} - Position{1, 1}));
  EXPECT_EQ((Position{-6, -5}), (Position{-1, -7} - Position{5, -2}));
}
