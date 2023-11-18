#include "src/rook/rook.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(RookTest, Constructor) {
  EXPECT_NO_THROW((Rook{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((Rook{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((Rook{Position{"H1"}, Color::Black}));
}

class RookColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(RookColorFixture, GetPosition) {
  Rook rook{Position{"B6"}, GetParam()};
  EXPECT_EQ(rook.getPosition(), Position{"B6"});
  EXPECT_FALSE(rook.move(Position{"D4"}));
  EXPECT_EQ(rook.getPosition(), Position{"B6"});
  EXPECT_TRUE(rook.move(Position{"D6"}));
  EXPECT_EQ(rook.getPosition(), Position{"D6"});
}

TEST_P(RookColorFixture, GetColor) {
  const Rook rook{Position{"H1"}, GetParam()};
  EXPECT_EQ(rook.getColor(), GetParam());
}

TEST_P(RookColorFixture, GetName) {
  const Rook rook{Position{"H1"}, GetParam()};
  EXPECT_EQ(rook.getName(), std::string("Rook"));
}

TEST_P(RookColorFixture, CanMove) {
  const Rook rook{Position{"E2"}, GetParam()};
  EXPECT_FALSE(rook.canMove(Position{"E2"}));
  EXPECT_TRUE(rook.canMove(Position{"E1"}));
  EXPECT_TRUE(rook.canMove(Position{"E3"}));
  EXPECT_TRUE(rook.canMove(Position{"D2"}));
  EXPECT_TRUE(rook.canMove(Position{"F2"}));
  EXPECT_FALSE(rook.canMove(Position{"D3"}));
  EXPECT_FALSE(rook.canMove(Position{"F3"}));
  EXPECT_FALSE(rook.canMove(Position{"D1"}));
  EXPECT_FALSE(rook.canMove(Position{"F1"}));

  EXPECT_TRUE(rook.canMove(Position{"E4"}));
  EXPECT_TRUE(rook.canMove(Position{"E8"}));
  EXPECT_TRUE(rook.canMove(Position{"G2"}));
  EXPECT_FALSE(rook.canMove(Position{"G3"}));
  EXPECT_FALSE(rook.canMove(Position{"G1"}));
  EXPECT_FALSE(rook.canMove(Position{"D4"}));
  EXPECT_FALSE(rook.canMove(Position{"F4"}));

  EXPECT_TRUE(rook.canMove(Position{"E8"}));
  EXPECT_TRUE(rook.canMove(Position{"H2"}));
  EXPECT_FALSE(rook.canMove(Position{"H5"}));
}

TEST_P(RookColorFixture, Move) {
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"E2"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"E1"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"E3"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"D2"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"F2"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"D3"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"F3"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"D1"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"F1"}));

  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"E4"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"G2"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"G3"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"G1"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"D4"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"F4"}));

  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Rook{Position{"E2"}, GetParam()}).move(Position{"H2"}));
  EXPECT_FALSE((Rook{Position{"E2"}, GetParam()}).move(Position{"H5"}));
}

TEST_P(RookColorFixture, HasBeenMoved) {
  Rook rook{Position{"B6"}, GetParam()};
  EXPECT_FALSE(rook.hasBeenMoved());
  EXPECT_FALSE(rook.move(Position{"A5"}));
  EXPECT_FALSE(rook.hasBeenMoved());
  EXPECT_TRUE(rook.move(Position{"A6"}));
  EXPECT_TRUE(rook.hasBeenMoved());
  EXPECT_FALSE(rook.move(Position{"A6"}));
  EXPECT_TRUE(rook.hasBeenMoved());
}

INSTANTIATE_TEST_SUITE_P(RookTest, RookColorFixture,
                         ::testing::Values(Color::Black, Color::White));
