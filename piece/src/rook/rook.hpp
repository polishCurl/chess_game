#ifndef CHESS_PIECE_SRC_ROOK_HPP_
#define CHESS_PIECE_SRC_ROOK_HPP_

#include "piece/src/piece/piece.hpp"

namespace chess {

namespace piece {

class Rook : public Piece {
 public:
  Rook(const chess::common::Position& position, chess::common::Color color);
  bool canMove(const chess::common::Position& next) const override;
  bool move(const chess::common::Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static inline constexpr char kName[]{"Rook"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_ROOK_HPP_
