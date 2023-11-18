#ifndef CHESS_GAME_PIECE_SRC_QUEEN_HPP_
#define CHESS_GAME_PIECE_SRC_QUEEN_HPP_

#include "src/piece.hpp"

namespace chess {

namespace piece {

class Queen : public Piece {
 public:
  Queen(const Position& position, Color color);
  bool canMove(const Position& next) const override;
  bool move(const Position& next) override;
  const char* getName() const override;

 private:
  static constexpr char kName[]{"Queen"};
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_QUEEN_HPP_
