#include "move.hpp"

#include <cmath>

namespace chess {

namespace piece {

const Position kNoDistance{0, 0};

bool Move::isWithinChessBoard(const Position &pos) {
  return (pos.col_ < kChessBoardCols) && (pos.row_ < kChessBoardRows) &&
         (pos.col_ >= 0) && (pos.row_ >= 0);
}

bool Move::isDiagonal(const Position &prev, const Position &next) {
  if (prev == next) {
    return false;
  }
  const auto dist = next - prev;
  return std::abs(dist.row_) == std::abs(dist.col_);
}

bool Move::isForward(const Position &prev, const Position &next, Color color) {
  const auto dist = next - prev;
  return (dist.col_ == 0) && (((dist.row_ > 0) && (color == Color::Black)) ||
                              ((dist.row_ < 0) && (color == Color::White)));
}

bool Move::isBackward(const Position &prev, const Position &next, Color color) {
  const auto dist = next - prev;
  return (dist.col_ == 0) && (((dist.row_ < 0) && (color == Color::Black)) ||
                              ((dist.row_ > 0) && (color == Color::White)));
}

bool Move::isSide(const Position &prev, const Position &next) {
  const auto dist = next - prev;
  return dist.row_ == 0 && dist.col_ != 0;
}

bool Move::isByOne(const Position &prev, const Position &next) {
  const auto dist = next - prev;
  return (abs(dist.row_) <= 1) && (abs(dist.col_) <= 1) &&
         (dist != kNoDistance);
}

}  // namespace piece
}  // namespace chess
