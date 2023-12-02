#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_COLOR_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_COLOR_HPP_

#include <iostream>

namespace chess {

namespace piece {

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

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_COLOR_HPP_
