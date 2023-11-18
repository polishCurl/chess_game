#include "src/knight/knight.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(KnightTest, Constructor) {
  EXPECT_NO_THROW((Knight{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((Knight{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((Knight{Position{"H1"}, Color::Black}));
}

class KnightColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(KnightColorFixture, GetPosition) {
  Knight knight{Position{"B6"}, GetParam()};
  EXPECT_EQ(knight.getPosition(), Position{"B6"});
  EXPECT_FALSE(knight.move(Position{"A7"}));
  EXPECT_EQ(knight.getPosition(), Position{"B6"});
  EXPECT_TRUE(knight.move(Position{"A8"}));
  EXPECT_EQ(knight.getPosition(), Position{"A8"});
}

TEST_P(KnightColorFixture, GetColor) {
  const Knight knight{Position{"H1"}, GetParam()};
  EXPECT_EQ(knight.getColor(), GetParam());
}

TEST_P(KnightColorFixture, GetName) {
  const Knight knight{Position{"H1"}, GetParam()};
  EXPECT_EQ(knight.getName(), std::string("Knight"));
}

TEST_P(KnightColorFixture, CanMove) {
  const Knight knight{Position{"D4"}, GetParam()};
  EXPECT_FALSE(knight.canMove(Position{"D4"}));

  EXPECT_FALSE(knight.canMove(Position{"B6"}));
  EXPECT_TRUE(knight.canMove(Position{"C6"}));
  EXPECT_FALSE(knight.canMove(Position{"D6"}));
  EXPECT_TRUE(knight.canMove(Position{"E6"}));
  EXPECT_FALSE(knight.canMove(Position{"F6"}));
  EXPECT_TRUE(knight.canMove(Position{"F5"}));
  EXPECT_FALSE(knight.canMove(Position{"F4"}));
  EXPECT_TRUE(knight.canMove(Position{"F3"}));
  EXPECT_FALSE(knight.canMove(Position{"F2"}));
  EXPECT_TRUE(knight.canMove(Position{"E2"}));
  EXPECT_FALSE(knight.canMove(Position{"D2"}));
  EXPECT_TRUE(knight.canMove(Position{"C2"}));
  EXPECT_FALSE(knight.canMove(Position{"B2"}));
  EXPECT_TRUE(knight.canMove(Position{"B3"}));
  EXPECT_FALSE(knight.canMove(Position{"B4"}));
  EXPECT_TRUE(knight.canMove(Position{"B5"}));

  EXPECT_FALSE(knight.canMove(Position{"D7"}));
  EXPECT_FALSE(knight.canMove(Position{"H8"}));
  EXPECT_FALSE(knight.canMove(Position{"H7"}));
}

TEST_P(KnightColorFixture, Move) {
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"D4"}));

  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"B6"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"C6"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"D6"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"E6"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"F6"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"F5"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"F4"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"F3"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"F2"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"E2"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"D2"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"C2"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"B2"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"B3"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"B4"}));
  EXPECT_TRUE((Knight{Position{"D4"}, GetParam()}).move(Position{"B5"}));

  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"D7"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"H8"}));
  EXPECT_FALSE((Knight{Position{"D4"}, GetParam()}).move(Position{"H7"}));
}

TEST_P(KnightColorFixture, HasBeenMoved) {
  Knight knight{Position{"B6"}, GetParam()};
  EXPECT_FALSE(knight.hasBeenMoved());
  EXPECT_FALSE(knight.move(Position{"B4"}));
  EXPECT_FALSE(knight.hasBeenMoved());
  EXPECT_TRUE(knight.move(Position{"D5"}));
  EXPECT_TRUE(knight.hasBeenMoved());
  EXPECT_FALSE(knight.move(Position{"D5"}));
  EXPECT_TRUE(knight.hasBeenMoved());
}

INSTANTIATE_TEST_SUITE_P(KnightTest, KnightColorFixture,
                         ::testing::Values(Color::Black, Color::White));
