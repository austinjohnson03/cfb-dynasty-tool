#include "position.h"

#include<gtest/gtest.h>

TEST(position_test, position_to_string_test) {
  EXPECT_EQ(position_to_string(Position::QB), "QB");
  EXPECT_EQ(position_to_string(Position::HB), "HB");
  EXPECT_EQ(position_to_string(Position::EDGE), "EDGE");
  EXPECT_EQ(position_to_string(Position::UNDEFINED), "UND");
}

TEST(position_test, position_to_full_name_test) {
  EXPECT_EQ(position_to_full_name(Position::WR), "Wide Receiver");
  EXPECT_EQ(position_to_full_name(Position::CB), "Corner Back");
  EXPECT_EQ(position_to_full_name(Position::S), "Safety");
  EXPECT_EQ(position_to_full_name(Position::UNDEFINED), "Undefined");
}

TEST(position_test, position_from_string_test) {
  EXPECT_EQ(position_from_string("linebacker"), Position::LB);
  EXPECT_EQ(position_from_string("   center    "), Position::C);
  EXPECT_EQ(position_from_string("????"), Position::UNDEFINED);
}


TEST(position_test, is_valid_position_test) {
  EXPECT_TRUE(is_valid_position(Position::P));
  EXPECT_TRUE(is_valid_position(Position::DT));
  EXPECT_TRUE(is_valid_position(Position::OG));
  EXPECT_FALSE(is_valid_position(Position::UNDEFINED));
}
