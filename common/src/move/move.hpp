#ifndef CHESS_COMMON_SRC_MOVE_HPP_
#define CHESS_COMMON_SRC_MOVE_HPP_

#include <cstddef>
#include <iostream>

#include "src/position/position.hpp"

namespace chess {

namespace common {

// TODO: Move Color to separate file
enum class Color { Black, White };

inline std::ostream &operator<<(std::ostream &out, Color color) {
  switch (color) {
    case Color::Black:
      return out << "black";
    case Color::White:
      return out << "white";
    default:
      return out << "Invalid color!";
  }
}

struct Move {
  static bool isDiagonal(const Move &move);
  static bool isForward(const Move &move, Color color);
  static bool isBackward(const Move &move, Color color);
  static bool isSide(const Move &move);
  static bool isByOne(const Move &move);
  static bool isPawnStartingMove(const Move &move, Color color);
  static bool isKnightMove(const Move &move);

  static Move revert(const Move &move);

  Position curr_;
  Position next_;
};

}  // namespace common
}  // namespace chess

#endif  // CHESS_COMMON_SRC_MOVE_HPP_
