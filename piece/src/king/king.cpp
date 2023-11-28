#include "src/king/king.hpp"

namespace chess {

namespace piece {

King::King(const Position& position, Color color) : Piece{position, color} {}

bool King::canMove(const Position& next) const {
  return Move::isByOne(position_, next);
}

bool King::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* King::getName() const { return kName; };

PieceType King::getType() const { return PieceType::kKing; }

}  // namespace piece
}  // namespace chess
