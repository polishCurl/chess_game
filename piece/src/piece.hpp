#ifndef CHESS_PIECE_SRC_PIECE_HPP_
#define CHESS_PIECE_SRC_PIECE_HPP_

#include "src/ipiece.hpp"

namespace chess {

namespace piece {

class Piece : public IPiece {
 public:
  Piece(const Position& position, Color color);
  Position getPosition() const override;
  bool hasBeenMoved() const override;
  Color getColor() const override;

 protected:
  Position position_;
  const Color color_;
  bool has_been_moved_;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_PIECE_HPP_
