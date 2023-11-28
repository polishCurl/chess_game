#include "src/queen/queen.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(QueenTest, Constructor) {
  EXPECT_NO_THROW((Queen{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((Queen{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((Queen{Position{"H1"}, Color::Black}));
}

class QueenColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(QueenColorFixture, GetPosition) {
  Queen queen{Position{"H8"}, GetParam()};
  EXPECT_EQ(queen.getPosition(), Position{"H8"});
  EXPECT_FALSE(queen.move(Position{"A7"}));
  EXPECT_EQ(queen.getPosition(), Position{"H8"});
  EXPECT_TRUE(queen.move(Position{"D8"}));
  EXPECT_EQ(queen.getPosition(), Position{"D8"});
}

TEST_P(QueenColorFixture, GetColor) {
  const Queen queen{Position{"H1"}, GetParam()};
  EXPECT_EQ(queen.getColor(), GetParam());
}

TEST_P(QueenColorFixture, GetName) {
  const Queen queen{Position{"H1"}, GetParam()};
  EXPECT_EQ(queen.getName(), std::string("Queen"));
}

TEST_P(QueenColorFixture, GetType) {
  const Queen queen{Position{"H1"}, GetParam()};
  EXPECT_EQ(queen.getType(), PieceType::kQueen);
}

TEST_P(QueenColorFixture, CanMove) {
  const Queen queen{Position{"E2"}, GetParam()};
  EXPECT_FALSE(queen.canMove(Position{"E2"}));
  EXPECT_TRUE(queen.canMove(Position{"E1"}));
  EXPECT_TRUE(queen.canMove(Position{"E3"}));
  EXPECT_TRUE(queen.canMove(Position{"D2"}));
  EXPECT_TRUE(queen.canMove(Position{"F2"}));
  EXPECT_TRUE(queen.canMove(Position{"D3"}));
  EXPECT_TRUE(queen.canMove(Position{"F3"}));
  EXPECT_TRUE(queen.canMove(Position{"D1"}));
  EXPECT_TRUE(queen.canMove(Position{"F1"}));

  EXPECT_TRUE(queen.canMove(Position{"E4"}));
  EXPECT_TRUE(queen.canMove(Position{"E8"}));
  EXPECT_TRUE(queen.canMove(Position{"G2"}));
  EXPECT_FALSE(queen.canMove(Position{"G3"}));
  EXPECT_FALSE(queen.canMove(Position{"G1"}));
  EXPECT_FALSE(queen.canMove(Position{"D4"}));
  EXPECT_FALSE(queen.canMove(Position{"F4"}));

  EXPECT_TRUE(queen.canMove(Position{"E8"}));
  EXPECT_TRUE(queen.canMove(Position{"H2"}));
  EXPECT_TRUE(queen.canMove(Position{"H5"}));
}

TEST_P(QueenColorFixture, Move) {
  EXPECT_FALSE((Queen{Position{"E2"}, GetParam()}).move(Position{"E2"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"E1"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"E3"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"D2"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"F2"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"D3"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"F3"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"D1"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"F1"}));

  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"E4"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"G2"}));
  EXPECT_FALSE((Queen{Position{"E2"}, GetParam()}).move(Position{"G3"}));
  EXPECT_FALSE((Queen{Position{"E2"}, GetParam()}).move(Position{"G1"}));
  EXPECT_FALSE((Queen{Position{"E2"}, GetParam()}).move(Position{"D4"}));
  EXPECT_FALSE((Queen{Position{"E2"}, GetParam()}).move(Position{"F4"}));

  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"H2"}));
  EXPECT_TRUE((Queen{Position{"E2"}, GetParam()}).move(Position{"H5"}));
}

TEST_P(QueenColorFixture, HasBeenMoved) {
  Queen queen{Position{"B6"}, GetParam()};
  EXPECT_FALSE(queen.hasBeenMoved());
  EXPECT_FALSE(queen.move(Position{"H7"}));
  EXPECT_FALSE(queen.hasBeenMoved());
  EXPECT_TRUE(queen.move(Position{"G1"}));
  EXPECT_TRUE(queen.hasBeenMoved());
  EXPECT_FALSE(queen.move(Position{"G1"}));
  EXPECT_TRUE(queen.hasBeenMoved());
}

INSTANTIATE_TEST_SUITE_P(QueenTest, QueenColorFixture,
                         ::testing::Values(Color::Black, Color::White));
