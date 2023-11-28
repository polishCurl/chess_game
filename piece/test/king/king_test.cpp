#include "src/king/king.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;

TEST(KingTest, Constructor) {
  EXPECT_NO_THROW((King{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((King{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((King{Position{"H1"}, Color::Black}));
}

class KingColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(KingColorFixture, GetPosition) {
  King king{Position{"H8"}, GetParam()};
  EXPECT_EQ(king.getPosition(), Position{"H8"});
  EXPECT_FALSE(king.move(Position{"H6"}));
  EXPECT_EQ(king.getPosition(), Position{"H8"});
  EXPECT_TRUE(king.move(Position{"G7"}));
  EXPECT_EQ(king.getPosition(), Position{"G7"});
}

TEST_P(KingColorFixture, GetColor) {
  const King king{Position{"H1"}, GetParam()};
  EXPECT_EQ(king.getColor(), GetParam());
}

TEST_P(KingColorFixture, GetName) {
  const King king{Position{"H1"}, GetParam()};
  EXPECT_EQ(king.getName(), std::string("King"));
}

TEST_P(KingColorFixture, GetType) {
  const King king{Position{"H1"}, GetParam()};
  EXPECT_EQ(king.getType(), PieceType::kKing);
}

TEST_P(KingColorFixture, CanMove) {
  const King king{Position{"E2"}, GetParam()};
  EXPECT_FALSE(king.canMove(Position{"E2"}));
  EXPECT_TRUE(king.canMove(Position{"E1"}));
  EXPECT_TRUE(king.canMove(Position{"E3"}));
  EXPECT_TRUE(king.canMove(Position{"D2"}));
  EXPECT_TRUE(king.canMove(Position{"F2"}));
  EXPECT_TRUE(king.canMove(Position{"D3"}));
  EXPECT_TRUE(king.canMove(Position{"F3"}));
  EXPECT_TRUE(king.canMove(Position{"D1"}));
  EXPECT_TRUE(king.canMove(Position{"F1"}));

  EXPECT_FALSE(king.canMove(Position{"E4"}));
  EXPECT_FALSE(king.canMove(Position{"E8"}));
  EXPECT_FALSE(king.canMove(Position{"G2"}));
  EXPECT_FALSE(king.canMove(Position{"G3"}));
  EXPECT_FALSE(king.canMove(Position{"G1"}));
  EXPECT_FALSE(king.canMove(Position{"D4"}));
  EXPECT_FALSE(king.canMove(Position{"F4"}));
}

TEST_P(KingColorFixture, Move) {
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"E2"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"E1"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"E3"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"D2"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"F2"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"D3"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"F3"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"D1"}));
  EXPECT_TRUE((King{Position{"E2"}, GetParam()}).move(Position{"F1"}));

  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"E4"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"G2"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"G3"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"G1"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"D4"}));
  EXPECT_FALSE((King{Position{"E2"}, GetParam()}).move(Position{"F4"}));
}

TEST_P(KingColorFixture, HasBeenMoved) {
  King king{Position{"H8"}, GetParam()};
  EXPECT_FALSE(king.hasBeenMoved());
  EXPECT_FALSE(king.move(Position{"H6"}));
  EXPECT_FALSE(king.hasBeenMoved());
  EXPECT_TRUE(king.move(Position{"G7"}));
  EXPECT_TRUE(king.hasBeenMoved());
  EXPECT_FALSE(king.move(Position{"G7"}));
  EXPECT_TRUE(king.hasBeenMoved());
}

INSTANTIATE_TEST_SUITE_P(KingTest, KingColorFixture,
                         ::testing::Values(Color::Black, Color::White));
