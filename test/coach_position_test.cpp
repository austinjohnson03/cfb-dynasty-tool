#include "coach_position.h"

#include <gtest/gtest.h>

TEST(coach_position_test, operator_tests) {
  EXPECT_TRUE(CoachPosition::HC < CoachPosition::OC);
  EXPECT_TRUE(CoachPosition::OC >= CoachPosition::OC);
  EXPECT_TRUE(CoachPosition::HC <= CoachPosition::DC);
}

TEST(coach_position_test, coach_pos_to_string_test) {
  EXPECT_EQ(coach_position_to_string(CoachPosition::HC), "HC");
  EXPECT_EQ(coach_position_to_string(CoachPosition::OC), "OC");
  EXPECT_EQ(coach_position_to_string(CoachPosition::UE), "UE");
  EXPECT_EQ(coach_position_to_string(CoachPosition::UNDEFINED), "UND");
}

TEST(coach_position_test, position_to_full_name_test) {
  EXPECT_EQ(coach_position_to_full_name(CoachPosition::HC), "Head Coach");
  EXPECT_EQ(coach_position_to_full_name(CoachPosition::OC), "Offensive Coordinator");
  EXPECT_EQ(coach_position_to_full_name(CoachPosition::UE), "Unemployed");
  EXPECT_EQ(coach_position_to_full_name(CoachPosition::UNDEFINED), "Undefined");
}

TEST(coach_position_test, position_from_string_test) {
  EXPECT_EQ(position_from_string("  hc     "), CoachPosition::HC);
  EXPECT_EQ(position_from_string("   OfFenSive Coordinator   "), CoachPosition::OC);
  EXPECT_EQ(position_from_string("???"), CoachPosition::UNDEFINED);
}
