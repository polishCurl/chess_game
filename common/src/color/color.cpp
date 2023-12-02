#include "src/color/color.hpp"

namespace chess {

namespace common {

std::ostream &operator<<(std::ostream &out, Color color) {
  switch (color) {
    case Color::Black:
      return out << "black";
    case Color::White:
      return out << "white";
    default:
      return out << "Invalid color!";
  }
}

}  // namespace common
}  // namespace chess
