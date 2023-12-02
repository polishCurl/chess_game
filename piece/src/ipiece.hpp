#ifndef CHESS_PIECE_SRC_IPIECE_HPP_
#define CHESS_PIECE_SRC_IPIECE_HPP_

#include <iostream>

#include "common/src/move/move.hpp"

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
  virtual chess::common::Position getPosition() const = 0;
  virtual bool canMove(const chess::common::Position& next) const = 0;
  virtual bool move(const chess::common::Position& next) = 0;
  virtual bool hasBeenMoved() const = 0;
  virtual const char* getName() const = 0;
  virtual chess::common::Color getColor() const = 0;
  virtual PieceType getType() const = 0;

  friend std::ostream& operator<<(std::ostream& out, const IPiece& piece);
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_IPIECE_HPP_
