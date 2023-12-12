#ifndef CHESS_BOARD_SRC_ICHESSBOARD_HPP_
#define CHESS_BOARD_SRC_ICHESSBOARD_HPP_

#include "common/src/color/color.hpp"
#include "common/src/move/move.hpp"
#include "piece/src/ipiece.hpp"

namespace chess {

namespace board {

/**
 * \brief Chessboard interface.
 */
class IChessboard {
 public:
  IChessboard() = default;
  IChessboard(const IChessboard&) = delete;
  IChessboard& operator=(const IChessboard&) = delete;
  IChessboard(IChessboard&&) = delete;
  IChessboard& operator=(IChessboard&&) = delete;

  virtual ~IChessboard() = default;

  /**
   * \brief Reset chessboard to initial state.
   *
   * Puts the chess pieces in their starting positions.
   */
  virtual void reset() = 0;

  /**
   * \brief Get a chess piece at the given position.
   *
   * \param[in] position Position on the chessboard.
   *
   * \return Pointer to the chess piece if present, nullptr otherwise.
   */
  virtual const chess::piece::IPiece* getPiece(
      const chess::common::Position& position) = 0;

  /**
   * \brief Add a chess piece at the given position.
   *
   * \param[in] type Chess piece type.
   * \param[in] position Starting chess piece position.
   * \param[in] color Chess piece color.
   *
   * \return True if piece was added to the chessboard, false otherwise.
   */
  virtual bool addPiece(chess::piece::PieceType type,
                        chess::common::Color color,
                        const chess::common::Position& position) = 0;

  /**
   * \brief Remove a chess piece from the given position.
   *
   * \param[in] position Position on the chessboard.
   *
   * \return True if piece was removed from the chessboard, false otherwise.
   */
  virtual bool removePiece(const chess::common::Position& position) = 0;

  /**
   * \brief Move a chess piece on the chessboard.
   *
   * The move on the chessboard is made only if all the conditions below
   * are met:
   * 1. There is a piece at the move starting position.
   * 2. The piece at the starting position has the same color as the player
   * making the move.
   * 3. The piece at the starting position can make the move (assuming no other
   * pieces on chessboard).
   * 4. The piece to move does not collide with any other piece on the board or
   * the piece to move can jump over other pieces.
   * 5. The move target position is free or occupied by a piece of a different
   * color to the piece being moved (capture).
   *
   * \param[in] player_color Color of the player making the move.
   * \param[in] move Move to make.
   *
   * \return True if the move was successful, false otherwise.
   */
  virtual bool movePiece(chess::common::Color player_color,
                         const chess::common::Move& move) = 0;

  // TODO: Implement detection of check, checkmate and stalemate
  // virtual bool isKingInCheck(Color color) const;
  // virtual bool isKingCheckmated(Color color) const;
};

}  // namespace board
}  // namespace chess

#endif  // CHESS_BOARD_SRC_ICHESSBOARD_HPP_
