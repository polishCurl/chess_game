#include "src/piece_utilities/position.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(PositionTest, Constructor) {
  Position position{2, 3};
  EXPECT_EQ(position.row_, 2);
  EXPECT_EQ(position.col_, 3);
}

TEST(PositionTest, Assignment) {
  Position position{2, 3};
  position.row_ = -1;
  position.col_ = 32;
  EXPECT_EQ(position.row_, -1);
  EXPECT_EQ(position.col_, 32);
}

TEST(PositionTest, CopySemantics) {
  Position a{2, 3};
  Position b{a};
  EXPECT_EQ(b.row_, 2);
  EXPECT_EQ(b.col_, 3);
  Position c{-2, 132};
  b = c;
  EXPECT_EQ(b.row_, -2);
  EXPECT_EQ(b.col_, 132);
}

TEST(PositionTest, MoveSemantics) {
  Position a{2, 3};
  Position b{std::move(a)};
  EXPECT_EQ(b.row_, 2);
  EXPECT_EQ(b.col_, 3);
  EXPECT_EQ(a.row_, 2);
  EXPECT_EQ(a.col_, 3);
  Position c{-2, 132};
  b = std::move(c);
  EXPECT_EQ(b.row_, -2);
  EXPECT_EQ(b.col_, 132);
}

TEST(PositionTest, StringConstructor) {
  EXPECT_NO_THROW(Position{"A1"});
  EXPECT_NO_THROW(Position{"A8"});
  EXPECT_NO_THROW(Position{"H1"});
  EXPECT_NO_THROW(Position{"H8"});

  EXPECT_THROW(Position{"A13"}, std::invalid_argument);
  EXPECT_THROW(Position{"D6z"}, std::invalid_argument);
  EXPECT_THROW(Position{"*1"}, std::invalid_argument);
  EXPECT_THROW(Position{"C&"}, std::invalid_argument);
  EXPECT_THROW(Position{"I6"}, std::invalid_argument);
  EXPECT_THROW(Position{"I6"}, std::invalid_argument);
  EXPECT_THROW(Position{"D0"}, std::invalid_argument);
  EXPECT_THROW(Position{"D9"}, std::invalid_argument);
  EXPECT_THROW(Position{"d2"}, std::invalid_argument);

  EXPECT_EQ((Position{"A1"}), (Position{7, 0}));
  EXPECT_EQ((Position{"A8"}), (Position{0, 0}));
  EXPECT_EQ((Position{"H1"}), (Position{7, 7}));
  EXPECT_EQ((Position{"H8"}), (Position{0, 7}));
}

TEST(PositionTest, StringAssignment) {
  Position a{"A1"};
  a = "E2";
  EXPECT_EQ(a, (Position{6, 4}));
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
