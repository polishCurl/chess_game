#include "src/piece_factory/piece_factory.hpp"

#include "gtest/gtest.h"
#include "src/king/king.hpp"
#include "src/queen/queen.hpp"

using namespace chess::piece;

class PieceFactoryTest : public ::testing::TestWithParam<PieceType> {
 protected:
  PieceFactory factory_;
};

TEST_P(PieceFactoryTest, Create) {
  std::unique_ptr<IPiece> piece =
      factory_.create(GetParam(), Position{"H7"}, Color::White);
  EXPECT_EQ(piece->getType(), GetParam());
}

TEST_F(PieceFactoryTest, DynamicCast) {
  std::unique_ptr<IPiece> piece =
      factory_.create(PieceType::kQueen, Position{"H7"}, Color::White);
  EXPECT_NE(dynamic_cast<Queen*>(piece.get()), nullptr);
  EXPECT_EQ(dynamic_cast<King*>(piece.get()), nullptr);
}

INSTANTIATE_TEST_SUITE_P(PieceTypeFixture, PieceFactoryTest,
                         ::testing::Values(PieceType::kPawn,
                                           PieceType::kKnight));
