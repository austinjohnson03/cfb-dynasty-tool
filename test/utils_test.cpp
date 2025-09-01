#include "utils.h"
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <cctype>

bool is_valid_timestamp(const std::string& s) {
  if (s.size() < 19) return false;
  for (int i = 0; i < 19; ++i) {
    if (i == 4 || i == 7) {
      if (s[i] != '-') return false;
    } else if (i == 10) {
      if (s[i] != ' ') return false;
    } else if (i == 13 || i == 16) {
      if (s[i] != ':') return false;
    } else {
      if (!std::isdigit(s[i])) return false;
    }
  }
  return true;
}

TEST(utils_test, log_with_timestamp_test) {
    const std::string test_file = "logs/test_log_timestamp.txt";

    if (std::filesystem::exists(test_file)) {
        std::filesystem::remove(test_file);
    }

    Utils::log(Utils::LogLevel::INFO, "Timestamp test message", test_file);

    std::ifstream in(test_file);
    ASSERT_TRUE(in.is_open());

    std::string line;
    bool found_timestamp = false;

    while (std::getline(in, line)) {
        if (line.find("[INFO] Timestamp test message") != std::string::npos) {
            found_timestamp = is_valid_timestamp(line.substr(1, 19)); // Skip '['
        }
    }

    EXPECT_TRUE(found_timestamp);

    in.close();

    std::filesystem::remove(test_file);
}

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
