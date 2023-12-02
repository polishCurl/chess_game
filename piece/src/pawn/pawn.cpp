#include "src/pawn/pawn.hpp"

namespace chess {

namespace piece {

using namespace chess::common;

Pawn::Pawn(const Position& position, Color color) : Piece{position, color} {}

bool Pawn::canMove(const Position& next) const {
  const auto is_valid_first_move =
      !has_been_moved_ && Move::isPawnStartingMove({position_, next}, color_);
  const auto is_valid_move = Move::isForward({position_, next}, color_) &&
                             Move::isByOne({position_, next});
  return is_valid_first_move || is_valid_move;
}

bool Pawn::move(const Position& next) {
  const auto can_move = canMove(next);

  if (can_move) {
    position_ = next;
    has_been_moved_ = true;
  }

  return can_move;
};

const char* Pawn::getName() const { return kName; };

PieceType Pawn::getType() const { return PieceType::kPawn; }

}  // namespace piece
}  // namespace chess
