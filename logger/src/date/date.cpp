#include "logger/src/date/date.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

namespace chess {

namespace logger {

Date::Date() {
  time_t now{time(0)};
  const auto local_time = localtime(&now);
  day_ = local_time->tm_mday;
  month_ = 1 + local_time->tm_mon;
  year_ = 1900 + local_time->tm_year;
}

Date::operator std::string() const {
  std::stringstream ss;
  ss.fill('0');
  ss << year_ << '/' << std::setw(2) << month_ << '/' << std::setw(2) << day_;
  return ss.str();
}

}  // namespace logger
}  // namespace chess
