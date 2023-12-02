#ifndef CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_
#define CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_

#include "src/ipiece.hpp"

namespace chess {

namespace piece {

class IPieceFactory {
 public:
  virtual ~IPieceFactory() = default;
  virtual std::unique_ptr<IPiece> create(
      PieceType type, const chess::common::Position& position,
      chess::common::Color color) const = 0;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_
