#ifndef CHESS_PIECE_SRC_KNIGHT_HPP_
#define CHESS_PIECE_SRC_KNIGHT_HPP_

#include "src/piece/piece.hpp"

namespace chess {

namespace piece {

class Knight : public Piece {
 public:
  Knight(const chess::common::Position& position, chess::common::Color color);
  bool canMove(const chess::common::Position& next) const override;
  bool move(const chess::common::Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;
  bool canJump() const override;

 private:
  static constexpr char kName[]{"Knight"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_KNIGHT_HPP_
