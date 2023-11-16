#ifndef CHESS_GAME_PIECE_SRC_IPIECE_HPP_
#define CHESS_GAME_PIECE_SRC_IPIECE_HPP_

#include "src/piece_utilities/move.hpp"
#include "src/piece_utilities/position.hpp"

namespace chess {

namespace piece {

class IPiece {
 public:
  virtual Position getPosition() const = 0;
  virtual bool canMove(const Position& next) const = 0;
  virtual bool move(const Position& next) = 0;
  virtual bool hasBeenMoved() const = 0;
  virtual const char* getName() const = 0;
  virtual Color getColor() const = 0;

  virtual ~IPiece() = default;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_IPIECE_HPP_
