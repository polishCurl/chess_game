#include "src/knight/knight.hpp"

namespace chess {

namespace piece {

using namespace chess::common;

Knight::Knight(const Position& position, Color color)
    : Piece{position, color} {}

bool Knight::canMove(const Position& next) const {
  return Move::isKnightMove({position_, next});
}

bool Knight::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* Knight::getName() const { return kName; };

PieceType Knight::getType() const { return PieceType::kKnight; }

}  // namespace piece
}  // namespace chess
