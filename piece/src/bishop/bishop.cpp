#include "src/bishop/bishop.hpp"

namespace chess {

namespace piece {

Bishop::Bishop(const Position& position, Color color)
    : Piece{position, color} {}

bool Bishop::canMove(const Position& next) const {
  return Move::isDiagonal(position_, next);
}

bool Bishop::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* Bishop::getName() const { return kName; };

}  // namespace piece
}  // namespace chess
