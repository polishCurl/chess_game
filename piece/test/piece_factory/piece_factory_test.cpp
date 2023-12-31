#include "piece/src/piece_factory/piece_factory.hpp"

#include "gtest/gtest.h"
#include "piece/src/king/king.hpp"
#include "piece/src/queen/queen.hpp"

using namespace chess::piece;
using namespace chess::common;

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
      factory_.create(PieceType::Queen, Position{"H7"}, Color::White);
  EXPECT_NE(dynamic_cast<Queen*>(piece.get()), nullptr);
  EXPECT_EQ(dynamic_cast<King*>(piece.get()), nullptr);
}

INSTANTIATE_TEST_SUITE_P(PieceTypeFixture, PieceFactoryTest,
                         ::testing::Values(PieceType::Pawn, PieceType::Knight));

TEST_F(PieceFactoryTest, InvalidPieceType) {
  std::unique_ptr<IPiece> piece = factory_.create(static_cast<PieceType>(10000),
                                                  Position{"H7"}, Color::Black);
  EXPECT_FALSE(piece);
}
