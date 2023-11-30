#ifndef CHESS_GAME_PIECE_SRC_IPIECE_FACTORY_HPP_
#define CHESS_GAME_PIECE_SRC_IPIECE_FACTORY_HPP_

#include "src/ipiece.hpp"

namespace chess {

namespace piece {

class IPieceFactory {
 public:
  virtual ~IPieceFactory() = default;
  virtual std::unique_ptr<IPiece> create(PieceType type,
                                         const Position& position,
                                         Color color) const = 0;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_IPIECE_FACTORY_HPP_
