#include "src/queen/queen.hpp"

namespace chess {

namespace piece {

Queen::Queen(const Position& position, Color color) : Piece{position, color} {}

bool Queen::canMove(const Position& next) const {
  return Move::isBackward(position_, next, color_) ||
         Move::isForward(position_, next, color_) ||
         Move::isDiagonal(position_, next) || Move::isSide(position_, next);
  ;
}

bool Queen::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* Queen::getName() const { return kName; };

PieceType Queen::getType() const { return PieceType::kQueen; }

}  // namespace piece
}  // namespace chess
