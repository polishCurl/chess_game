#ifndef CHESS_PIECE_SRC_PIECE_HPP_
#define CHESS_PIECE_SRC_PIECE_HPP_

#include "src/ipiece.hpp"

namespace chess {

namespace piece {

class Piece : public IPiece {
 public:
  Piece(const chess::common::Position& position, chess::common::Color color);
  chess::common::Position getPosition() const override;
  bool hasBeenMoved() const override;
  chess::common::Color getColor() const override;

 protected:
  chess::common::Position position_;
  const chess::common::Color color_;
  bool has_been_moved_;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_PIECE_HPP_
