#include "src/piece_utilities/position.hpp"

#include <cmath>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace chess {

namespace piece {

static void validateChessRows(int chess_board_rows) {
  constexpr int kMaxSupportedChessboardRows{12};
  if (chess_board_rows > kMaxSupportedChessboardRows) {
    std::stringstream error_msg;
    error_msg << "Invalid number (" << chess_board_rows
              << ") of chessboard rows! Max supported: "
              << kMaxSupportedChessboardRows;
    throw std::invalid_argument(error_msg.str());
  }
}

static void validateChessCols(int chess_board_cols) {
  constexpr int kMaxSupportedChessboardCols{12};
  if (chess_board_cols > kMaxSupportedChessboardCols) {
    std::stringstream error_msg;
    error_msg << "Invalid number (" << chess_board_cols
              << ") of chessboard columns! Max supported: "
              << kMaxSupportedChessboardCols;
    throw std::invalid_argument(error_msg.str());
  }
}

Position::Position(int row, int col, int chess_board_rows, int chess_board_cols)
    : row_{row},
      col_{col},
      chess_board_rows_{chess_board_rows},
      chess_board_cols_{chess_board_cols} {
  validateChessRows(chess_board_rows);
  validateChessCols(chess_board_cols);

  if ((col_ < 0) || (row_ < 0) || (col_ >= chess_board_cols_) ||
      (row_ >= chess_board_rows_)) {
    std::stringstream error_msg;
    error_msg << "Invalid position! (" << row_ << ',' << col_ << ")";
    throw std::invalid_argument(error_msg.str());
  }
}

Position::Position(const std::string &coordinates, int chess_board_rows,
                   int chess_board_cols)
    : chess_board_rows_{chess_board_rows}, chess_board_cols_{chess_board_cols} {
  validateChessRows(chess_board_rows);
  validateChessCols(chess_board_cols);

  if ((coordinates.size() < 2) || (coordinates[0] < 'A') ||
      (coordinates[0] >= ('A' + chess_board_cols_)) || (coordinates[1] < '1') ||
      (coordinates[1] >= ('1' + chess_board_rows_))) {
    std::stringstream error_msg;
    error_msg << "Invalid coordinates: " << coordinates << "!";
    throw std::invalid_argument(error_msg.str());
  }

  this->row_ = chess_board_rows_ - static_cast<int>(coordinates[1] - '0');
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
  const char row = static_cast<char>(chess_board_rows_ - row_) + '0';
  const char col = 'A' + static_cast<char>(col_);
  return {std::string(1, col) + row};
}

void Position::swap(Position &other) {
  std::swap(this->row_, other.row_);
  std::swap(this->col_, other.col_);
}

}  // namespace piece
}  // namespace chess
