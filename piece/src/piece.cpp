#include "src/piece.hpp"

#include <sstream>

namespace chess {

namespace piece {

using namespace chess::common;

Piece::Piece(const Position& position, Color color)
    : position_{position}, color_{color}, has_been_moved_{false} {}

Position Piece::getPosition() const { return position_; }

bool Piece::hasBeenMoved() const { return has_been_moved_; }

Color Piece::getColor() const { return color_; }

std::ostream& operator<<(std::ostream& out, const IPiece& piece) {
  out << piece.getName() << " (" << piece.getColor() << ") on "
      << std::string(piece.getPosition());
  return out;
}

}  // namespace piece
}  // namespace chess