#ifndef CHESS_COMMON_SRC_POSITION_HPP_
#define CHESS_COMMON_SRC_POSITION_HPP_

#include <cstddef>
#include <functional>
#include <string>

namespace chess {

namespace common {

constexpr int kChessBoardRows{8}; /**< Number of chessboard rows */
constexpr int kChessBoardCols{8}; /**< Number of chessboard columns */

/**
 * \brief Represents a chess positions on a 2D grid.
 */
class Position {
 public:
  Position() = delete;

  /**
   * \brief Construct a new position.
   *
   * \param[in] row Position row.
   * \param[in] col Position column.
   */
  Position(int row, int col);

  /**
   * \brief Construct a new position from string representation.
   *
   * \param[in] coordinates Position string representation.
   */
  Position(const std::string &coordinates);

  /**
   * \brief Assign a new position from string representation.
   *
   * \param[in] coordinates String representation of position to assign.
   *
   * \return Reference to the updated position.
   */
  Position &operator=(const std::string &coordinates);

  /**
   * \brief Check if two positions are equal.
   *
   * \param[in] Position to compare against.
   *
   * \return True if positions are equal, false otherwise.
   */
  bool operator==(const Position &other) const;

  /**
   * \brief Check if two positions are not equal.
   *
   * \param[in] Position to compare against.
   *
   * \return True if positions are different, false otherwise.
   */
  bool operator!=(const Position &other) const;

  /**
   * \brief Convert position to string representation (e.g. E4)
   *
   * \return String representing the chess position.
   */
  operator std::string() const;

  int row_; /**< Chessboard row */
  int col_; /**< Chessboard column */

 protected:
  /**
   * \brief Swap the position value with another one.
   *
   * \param[in] Position to swap with against.
   */
  void swap(Position &other);
};

}  // namespace common
}  // namespace chess

template <>
struct std::hash<chess::common::Position> {
  /**
   * \brief Hash operator for Position.
   *
   * \param[in] position Position to hash.
   *
   * \return Hash value of position.
   */
  std::size_t operator()(const chess::common::Position &position) const {
    return ((std::hash<int>()(position.row_) ^
             (std::hash<int>()(position.col_) << 1)) >>
            1);
  }
};

#endif  // CHESS_COMMON_SRC_POSITION_HPP_
