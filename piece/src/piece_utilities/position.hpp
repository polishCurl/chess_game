#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_

#include <cstddef>

namespace chess {

namespace piece {

struct Position {
  Position() = delete;
  Position(int row, int col);
  Position operator+(const Position &other) const;
  Position operator-(const Position &other) const;
  bool operator==(const Position &other) const;
  bool operator!=(const Position &other) const;

  int row;
  int col;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
