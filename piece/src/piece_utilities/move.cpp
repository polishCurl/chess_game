#include "move.hpp"

#include <cmath>

namespace chess {

namespace piece {

constexpr int kChessBoardRows{8};
constexpr int kChessBoardCols{8};
const Position kNoDistance{0, 0};

bool Move::isWithinChessBoard(const Position &pos) {
  return (pos.col < kChessBoardCols) && (pos.row < kChessBoardRows) &&
         (pos.col >= 0) && (pos.row >= 0);
}

bool Move::isDiagonal(const Position &prev, const Position &next) {
  if (prev == next) {
    return false;
  }
  const auto dist = next - prev;
  return std::abs(dist.row) == std::abs(dist.col);
}

bool Move::isForward(const Position &prev, const Position &next, Color color) {
  const auto dist = next - prev;
  return (dist.col == 0) && (((dist.row > 0) && (color == Color::Black)) ||
                             ((dist.row < 0) && (color == Color::White)));
}

bool Move::isBackward(const Position &prev, const Position &next, Color color) {
  const auto dist = next - prev;
  return (dist.col == 0) && (((dist.row < 0) && (color == Color::Black)) ||
                             ((dist.row > 0) && (color == Color::White)));
}

bool Move::isSide(const Position &prev, const Position &next) {
  const auto dist = next - prev;
  return dist.row == 0 && dist.col != 0;
}

bool Move::isByOne(const Position &prev, const Position &next) {
  const auto dist = next - prev;
  return (abs(dist.row) <= 1) && (abs(dist.col) <= 1) && (dist != kNoDistance);
}

}  // namespace piece
}  // namespace chess
