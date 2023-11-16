#ifndef CHESS_GAME_PIECE_SRC_PIECE_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_HPP_

#include "src/piece_utilities/move.hpp"

namespace chess {

namespace piece {

class Piece {
 public:
  virtual Position getPosition() const = 0;
  virtual bool canMove(const Position& next) const = 0;
  virtual bool move(const Position& next) const = 0;
  virtual bool hasBeenMoved() const = 0;
  virtual const char* getName() const = 0;
  virtual Color getColor() const = 0;

  virtual ~Piece() = default;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_HPP_
