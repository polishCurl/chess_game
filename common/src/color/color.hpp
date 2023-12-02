#ifndef CHESS_COMMON_SRC_COLOR_HPP_
#define CHESS_COMMON_SRC_COLOR_HPP_

#include <iostream>

namespace chess {

namespace piece {

enum class Color { Black, White };

std::ostream &operator<<(std::ostream &out, Color color);

}  // namespace piece
}  // namespace chess

#endif  // CHESS_COMMON_SRC_COLOR_HPP_
