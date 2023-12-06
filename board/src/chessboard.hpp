#ifndef CHESS_BOARD_SRC_CHESSBOARD_HPP_
#define CHESS_BOARD_SRC_CHESSBOARD_HPP_

#include <array>
#include <memory>
#include <unordered_map>

#include "board/src/ichessboard.hpp"

namespace chess {

namespace board {

using Board = std::array<std::array<std::unique_ptr<chess::piece::IPiece>,
                                    chess::common::kChessBoardCols>,
                         chess::common::kChessBoardRows>;

using PieceMap = std::unordered_map<
    chess::common::Position,
    std::pair<chess::piece::PieceType, chess::common::Color>>;

class Chessboard : public IChessboard {
 public:
  Chessboard();
  int getPieceCount(chess::common::Color color,
                    chess::piece::PieceType type) const override;
  MoveResult move(chess::common::Color player_color,
                  const chess::common::Move& move) override;

 protected:
  std::unique_ptr<chess::piece::IPiece>& getPiece(
      const chess::common::Position& position);

  bool detectColision(const chess::common::Move& move);

  Board board_;
  static const PieceMap kPieceMap;
};

}  // namespace board
}  // namespace chess

#endif  // CHESS_BOARD_SRC_CHESSBOARD_HPP_
