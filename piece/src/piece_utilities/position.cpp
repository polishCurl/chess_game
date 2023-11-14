#include "position.hpp"

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace chess {

namespace piece {

Position::Position(int row, int col) : row{row}, col{col} {}

Position::Position(const std::string &coordinates) {
  if ((coordinates.size() != 2) || (coordinates[0] < 'A') ||
      (coordinates[0] > 'H') || (coordinates[1] < '1') ||
      (coordinates[1] > '8')) {
    std::stringstream error_msg;
    error_msg << "Invalid coordinates: " << coordinates << "!";
    throw std::invalid_argument(error_msg.str());
  }

  this->row = kChessBoardRows - static_cast<int>(coordinates[1] - '0');
  this->col = static_cast<int>(coordinates[0] - 'A');
}

Position &Position::operator=(const std::string &coordinates) {
  Position temp{coordinates};
  swap(temp);
  return *this;
}

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

void Position::swap(Position &other) {
  std::swap(this->row, other.row);
  std::swap(this->col, other.col);
}

}  // namespace piece
}  // namespace chess
