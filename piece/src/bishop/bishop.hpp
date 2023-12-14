#ifndef CHESS_PIECE_SRC_BISHOP_HPP_
#define CHESS_PIECE_SRC_BISHOP_HPP_

#include "piece/src/piece/piece.hpp"

namespace chess {

namespace piece {

class Bishop : public Piece {
 public:
  Bishop(const chess::common::Position& position, chess::common::Color color);
  bool canMove(const chess::common::Position& next) const override;
  bool move(const chess::common::Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static inline constexpr char kName[]{"Bishop"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_BISHOP_HPP_
