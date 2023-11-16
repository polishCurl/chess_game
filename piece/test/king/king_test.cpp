#include "src/king/king.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(KingTest, Constructor) {
  EXPECT_NO_THROW((King{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((King{std::string("D3"), Color::White}));
  EXPECT_NO_THROW((King{std::string("H1"), Color::Black}));
}

TEST(KingTest, GetPosition) {
  const King king{std::string("H1"), Color::Black};
  EXPECT_EQ(king.getPosition(), (Position{"H1"}));
}

class KingColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(KingColorFixture, GetColor) {
  const King king_black{std::string("H1"), GetParam()};
  EXPECT_EQ(king_black.getColor(), GetParam());
}

TEST_P(KingColorFixture, CanMove) {
  const King king{std::string("E2"), GetParam()};
  EXPECT_FALSE(king.canMove(std::string("E2")));
  EXPECT_TRUE(king.canMove(std::string("E1")));
  EXPECT_TRUE(king.canMove(std::string("E3")));
  EXPECT_TRUE(king.canMove(std::string("D2")));
  EXPECT_TRUE(king.canMove(std::string("F2")));
  EXPECT_TRUE(king.canMove(std::string("D3")));
  EXPECT_TRUE(king.canMove(std::string("F3")));
  EXPECT_TRUE(king.canMove(std::string("D1")));
  EXPECT_TRUE(king.canMove(std::string("F1")));

  EXPECT_FALSE(king.canMove(std::string("E4")));
  EXPECT_FALSE(king.canMove(std::string("E8")));
  EXPECT_FALSE(king.canMove(std::string("G2")));
  EXPECT_FALSE(king.canMove(std::string("G3")));
  EXPECT_FALSE(king.canMove(std::string("G1")));
  EXPECT_FALSE(king.canMove(std::string("D4")));
  EXPECT_FALSE(king.canMove(std::string("F4")));
}

INSTANTIATE_TEST_SUITE_P(KingTest, KingColorFixture,
                         ::testing::Values(Color::Black, Color::White));
