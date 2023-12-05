#ifndef CHESS_COMMON_SRC_MOVE_HPP_
#define CHESS_COMMON_SRC_MOVE_HPP_

#include <cstddef>
#include <iostream>
#include <vector>

#include "src/color/color.hpp"
#include "src/position/position.hpp"

namespace chess {

namespace common {

struct Move {
  static bool isDiagonal(const Move &move);
  static bool isForward(const Move &move, Color color);
  static bool isBackward(const Move &move, Color color);
  static bool isSide(const Move &move);
  static bool isByOne(const Move &move);
  static bool isPawnStartingMove(const Move &move, Color color);
  static bool isKnightMove(const Move &move);
  static Move revert(const Move &move);
  static std::vector<Position> getIntermediatePositions(const Move &move);

  Position curr_;
  Position next_;
};

}  // namespace common
}  // namespace chess

#endif  // CHESS_COMMON_SRC_MOVE_HPP_
