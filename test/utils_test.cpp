#include "utils.h"

#include <gtest/gtest.h>

TEST(utils_test, trim_test) {
  EXPECT_EQ(Utils::trim("     test    "), "test");
  EXPECT_EQ(Utils::trim("     test 3   "), "test 3");
  EXPECT_EQ(Utils::trim("  928409D^SAD78da7   \'    "), "928409D^SAD78da7   \'");
}

TEST(utils_test, to_upper_test) {
  EXPECT_EQ(Utils::to_upper("upper"), "UPPER");
  EXPECT_EQ(Utils::to_upper("upp3r"), "UPP3R");
  EXPECT_EQ(Utils::to_upper("433lll;]"), "433LLL;]");
}

TEST(utils_test, to_lower_test) {
  EXPECT_EQ(Utils::to_lower("LOWER"), "lower");
  EXPECT_EQ(Utils::to_lower("LOW3R"), "low3r");
  EXPECT_EQ(Utils::to_lower("433LLL;]"), "433lll;]");
}

TEST(utils_test, convert_height_str_test) {
  EXPECT_EQ(Utils::convert_height_str("6'4\""), 76);
  EXPECT_EQ(Utils::convert_height_str("6'11\""), 83);
  EXPECT_EQ(Utils::convert_height_str("04'04\""), 52);
}
