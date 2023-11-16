#include "src/piece_utilities/position.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(PositionTest, Constructor) {
  EXPECT_NO_THROW((Position{0, 0}));
  EXPECT_NO_THROW((Position{7, 7}));
  EXPECT_NO_THROW((Position{5, 2}));

  EXPECT_THROW((Position{8, 0}), std::invalid_argument);
  EXPECT_THROW((Position{0, 8}), std::invalid_argument);
  EXPECT_THROW((Position{8, 8}), std::invalid_argument);
  EXPECT_THROW((Position{-1, 1}), std::invalid_argument);
  EXPECT_THROW((Position{7, -3}), std::invalid_argument);
  EXPECT_THROW((Position{-10, -25}), std::invalid_argument);
}

TEST(PositionTest, Equality) {
  EXPECT_EQ((Position{1, 3}), (Position{1, 3}));
  EXPECT_EQ((Position{0, 0}), (Position{0, 0}));
  EXPECT_EQ((Position{7, 7}), (Position{7, 7}));
  EXPECT_NE((Position{1, 3}), (Position{3, 1}));
  EXPECT_NE((Position{7, 0}), (Position{3, 3}));
}

TEST(PositionTest, CopyAssignment) {
  Position a{2, 3};
  Position b{5, 7};
  a = b;
  EXPECT_EQ(a, (Position{5, 7}));
}

TEST(PositionTest, CopyConstructor) {
  Position a{2, 3};
  Position b{a};
  EXPECT_EQ(b, (Position{2, 3}));
}

TEST(PositionTest, MoveAssignment) {
  Position a{2, 3};
  Position b{5, 7};
  a = std::move(b);
  EXPECT_EQ(a, (Position{5, 7}));
}

TEST(PositionTest, MoveConstructor) {
  Position a{2, 3};
  Position b{std::move(a)};
  EXPECT_EQ(b, (Position{2, 3}));
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
  EXPECT_EQ((Position{"E5"}), (Position{3, 4}));
}

TEST(PositionTest, StringAssignment) {
  Position a{"A1"};
  a = "E2";
  EXPECT_EQ(a, (Position{6, 4}));
}

TEST(PositionTest, ConversionToString) {
  EXPECT_EQ(std::string(Position{0, 0}), "A8");
  EXPECT_EQ(static_cast<std::string>(Position{7, 7}), "H1");
  EXPECT_EQ(static_cast<std::string>(Position{2, 5}), "F6");
  EXPECT_EQ(static_cast<std::string>(Position{6, 6}), "G2");
}
