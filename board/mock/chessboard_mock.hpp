#ifndef CHESS_BOARD_MOCK_CHESSBOARD_MOCK_HPP_
#define CHESS_BOARD_MOCK_CHESSBOARD_MOCK_HPP_

#include "gmock/gmock.h"
#include "src/ichessboard.hpp"

namespace chess {

namespace board {

class ChessboardMock : public IChessboard {
 public:
  MOCK_METHOD(void, reset, (), (override));
  MOCK_METHOD(const chess::piece::IPiece*, getPiece,
              (const chess::common::Position& position), (override));
  MOCK_METHOD(bool, addPiece,
              (chess::piece::PieceType type, chess::common::Color color,
               const chess::common::Position& position),
              (override));
  MOCK_METHOD(bool, removePiece, (const chess::common::Position& position),
              (override));
  MOCK_METHOD(bool, movePiece,
              (chess::common::Color player_color,
               const chess::common::Move& move),
              (override));
};

}  // namespace board
}  // namespace chess

#endif  // CHESS_BOARD_MOCK_CHESSBOARD_MOCK_HPP_