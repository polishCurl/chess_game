#ifndef CHESS_PIECE_SRC_BISHOP_HPP_
#define CHESS_PIECE_SRC_BISHOP_HPP_

#include "src/piece.hpp"

namespace chess {

namespace piece {

class Bishop : public Piece {
 public:
  Bishop(const Position& position, Color color);
  bool canMove(const Position& next) const override;
  bool move(const Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static constexpr char kName[]{"Bishop"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_BISHOP_HPP_
