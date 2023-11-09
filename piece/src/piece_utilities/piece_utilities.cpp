#include "piece_utilities.hpp"

namespace chess {

namespace piece {

constexpr std::size_t kChessBoardRows{8};
constexpr std::size_t kChessBoardCols{8};

Position Position::operator+(Position const &other) const {
  return {row + other.row, col + other.col};
}

Position Position::operator-(Position const &other) const {
  return {row - other.row, col - other.col};
}

bool isWithinChessBoard(Position const &pos) {
  return (pos.col < kChessBoardCols) && (pos.row < kChessBoardRows);
}

bool isDiagonalMove(Position const &prev, Position const &next) { return {}; }

bool isForwardMove(Position const &prev, Position const &next) { return {}; }

bool isBackwardMove(Position const &prev, Position const &next) { return {}; }

bool isSideMove(Position const &prev, Position const &next) {
  Position diff = next - prev;
  return !diff.row != !diff.col;
}

bool isMoveByOne(Position const &prev, Position const &next) { return {}; }

}  // namespace piece
}  // namespace chess
