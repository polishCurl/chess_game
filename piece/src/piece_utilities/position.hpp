#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_

#include <cstddef>
#include <string>

namespace chess {

namespace piece {

class Position {
 public:
  Position() = delete;
  Position(int row, int col, int chess_board_rows = 8,
           int chess_board_cols = 8);
  Position(const std::string &coordinates, int chess_board_rows = 8,
           int chess_board_cols = 8);
  Position &operator=(const std::string &coordinates);
  bool operator==(const Position &other) const;
  bool operator!=(const Position &other) const;
  operator std::string() const;

  friend struct Move;

 private:
  int row_;
  int col_;
  int chess_board_rows_;
  int chess_board_cols_;

 private:
  void swap(Position &other);
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
