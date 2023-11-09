#ifndef CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_

#include <cstddef>

namespace chess {

namespace piece {

struct Position {
  Position() = delete;
  Position(std::size_t row, std::size_t col);
  Position operator+(Position const &other) const;
  Position operator-(Position const &other) const;

  std::size_t row;
  std::size_t col;
};

bool isWithinChessBoard(Position const &pos);
bool isDiagonalMove(Position const &prev, Position const &next);
bool isForwardMove(Position const &prev, Position const &next);
bool isBackwardMove(Position const &prev, Position const &next);
bool isSideMove(Position const &prev, Position const &next);
bool isMoveByOne(Position const &prev, Position const &next);

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_UTILITIES_HPP_
