#include "common/src/color/color.hpp"

#include "gtest/gtest.h"

using namespace chess::common;

TEST(ColorTest, StreamInsertion) {
  EXPECT_EQ((std::stringstream{} << Color::White).str(), "white");
  EXPECT_EQ((std::stringstream{} << Color::Black).str(), "black");
  EXPECT_EQ((std::stringstream{} << static_cast<Color>(3)).str(),
            "Invalid color!");
}
