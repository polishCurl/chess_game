#ifndef CHESS_LOGGER_SRC_TIME_TIME_HPP_
#define CHESS_LOGGER_SRC_TIME_TIME_HPP_

#include <string>

#include "src/time/itime.hpp"

namespace chess {

namespace logger {

class Time : public ITime {
 public:
  Time();
  operator std::string() const override;

 protected:
  int hour_;
  int min_;
  int sec_;
  int ms_;
};

}  // namespace logger
}  // namespace chess

#endif  // CHESS_LOGGER_SRC_TIME_TIME_HPP_
