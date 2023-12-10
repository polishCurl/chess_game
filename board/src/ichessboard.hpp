#ifndef CHESS_BOARD_SRC_ICHESSBOARD_HPP_
#define CHESS_BOARD_SRC_ICHESSBOARD_HPP_

#include "common/src/color/color.hpp"
#include "common/src/move/move.hpp"
#include "piece/src/ipiece.hpp"

namespace chess {

namespace board {

class IChessboard {
 public:
  IChessboard() = default;
  IChessboard(const IChessboard&) = delete;
  IChessboard& operator=(const IChessboard&) = delete;
  IChessboard(IChessboard&&) = delete;
  IChessboard& operator=(IChessboard&&) = delete;

  virtual ~IChessboard() = default;

  virtual void reset() = 0;
  virtual const chess::piece::IPiece* getPiece(
      const chess::common::Position& position) = 0;
  virtual bool addPiece(chess::piece::PieceType type,
                        chess::common::Color color,
                        const chess::common::Position& position) = 0;
  virtual bool removePiece(const chess::common::Position& position) = 0;
  virtual bool movePiece(chess::common::Color player_color,
                         const chess::common::Move& move) = 0;

  // TODO: Implement detection of check, checkmate and stalemate
  // virtual bool isKingInCheck(Color color) const;
  // virtual bool isKingCheckmated(Color color) const;
};

}  // namespace board
}  // namespace chess

#endif  // CHESS_BOARD_SRC_ICHESSBOARD_HPP_
