#include "src/position/position.hpp"

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace chess {

namespace piece {

Position::Position(int row, int col) : row_{row}, col_{col} {
  if ((col_ < 0) || (row_ < 0) || (col_ >= kChessBoardCols) ||
      (row_ >= kChessBoardRows)) {
    std::stringstream error_msg;
    error_msg << "Invalid position! (" << row_ << ',' << col_ << ")";
    throw std::invalid_argument(error_msg.str());
  }
}

Position::Position(const std::string &coordinates) {
  if ((coordinates.size() != 2) || (coordinates[0] < 'A') ||
      (coordinates[0] > 'H') || (coordinates[1] < '1') ||
      (coordinates[1] > '8')) {
    std::stringstream error_msg;
    error_msg << "Invalid coordinates: " << coordinates << "!";
    throw std::invalid_argument(error_msg.str());
  }

  this->row_ = kChessBoardRows - static_cast<int>(coordinates[1] - '0');
  this->col_ = static_cast<int>(coordinates[0] - 'A');
}

Position &Position::operator=(const std::string &coordinates) {
  Position temp{coordinates};
  swap(temp);
  return *this;
}

bool Position::operator==(const Position &other) const {
  return (row_ == other.row_) && (col_ == other.col_);
}

bool Position::operator!=(const Position &other) const {
  return (row_ != other.row_) || (col_ != other.col_);
}

Position::operator std::string() const {
  const char row = static_cast<char>(kChessBoardRows - row_) + '0';
  const char col = 'A' + static_cast<char>(col_);
  return {std::string(1, col) + row};
}

void Position::swap(Position &other) {
  std::swap(this->row_, other.row_);
  std::swap(this->col_, other.col_);
}

}  // namespace piece
}  // namespace chess
