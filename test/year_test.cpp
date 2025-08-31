#include <gtest/gtest.h>
#include "year.h"

TEST(year_test, ToStringBasic) {
  EXPECT_EQ(year_to_string(Year::FR), "FR");
  EXPECT_EQ(year_to_string(Year::HS), "HS");
  EXPECT_EQ(year_to_string(Year::JR), "JR");
  EXPECT_EQ(year_to_string(Year::UNK), "UNK");
}

TEST(year_test, FromStringBasic) {
  EXPECT_EQ(year_from_string("fr"), Year::FR);
  EXPECT_EQ(year_from_string("HS"), Year::HS);
  EXPECT_EQ(year_from_string("Sr"), Year::SR);
  EXPECT_EQ(year_from_string("??"), Year::UNK);
}

TEST(year_test, is_valid_test) {
  EXPECT_TRUE(is_valid_year(Year::HS));
  EXPECT_TRUE(is_valid_year(Year::SO));
  EXPECT_FALSE(is_valid_year(Year::UNK));
}
