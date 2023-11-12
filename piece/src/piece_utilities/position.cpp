#include "position.hpp"

#include <cmath>

namespace chess {

namespace piece {

Position::Position(int row, int col) : row{row}, col{col} {}

Position Position::operator+(const Position &other) const {
  return {row + other.row, col + other.col};
}

Position Position::operator-(const Position &other) const {
  return {row - other.row, col - other.col};
}

bool Position::operator==(const Position &other) const {
  return (row == other.row) && (col == other.col);
}

bool Position::operator!=(const Position &other) const {
  return (row != other.row) || (col != other.col);
}

}  // namespace piece
}  // namespace chess
