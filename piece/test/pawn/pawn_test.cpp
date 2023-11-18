#include "src/pawn/pawn.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(PawnTest, Constructor) {
  EXPECT_NO_THROW((Pawn{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((Pawn{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((Pawn{Position{"H1"}, Color::Black}));
}

TEST(PawnTest, GetPosition) {
  Pawn pawn_white{Position{"H2"}, Color::White};
  EXPECT_EQ(pawn_white.getPosition(), Position{"H2"});
  EXPECT_FALSE(pawn_white.move(Position{"G2"}));
  EXPECT_EQ(pawn_white.getPosition(), Position{"H2"});
  EXPECT_TRUE(pawn_white.move(Position{"H3"}));
  EXPECT_EQ(pawn_white.getPosition(), Position{"H3"});

  Pawn pawn_black{Position{"B6"}, Color::Black};
  EXPECT_EQ(pawn_black.getPosition(), Position{"B6"});
  EXPECT_FALSE(pawn_black.move(Position{"C6"}));
  EXPECT_EQ(pawn_black.getPosition(), Position{"B6"});
  EXPECT_TRUE(pawn_black.move(Position{"B4"}));
  EXPECT_EQ(pawn_black.getPosition(), Position{"B4"});
}

TEST(PawnTest, HasBeenMoved) {
  Pawn pawn_white{Position{"H2"}, Color::White};
  EXPECT_FALSE(pawn_white.hasBeenMoved());
  EXPECT_FALSE(pawn_white.move(Position{"G2"}));
  EXPECT_FALSE(pawn_white.hasBeenMoved());
  EXPECT_TRUE(pawn_white.move(Position{"H3"}));
  EXPECT_TRUE(pawn_white.hasBeenMoved());
  EXPECT_FALSE(pawn_white.move(Position{"H3"}));
  EXPECT_TRUE(pawn_white.hasBeenMoved());

  Pawn pawn_black{Position{"B6"}, Color::Black};
  EXPECT_FALSE(pawn_black.hasBeenMoved());
  EXPECT_FALSE(pawn_black.move(Position{"C6"}));
  EXPECT_FALSE(pawn_black.hasBeenMoved());
  EXPECT_TRUE(pawn_black.move(Position{"B4"}));
  EXPECT_TRUE(pawn_black.hasBeenMoved());
  EXPECT_FALSE(pawn_black.move(Position{"B4"}));
  EXPECT_TRUE(pawn_black.hasBeenMoved());
}

class PawnColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(PawnColorFixture, GetColor) {
  const Pawn pawn{Position{"H1"}, GetParam()};
  EXPECT_EQ(pawn.getColor(), GetParam());
}

TEST_P(PawnColorFixture, GetName) {
  const Pawn pawn{Position{"H1"}, GetParam()};
  EXPECT_EQ(pawn.getName(), std::string("Pawn"));
}

// TODO: Complete Pawn unit tests
/*
TEST_P(PawnColorFixture, CanMove) {
  const Pawn pawn{Position{"E2"}, GetParam()};
  EXPECT_FALSE(pawn.canMove(Position{"E2"}));
  EXPECT_FALSE(pawn.canMove(Position{"E1"}));
  EXPECT_FALSE(pawn.canMove(Position{"E3"}));
  EXPECT_FALSE(pawn.canMove(Position{"D2"}));
  EXPECT_FALSE(pawn.canMove(Position{"F2"}));
  EXPECT_TRUE(pawn.canMove(Position{"D3"}));
  EXPECT_TRUE(pawn.canMove(Position{"F3"}));
  EXPECT_TRUE(pawn.canMove(Position{"D1"}));
  EXPECT_TRUE(pawn.canMove(Position{"F1"}));

  EXPECT_FALSE(pawn.canMove(Position{"E4"}));
  EXPECT_FALSE(pawn.canMove(Position{"E8"}));
  EXPECT_FALSE(pawn.canMove(Position{"G2"}));
  EXPECT_FALSE(pawn.canMove(Position{"G3"}));
  EXPECT_FALSE(pawn.canMove(Position{"G1"}));
  EXPECT_FALSE(pawn.canMove(Position{"D4"}));
  EXPECT_FALSE(pawn.canMove(Position{"F4"}));

  EXPECT_FALSE(pawn.canMove(Position{"E8"}));
  EXPECT_TRUE(pawn.canMove(Position{"C4"}));
  EXPECT_TRUE(pawn.canMove(Position{"H5"}));
}

TEST_P(PawnColorFixture, Move) {
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E2"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E1"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E3"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"D2"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"F2"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"D3"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"F3"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"D1"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"F1"}));

  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E4"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"G2"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"G3"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"G1"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"D4"}));
  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"F4"}));

  EXPECT_FALSE((Pawn{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"C4"}));
  EXPECT_TRUE((Pawn{Position{"E2"}, GetParam()}).move(Position{"H5"}));
}
*/

INSTANTIATE_TEST_SUITE_P(PawnTest, PawnColorFixture,
                         ::testing::Values(Color::Black, Color::White));
