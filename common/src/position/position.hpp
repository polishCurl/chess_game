#ifndef CHESS_COMMON_SRC_POSITION_HPP_
#define CHESS_COMMON_SRC_POSITION_HPP_

#include <cstddef>
#include <string>

namespace chess {

namespace common {

constexpr int kChessBoardRows{8};
constexpr int kChessBoardCols{8};

class Position {
 public:
  Position() = delete;
  Position(int row, int col);
  Position(const std::string &coordinates);
  Position &operator=(const std::string &coordinates);
  bool operator==(const Position &other) const;
  bool operator!=(const Position &other) const;
  operator std::string() const;

  friend struct Move;

 private:
  int row_;
  int col_;

 private:
  void swap(Position &other);
};

}  // namespace common
}  // namespace chess

#endif  // CHESS_COMMON_SRC_POSITION_HPP_
