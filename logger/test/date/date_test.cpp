#include "logger/src/date/date.hpp"

#include <regex>

#include "gtest/gtest.h"

using namespace chess::logger;

TEST(DateTest, DefaultConstructor) { EXPECT_NO_THROW(Date{}); }

TEST(DateTest, PrintFormat) {
  Date date{};
  std::cout << "[          ] Current date: " << date << '\n';
  EXPECT_TRUE(
      std::regex_match(std::string{date}, std::regex("\\d{4}/\\d{2}/\\d{2}")));
}
