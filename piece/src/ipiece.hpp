#ifndef CHESS_PIECE_SRC_IPIECE_HPP_
#define CHESS_PIECE_SRC_IPIECE_HPP_

#include <iostream>

#include "common/src/move/move.hpp"

namespace chess {

namespace piece {

/**
 * \brief Represents a chess piece type.
 */
enum class PieceType { kPawn, kKnight, kBishop, kRook, kQueen, kKing };

/**
 * \brief Chess piece interface
 */
class IPiece {
 public:
  IPiece() = default;
  IPiece(const IPiece&) = delete;
  IPiece& operator=(const IPiece&) = delete;
  IPiece(IPiece&&) = default;
  IPiece& operator=(IPiece&&) = default;

  virtual ~IPiece() = default;

  /**
   * \brief Get current chess piece position.
   *
   * \return Current piece Position.
   */
  virtual chess::common::Position getPosition() const = 0;

  /**
   * \brief Check if the chess piece can move to a new position.
   *
   * \param[in] next Position to move the piece to.
   *
   * \return True if the piece can be moved to the new position, false
   * otherwise.
   */
  virtual bool canMove(const chess::common::Position& next) const = 0;

  /**
   * \brief Check if the chess piece can move to a new position.
   *
   * \param[in] next Position to move the piece to.
   *
   * \return True if the piece can be moved to the new position, false
   * otherwise.
   */
  virtual bool move(const chess::common::Position& next) = 0;

  /**
   * \brief Check if the chess piece has been moved at least once.
   *
   * \return True if the piece has been moved, false otherwise.
   */
  virtual bool hasBeenMoved() const = 0;

  /**
   * \brief Get the chess piece name.
   *
   * \return piece name
   */
  virtual const char* getName() const = 0;

  /**
   * \brief Get the chess piece color.
   *
   * \return piece color
   */
  virtual chess::common::Color getColor() const = 0;

  /**
   * \brief Get the chess piece type.
   *
   * \return piece type
   */
  virtual PieceType getType() const = 0;

  /**
   * \brief Check if the chess piece can jump over other pieces.
   *
   * \return  True if the piece cannot collide with other pieces, false
   * otherwise.
   */
  virtual bool canJump() const = 0;

  friend std::ostream& operator<<(std::ostream& out, const IPiece& piece);
};

}  // namespace piece
}  // namespace chess

#endif  // CHESS_PIECE_SRC_IPIECE_HPP_
