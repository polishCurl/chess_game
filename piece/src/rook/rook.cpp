#include "piece/src/rook/rook.hpp"

namespace chess {

namespace piece {

using namespace chess::common;

Rook::Rook(const Position& position, Color color) : Piece{position, color} {}

bool Rook::canMove(const Position& next) const {
  return Move::isBackward({position_, next}, color_) ||
         Move::isForward({position_, next}, color_) ||
         Move::isSide({position_, next});
  ;
}

bool Rook::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* Rook::getName() const { return kName; };

PieceType Rook::getType() const { return PieceType::Rook; }

}  // namespace piece
}  // namespace chess
