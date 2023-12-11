#ifndef CHESS_COMMON_SRC_COLOR_HPP_
#define CHESS_COMMON_SRC_COLOR_HPP_

#include <iostream>

namespace chess {

namespace common {

/**
 * \brief Represents a chess color
 *
 * The color is an attribute of a chess player or a chess piece.
 */
enum class Color { Black, White };

std::ostream &operator<<(std::ostream &out, Color color);

}  // namespace common
}  // namespace chess

#endif  // CHESS_COMMON_SRC_COLOR_HPP_
