#ifndef CHESS_PIECE_SRC_PIECE_FACTORY_HPP_
#define CHESS_PIECE_SRC_PIECE_FACTORY_HPP_

#include "piece/src/piece_factory/ipiece_factory.hpp"

namespace chess {

namespace piece {

class PieceFactory : public IPieceFactory {
 public:
  std::unique_ptr<IPiece> create(PieceType type,
                                 const chess::common::Position& position,
                                 chess::common::Color color) const override;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_PIECE_FACTORY_HPP_
