#ifndef CHESS_COMMON_SRC_MOVE_HPP_
#define CHESS_COMMON_SRC_MOVE_HPP_

#include <cstddef>
#include <iostream>
#include <vector>

#include "common/src/color/color.hpp"
#include "common/src/position/position.hpp"

namespace chess {

namespace common {

/**
 * \brief Represents a move between two chess positions.
 */
struct Move {
  /**
   * \brief Check if the given move is diagonal.
   *
   * \param[in] move Move to check.
   *
   * \return True if move is diagonal, false otherwise.
   */
  static bool isDiagonal(const Move &move);

  /**
   * \brief Check if the given move is forward.
   *
   * \param[in] move Move to check.
   * \param[in] color Color of the piece being moved.
   *
   * \return True if move is forward, false otherwise.
   */
  static bool isForward(const Move &move, Color color);

  /**
   * \brief Check if the given move is backward.
   *
   * \param[in] move Move to check.
   * \param[in] color Color of the piece being moved.
   *
   * \return True if move is backward, false otherwise.
   */
  static bool isBackward(const Move &move, Color color);

  /**
   * \brief Check if the given move is to the side (left or right).
   *
   * \param[in] move Move to check.
   *
   * \return True if move is a side move, false otherwise.
   */
  static bool isSide(const Move &move);

  /**
   * \brief Check if the given move is by one position (in distance).
   *
   * \param[in] move Move to check.
   *
   * \return True if move has a distance of one, false otherwise
   */
  static bool isByOne(const Move &move);

  /**
   * \brief Check if the given move is forward by two positions.
   *
   * \param[in] move Move to check.
   * \param[in] color Pawn's color.
   *
   * \return True if move is a valid first pawn move (by two positions forward),
   * false otherwise.
   */
  static bool isPawnStartingMove(const Move &move, Color color);

  /**
   * \brief Check if the given move is a valid knight move.
   *
   * \param[in] move Move to check.
   *
   * \return True if move is a valid knight move, false otherwise.
   */
  static bool isKnightMove(const Move &move);

  /**
   * \brief Revert a given move.
   *
   * The current and next position in the input move are swapped.
   *
   * \param[in] move Move to check.
   *
   * \return Reverted move.
   */
  static Move revert(const Move &move);

  /**
   * \brief Get the list of all intermediate positions for a move.
   *
   * \param[in] move Move to check.
   *
   * \return List of all intermediate positions between the current position and
   * the next position (non-inclusive).
   */
  static std::vector<Position> getIntermediatePositions(const Move &move);

  Position curr_pos_; /**< Current position */
  Position next_pos_; /**< Next position */
};

}  // namespace common
}  // namespace chess

#endif  // CHESS_COMMON_SRC_MOVE_HPP_
