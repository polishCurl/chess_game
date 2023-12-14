#include "piece/src/bishop/bishop.hpp"

#include "gtest/gtest.h"

using namespace chess::piece;
using namespace chess::common;

TEST(BishopTest, Constructor) {
  EXPECT_NO_THROW((Bishop{Position{0, 0}, Color::Black}));
  EXPECT_NO_THROW((Bishop{Position{"D3"}, Color::White}));
  EXPECT_NO_THROW((Bishop{Position{"H1"}, Color::Black}));
}

class BishopColorFixture : public ::testing::TestWithParam<Color> {};

TEST_P(BishopColorFixture, GetPosition) {
  Bishop bishop{Position{"B6"}, GetParam()};
  EXPECT_EQ(bishop.getPosition(), Position{"B6"});
  EXPECT_FALSE(bishop.move(Position{"C4"}));
  EXPECT_EQ(bishop.getPosition(), Position{"B6"});
  EXPECT_TRUE(bishop.move(Position{"G1"}));
  EXPECT_EQ(bishop.getPosition(), Position{"G1"});
}

TEST_P(BishopColorFixture, GetColor) {
  const Bishop bishop{Position{"H1"}, GetParam()};
  EXPECT_EQ(bishop.getColor(), GetParam());
}

TEST_P(BishopColorFixture, GetName) {
  const Bishop bishop{Position{"H1"}, GetParam()};
  EXPECT_EQ(bishop.getName(), std::string("Bishop"));
}

TEST_P(BishopColorFixture, GetType) {
  const Bishop bishop{Position{"H1"}, GetParam()};
  EXPECT_EQ(bishop.getType(), PieceType::Bishop);
}

TEST_P(BishopColorFixture, CanMove) {
  const Bishop bishop{Position{"E2"}, GetParam()};
  EXPECT_FALSE(bishop.canMove(Position{"E2"}));
  EXPECT_FALSE(bishop.canMove(Position{"E1"}));
  EXPECT_FALSE(bishop.canMove(Position{"E3"}));
  EXPECT_FALSE(bishop.canMove(Position{"D2"}));
  EXPECT_FALSE(bishop.canMove(Position{"F2"}));
  EXPECT_TRUE(bishop.canMove(Position{"D3"}));
  EXPECT_TRUE(bishop.canMove(Position{"F3"}));
  EXPECT_TRUE(bishop.canMove(Position{"D1"}));
  EXPECT_TRUE(bishop.canMove(Position{"F1"}));

  EXPECT_FALSE(bishop.canMove(Position{"E4"}));
  EXPECT_FALSE(bishop.canMove(Position{"E8"}));
  EXPECT_FALSE(bishop.canMove(Position{"G2"}));
  EXPECT_FALSE(bishop.canMove(Position{"G3"}));
  EXPECT_FALSE(bishop.canMove(Position{"G1"}));
  EXPECT_FALSE(bishop.canMove(Position{"D4"}));
  EXPECT_FALSE(bishop.canMove(Position{"F4"}));

  EXPECT_FALSE(bishop.canMove(Position{"E8"}));
  EXPECT_TRUE(bishop.canMove(Position{"C4"}));
  EXPECT_TRUE(bishop.canMove(Position{"H5"}));
}

TEST_P(BishopColorFixture, Move) {
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E2"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E1"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E3"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"D2"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"F2"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"D3"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"F3"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"D1"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"F1"}));

  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E4"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"G2"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"G3"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"G1"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"D4"}));
  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"F4"}));

  EXPECT_FALSE((Bishop{Position{"E2"}, GetParam()}).move(Position{"E8"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"C4"}));
  EXPECT_TRUE((Bishop{Position{"E2"}, GetParam()}).move(Position{"H5"}));
}

TEST_P(BishopColorFixture, HasBeenMoved) {
  Bishop bishop{Position{"B6"}, GetParam()};
  EXPECT_FALSE(bishop.hasBeenMoved());
  EXPECT_FALSE(bishop.move(Position{"A8"}));
  EXPECT_FALSE(bishop.hasBeenMoved());
  EXPECT_TRUE(bishop.move(Position{"A7"}));
  EXPECT_TRUE(bishop.hasBeenMoved());
  EXPECT_FALSE(bishop.move(Position{"A7"}));
  EXPECT_TRUE(bishop.hasBeenMoved());
}

TEST_P(BishopColorFixture, StreamInsertion) {
  Bishop bishop{Position{"B6"}, GetParam()};
  std::stringstream test;
  test << bishop;
  std::stringstream ref;
  ref << "Bishop (" << GetParam() << ") on B6";
  EXPECT_EQ(test.str(), ref.str());
}

TEST_P(BishopColorFixture, CanJump) {
  Bishop bishop{Position{"B6"}, GetParam()};
  EXPECT_FALSE(bishop.canJump());
}

INSTANTIATE_TEST_SUITE_P(BishopTest, BishopColorFixture,
                         ::testing::Values(Color::Black, Color::White));
