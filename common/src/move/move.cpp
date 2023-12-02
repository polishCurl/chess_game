#include "src/move/move.hpp"

#include <cmath>

namespace chess {

namespace piece {

const Position kNoDistance{0, 0};

bool Move::isDiagonal(const Move &move) {
  if (move.curr_ == move.next_) {
    return false;
  }
  const auto row_diff = std::abs(move.next_.row_ - move.curr_.row_);
  const auto col_diff = std::abs(move.next_.col_ - move.curr_.col_);
  return row_diff == col_diff;
}

bool Move::isForward(const Move &move, Color color) {
  const auto row_diff = move.next_.row_ - move.curr_.row_;
  const auto col_diff = move.next_.col_ - move.curr_.col_;
  return (col_diff == 0) && (((row_diff > 0) && (color == Color::Black)) ||
                             ((row_diff < 0) && (color == Color::White)));
}

bool Move::isBackward(const Move &move, Color color) {
  const auto row_diff = move.next_.row_ - move.curr_.row_;
  const auto col_diff = move.next_.col_ - move.curr_.col_;
  return (col_diff == 0) && (((row_diff < 0) && (color == Color::Black)) ||
                             ((row_diff > 0) && (color == Color::White)));
}

bool Move::isSide(const Move &move) {
  const auto row_diff = move.next_.row_ - move.curr_.row_;
  const auto col_diff = move.next_.col_ - move.curr_.col_;
  return (row_diff == 0) && (col_diff != 0);
}

bool Move::isByOne(const Move &move) {
  const auto row_diff = std::abs(move.next_.row_ - move.curr_.row_);
  const auto col_diff = std::abs(move.next_.col_ - move.curr_.col_);
  return (row_diff <= 1) && (col_diff <= 1) && (move.curr_ != move.next_);
}

bool Move::isPawnStartingMove(const Move &move, Color color) {
  const auto row_diff = std::abs(move.next_.row_ - move.curr_.row_);
  return isForward(move, color) && (row_diff == 2);
}

bool Move::isKnightMove(const Move &move) {
  const auto row_diff = std::abs(move.next_.row_ - move.curr_.row_);
  const auto col_diff = std::abs(move.next_.col_ - move.curr_.col_);
  return ((row_diff == 1) && (col_diff == 2)) ||
         ((row_diff == 2) && (col_diff == 1));
}

Move Move::revert(const Move &move) { return {move.next_, move.curr_}; }

}  // namespace piece
}  // namespace chess
