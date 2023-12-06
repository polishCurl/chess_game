#ifndef CHESS_BOARD_SRC_ICHESSBOARD_HPP_
#define CHESS_BOARD_SRC_ICHESSBOARD_HPP_

#include "common/src/color/color.hpp"
#include "common/src/move/move.hpp"
#include "piece/src/ipiece.hpp"

namespace chess {

namespace board {

enum class MoveResult {
  kInvalid,
  kNoCapture,
  kCapture,
  kCastling,
  kEnPassant,
  kPromotion,
};

class IChessboard {
 public:
  IChessboard() = default;
  IChessboard(const IChessboard&) = delete;
  IChessboard& operator=(const IChessboard&) = delete;
  IChessboard(IChessboard&&) = delete;
  IChessboard& operator=(IChessboard&&) = delete;

  virtual ~IChessboard() = default;

  virtual int getPieceCount(chess::common::Color color,
                            chess::piece::PieceType type) const = 0;
  virtual MoveResult move(chess::common::Color player_color,
                          const chess::common::Move& move) = 0;

  // TODO: Implement detection of check, checkmate and stalemate
  // virtual bool isKingInCheck(Color color) const;
  // virtual bool isKingCheckmated(Color color) const;
};

}  // namespace board
}  // namespace chess

#endif  // CHESS_BOARD_SRC_ICHESSBOARD_HPP_
