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
   *
   * \exception std::out_of_range Row and/or column is outside valid range.
   */
  Position(int row, int col);

  /**
   * \brief Construct a new position from string representation.
   *
   * \param[in] coordinates String representation of Position.
   *
   * \exception std::invalid_argument Invalid string representation.
   */
  Position(const std::string &coordinates);

  /**
   * \brief Assign a new position from string representation.
   *
   * \param[in] coordinates String representation of position to assign.
   *
   * \exception std::invalid_argument Invalid string representation.
   *
   * \return Reference to the updated position.
   */
  Position &operator=(const std::string &coordinates);

  /**
   * \brief Check if two positions are equal.
   *
   * \param[in] other Position to compare against.
   *
   * \return True if positions are equal, false otherwise.
   */
  bool operator==(const Position &other) const;

  /**
   * \brief Check if two positions are not equal.
   *
   * \param[in] other Position to compare against.
   *
   * \return True if positions are different, false otherwise.
   */
  bool operator!=(const Position &other) const;

  /**
   * \brief Convert position to string representation (e.g. E4)
   *
   * \return String representation of the chess position.
   */
  operator std::string() const;

  int row_; /**< Chessboard row */
  int col_; /**< Chessboard column */

 protected:
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
