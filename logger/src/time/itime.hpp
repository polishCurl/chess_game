#ifndef CHESS_LOGGER_SRC_TIME_ITIME_HPP_
#define CHESS_LOGGER_SRC_TIME_ITIME_HPP_

#include <string>

namespace chess {

namespace logger {

class ITime {
 public:
  virtual ~ITime() = default;
  virtual operator std::string() const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const ITime& time) {
  out << std::string{time};
  return out;
}

}  // namespace logger
}  // namespace chess

#endif  // CHESS_LOGGER_SRC_TIME_ITIME_HPP_
