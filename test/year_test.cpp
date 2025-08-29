#include <gtest/gtest.h>
#include "year.h"

TEST(YearTest, ToStringBasic) {
  EXPECT_EQ(to_string(Year::FR), "FR");
  EXPECT_EQ(to_string(Year::HS), "HS");
  EXPECT_EQ(to_string(Year::JR), "JR");
  EXPECT_EQ(to_string(Year::UNK), "UNK");
}

TEST(YearTest, FromStringBasic) {
  EXPECT_EQ(year_from_string("fr"), Year::FR);
  EXPECT_EQ(year_from_string("HS"), Year::HS);
  EXPECT_EQ(year_from_string("Sr"), Year::SR);
  EXPECT_EQ(year_from_string("??"), Year::UNK);
}
