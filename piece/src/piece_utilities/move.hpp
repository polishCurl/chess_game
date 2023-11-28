#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_

#include <cstddef>

#include "src/piece_utilities/position.hpp"

namespace chess {

namespace piece {

enum class Color { Black, White };

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

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_
