#ifndef CHESS_GAME_PIECE_SRC_KING_HPP_
#define CHESS_GAME_PIECE_SRC_KING_HPP_

#include "src/piece.hpp"

namespace chess {

namespace piece {

class King : public Piece {
 public:
  King(const Position& position, Color color);
  King(const King&) = delete;
  King operator=(const King&) = delete;

  bool canMove(const Position& next) const override;
  bool move(const Position& next) override;
  const char* getName() const override;
  PieceType getType() const override;

 private:
  static constexpr char kName[]{"King"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_KING_HPP_
