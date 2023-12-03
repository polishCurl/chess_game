#ifndef CHESS_LOGGER_SRC_DATE_IDATE_HPP_
#define CHESS_LOGGER_SRC_DATE_IDATE_HPP_

#include <string>

namespace chess {

namespace logger {

class IDate {
 public:
  virtual ~IDate() = default;
  virtual operator std::string() const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const IDate& date) {
  out << std::string{date};
  return out;
}

}  // namespace logger
}  // namespace chess

#endif  // CHESS_LOGGER_SRC_DATE_IDATE_HPP_
