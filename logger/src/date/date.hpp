#ifndef CHESS_LOGGER_SRC_DATE_DATE_HPP_
#define CHESS_LOGGER_SRC_DATE_DATE_HPP_

#include <string>

#include "src/date/idate.hpp"

namespace chess {

namespace logger {

class Date : public IDate {
 public:
  Date();
  operator std::string() const override;

 protected:
  int day_;
  int month_;
  int year_;
};

}  // namespace logger
}  // namespace chess

#endif  // CHESS_LOGGER_SRC_DATE_IDATE_HPP_
