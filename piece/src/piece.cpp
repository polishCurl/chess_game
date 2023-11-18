#include "src/piece.hpp"

#include <sstream>

namespace chess {

namespace piece {

Piece::Piece(const Position& position, Color color)
    : position_{position}, color_{color}, has_been_moved_{false} {}

Position Piece::getPosition() const { return position_; }

bool Piece::hasBeenMoved() const { return has_been_moved_; }

Color Piece::getColor() const { return color_; }

}  // namespace piece
}  // namespace chess