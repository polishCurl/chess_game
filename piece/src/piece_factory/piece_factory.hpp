#ifndef CHESS_GAME_PIECE_SRC_PIECE_FACTORY_HPP_
#define CHESS_GAME_PIECE_SRC_PIECE_FACTORY_HPP_

#include "src/piece_factory/ipiece_factory.hpp"

namespace chess {

namespace piece {

class PieceFactory : public IPieceFactory {
 public:
  std::unique_ptr<IPiece> create(PieceType type, const Position& position,
                                 Color color) const override;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_GAME_PIECE_SRC_PIECE_FACTORY_HPP_
