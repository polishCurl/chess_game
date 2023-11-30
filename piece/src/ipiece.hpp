#ifndef CHESS_GAME_PIECE_SRC_IPIECE_HPP_
#define CHESS_GAME_PIECE_SRC_IPIECE_HPP_

#include "src/piece_utilities/move.hpp"
#include "src/piece_utilities/position.hpp"

namespace chess {

namespace piece {

enum class PieceType { kPawn, kKnight, kBishop, kRook, kQueen, kKing };

class IPiece {
 public:
  IPiece() = default;
  IPiece(const IPiece&) = delete;
  IPiece& operator=(const IPiece&) = delete;
  IPiece(IPiece&&) = default;
  IPiece& operator=(IPiece&&) = default;

  virtual ~IPiece() = default;
  virtual Position getPosition() const = 0;
  virtual bool canMove(const Position& next) const = 0;
  virtual bool move(const Position& next) = 0;
  virtual bool hasBeenMoved() const = 0;
  virtual const char* getName() const = 0;
  virtual Color getColor() const = 0;
  virtual PieceType getType() const = 0;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_IPIECE_HPP_
