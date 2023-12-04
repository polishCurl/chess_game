#include "src/time/time.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace chess {

namespace logger {

Time::Time() {
  const auto system_time_now = std::chrono::system_clock::now();
  time_t time_now = std::chrono::system_clock::to_time_t(system_time_now);
  const auto local_time = localtime(&time_now);
  hour_ =
      local_time->tm_isdst == 0 ? local_time->tm_hour + 1 : local_time->tm_hour;
  min_ = local_time->tm_min;
  sec_ = local_time->tm_sec;
  ms_ = std::chrono::duration_cast<std::chrono::milliseconds>(
            system_time_now.time_since_epoch())
            .count() %
        1000;
}

Time::operator std::string() const {
  std::stringstream ss;
  ss.fill('0');
  ss << std::setw(2) << hour_ << ':' << std::setw(2) << min_ << ':'
     << std::setw(2) << sec_ << '.' << std::setw(3) << ms_;
  return ss.str();
}

}  // namespace logger
}  // namespace chess
