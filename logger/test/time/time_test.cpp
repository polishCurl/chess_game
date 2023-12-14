#include "logger/src/time/time.hpp"

#include <regex>

#include "gtest/gtest.h"

using namespace chess::logger;

TEST(TimeTest, DefaultConstructor) { EXPECT_NO_THROW(Time{}); }

TEST(DateTest, PrintFormat) {
  Time time{};
  std::cout << "[          ] Current time: " << time << '\n';
  EXPECT_TRUE(std::regex_match(std::string{time},
                               std::regex("\\d{2}:\\d{2}:\\d{2}.\\d{3}")));
}
