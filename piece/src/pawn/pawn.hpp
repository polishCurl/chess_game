#ifndef CHESS_PIECE_SRC_PAWN_HPP_
#define CHESS_PIECE_SRC_PAWN_HPP_

#include "src/piece.hpp"

namespace chess {

namespace piece {

class Pawn : public Piece {
 public:
  Pawn(const Position& position, Color color);
  bool canMove(const Position& next) const override;
  bool move(const Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static constexpr char kName[]{"Pawn"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_PAWN_HPP_
