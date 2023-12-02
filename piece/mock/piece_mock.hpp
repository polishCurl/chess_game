#ifndef CHESS_PIECE_MOCK_PIECE_MOCK_HPP_
#define CHESS_PIECE_MOCK_PIECE_MOCK_HPP_

#include "gmock/gmock.h"
#include "src/ipiece.hpp"

namespace chess {

namespace piece {

class PieceMock : public IPiece {
 public:
  MOCK_METHOD(chess::common::Position, getPosition, (), (const override));
  MOCK_METHOD(bool, canMove, (const chess::common::Position& next),
              (const override));
  MOCK_METHOD(bool, move, (const chess::common::Position& next), (override));
  MOCK_METHOD(bool, hasBeenMoved, (), (const override));
  MOCK_METHOD(const char*, getName, (), (const override));
  MOCK_METHOD(chess::common::Color, getColor, (), (const override));
  MOCK_METHOD(PieceType, getType, (), (const override));
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_MOCK_PIECE_MOCK_HPP_