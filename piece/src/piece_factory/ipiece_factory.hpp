#ifndef CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_
#define CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_

#include "piece/src/ipiece.hpp"

namespace chess {

namespace piece {

/**
 * \brief Chess piece factory interface.
 */
class IPieceFactory {
 public:
  virtual ~IPieceFactory() = default;

  /**
   * \brief Create a chess piece.
   *
   * \param[in] type Chess piece type.
   * \param[in] position Starting chess piece position.
   * \param[in] color Chess piece color.
   *
   * \return Owning pointer to the created chess piece.
   */
  virtual std::unique_ptr<IPiece> create(
      PieceType type, const chess::common::Position& position,
      chess::common::Color color) const = 0;
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_IPIECE_FACTORY_HPP_
