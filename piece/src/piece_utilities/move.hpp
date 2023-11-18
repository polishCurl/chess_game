#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_

#include <cstddef>

#include "src/piece_utilities/position.hpp"

namespace chess {

namespace piece {

enum class Color { Black, White };

class Move {
 public:
  static bool isDiagonal(const Position &prev, const Position &next);
  static bool isForward(const Position &prev, const Position &next,
                        Color color);
  static bool isBackward(const Position &prev, const Position &next,
                         Color color);
  static bool isSide(const Position &prev, const Position &next);
  static bool isByOne(const Position &prev, const Position &next);
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_MOVE_HPP_
