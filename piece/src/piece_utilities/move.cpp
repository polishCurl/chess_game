#include "move.hpp"

#include <cmath>

namespace chess {

namespace piece {

const Position kNoDistance{0, 0};

bool Move::isDiagonal(const Position &curr, const Position &next) {
  if (curr == next) {
    return false;
  }
  const auto row_diff = std::abs(next.row_ - curr.row_);
  const auto col_diff = std::abs(next.col_ - curr.col_);
  return row_diff == col_diff;
}

bool Move::isForward(const Position &curr, const Position &next, Color color) {
  const auto row_diff = next.row_ - curr.row_;
  const auto col_diff = next.col_ - curr.col_;
  return (col_diff == 0) && (((row_diff > 0) && (color == Color::Black)) ||
                             ((row_diff < 0) && (color == Color::White)));
}

bool Move::isBackward(const Position &curr, const Position &next, Color color) {
  const auto row_diff = next.row_ - curr.row_;
  const auto col_diff = next.col_ - curr.col_;
  return (col_diff == 0) && (((row_diff < 0) && (color == Color::Black)) ||
                             ((row_diff > 0) && (color == Color::White)));
}

bool Move::isSide(const Position &curr, const Position &next) {
  const auto row_diff = next.row_ - curr.row_;
  const auto col_diff = next.col_ - curr.col_;
  return (row_diff == 0) && (col_diff != 0);
}

bool Move::isByOne(const Position &curr, const Position &next) {
  const auto row_diff = std::abs(next.row_ - curr.row_);
  const auto col_diff = std::abs(next.col_ - curr.col_);
  return (row_diff <= 1) && (col_diff <= 1) && (curr != next);
}

bool Move::isPawnStartingMove(const Position &curr, const Position &next,
                              Color color) {
  const auto row_diff = std::abs(next.row_ - curr.row_);
  return isForward(curr, next, color) && (row_diff == 2);
}

bool Move::isKnightMove(const Position &curr, const Position &next) {
  const auto row_diff = std::abs(next.row_ - curr.row_);
  const auto col_diff = std::abs(next.col_ - curr.col_);
  return ((row_diff == 1) && (col_diff == 2)) ||
         ((row_diff == 2) && (col_diff == 1));
}

}  // namespace piece
}  // namespace chess
