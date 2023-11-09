#ifndef CHESS_GAME_PIECE_SRC_PIECE_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_HPP_

#include "piece_utilities/piece_utilities.hpp"

namespace chess {

namespace piece {

class Piece {
 public:
  virtual char getSymbol() const = 0;
  virtual Position getPosition() const = 0;
  virtual bool canMove(Position const& nextition) const = 0;
  virtual bool move(Position const& nextition) const = 0;
  virtual bool hasBeenMoved() const = 0;
  virtual ~Piece() = default;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_HPP_
