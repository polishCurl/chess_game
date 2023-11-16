#include "move.hpp"

#include <cmath>

namespace chess {

namespace piece {

const Position kNoDistance{0, 0};

bool Move::isDiagonal(const Position &prev, const Position &next) {
  if (prev == next) {
    return false;
  }
  const auto row_diff = std::abs(next.row_ - prev.row_);
  const auto col_diff = std::abs(next.col_ - prev.col_);
  return row_diff == col_diff;
}

bool Move::isForward(const Position &prev, const Position &next, Color color) {
  const auto row_diff = next.row_ - prev.row_;
  const auto col_diff = next.col_ - prev.col_;
  return (col_diff == 0) && (((row_diff > 0) && (color == Color::Black)) ||
                             ((row_diff < 0) && (color == Color::White)));
}

bool Move::isSide(const Position &prev, const Position &next) {
  const auto row_diff = next.row_ - prev.row_;
  const auto col_diff = next.col_ - prev.col_;
  return (row_diff == 0) && (col_diff != 0);
}

bool Move::isByOne(const Position &prev, const Position &next) {
  const auto row_diff = std::abs(next.row_ - prev.row_);
  const auto col_diff = std::abs(next.col_ - prev.col_);
  return (row_diff <= 1) && (col_diff <= 1) && (prev != next);
}

}  // namespace piece
}  // namespace chess
