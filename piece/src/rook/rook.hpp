#ifndef CHESS_PIECE_SRC_ROOK_HPP_
#define CHESS_PIECE_SRC_ROOK_HPP_

#include "src/piece.hpp"

namespace chess {

namespace piece {

class Rook : public Piece {
 public:
  Rook(const Position& position, Color color);
  bool canMove(const Position& next) const override;
  bool move(const Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static constexpr char kName[]{"Rook"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_ROOK_HPP_
