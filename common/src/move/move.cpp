#include "common/src/move/move.hpp"

#include <cmath>

namespace chess {

namespace common {

const Position kNoDistance{0, 0};

bool Move::isDiagonal(const Move &move) {
  if (move.curr_pos_ == move.next_pos_) {
    return false;
  }
  const auto row_diff = std::abs(move.next_pos_.row_ - move.curr_pos_.row_);
  const auto col_diff = std::abs(move.next_pos_.col_ - move.curr_pos_.col_);
  return row_diff == col_diff;
}

bool Move::isForward(const Move &move, Color color) {
  const auto row_diff = move.next_pos_.row_ - move.curr_pos_.row_;
  const auto col_diff = move.next_pos_.col_ - move.curr_pos_.col_;
  return (col_diff == 0) && (((row_diff > 0) && (color == Color::Black)) ||
                             ((row_diff < 0) && (color == Color::White)));
}

bool Move::isBackward(const Move &move, Color color) {
  const auto row_diff = move.next_pos_.row_ - move.curr_pos_.row_;
  const auto col_diff = move.next_pos_.col_ - move.curr_pos_.col_;
  return (col_diff == 0) && (((row_diff < 0) && (color == Color::Black)) ||
                             ((row_diff > 0) && (color == Color::White)));
}

bool Move::isSide(const Move &move) {
  const auto row_diff = move.next_pos_.row_ - move.curr_pos_.row_;
  const auto col_diff = move.next_pos_.col_ - move.curr_pos_.col_;
  return (row_diff == 0) && (col_diff != 0);
}

bool Move::isByOne(const Move &move) {
  const auto row_diff = std::abs(move.next_pos_.row_ - move.curr_pos_.row_);
  const auto col_diff = std::abs(move.next_pos_.col_ - move.curr_pos_.col_);
  return (row_diff <= 1) && (col_diff <= 1) &&
         (move.curr_pos_ != move.next_pos_);
}

bool Move::isPawnStartingMove(const Move &move, Color color) {
  const auto row_diff = std::abs(move.next_pos_.row_ - move.curr_pos_.row_);
  return isForward(move, color) && (row_diff == 2);
}

bool Move::isKnightMove(const Move &move) {
  const auto row_diff = std::abs(move.next_pos_.row_ - move.curr_pos_.row_);
  const auto col_diff = std::abs(move.next_pos_.col_ - move.curr_pos_.col_);
  return ((row_diff == 1) && (col_diff == 2)) ||
         ((row_diff == 2) && (col_diff == 1));
}

Move Move::revert(const Move &move) { return {move.next_pos_, move.curr_pos_}; }

std::vector<Position> Move::getIntermediatePositions(const Move &move) {
  std::vector<Position> intermediate_positions{};

  const auto row_diff = move.next_pos_.row_ - move.curr_pos_.row_;
  const auto col_diff = move.next_pos_.col_ - move.curr_pos_.col_;

  auto getIncrementValue = [](int diff) {
    if (diff == 0) {
      return 0;
    } else if (diff < 0) {
      return -1;
    } else {
      return 1;
    }
  };

  const auto row_step = getIncrementValue(row_diff);
  const auto col_step = getIncrementValue(col_diff);

  for (int i = 1; i <= std::max(std::abs(row_diff), std::abs(col_diff)) - 1;
       i++) {
    intermediate_positions.push_back({move.curr_pos_.row_ + (i * row_step),
                                      move.curr_pos_.col_ + (i * col_step)});
  }

  return intermediate_positions;
}

}  // namespace common
}  // namespace chess
