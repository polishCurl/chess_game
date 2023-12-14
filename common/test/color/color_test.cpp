#include "common/src/color/color.hpp"

#include "gtest/gtest.h"

using namespace chess::common;

TEST(ColorTest, StreamInsertionWhite) {
  std::stringstream ss;
  ss << Color::White;
  EXPECT_EQ(ss.str(), "white");
}

TEST(ColorTest, StreamInsertionBlack) {
  std::stringstream ss;
  ss << Color::Black;
  EXPECT_EQ(ss.str(), "black");
}

TEST(ColorTest, StreamInsertionInvalidColor) {
  std::stringstream ss;
  ss << static_cast<Color>(3);
  EXPECT_EQ(ss.str(), "Invalid color!");
}
