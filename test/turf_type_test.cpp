#include "turf_type.h"

#include <gtest/gtest.h>

TEST(turf_type_test, comparison_operators_test) {
  EXPECT_TRUE(TurfType::GRASS < TurfType::TURF);
  EXPECT_TRUE(TurfType::TURF <= TurfType::TURF);
  EXPECT_FALSE(TurfType::TURF <= TurfType::UNKNOWN);
}

TEST(turf_type_test, turf_type_to_string_test) {
  EXPECT_EQ(turf_type_to_string(TurfType::GRASS), "Grass");
  EXPECT_EQ(turf_type_to_string(TurfType::TURF), "Turf");
  EXPECT_EQ(turf_type_to_string(TurfType::UNKNOWN), "Unknown");
}

TEST(turf_type_test, turf_type_from_string_test) {
  EXPECT_EQ(turf_type_from_string("    grAss     "), TurfType::GRASS);
  EXPECT_EQ(turf_type_from_string("TURF"), TurfType::TURF);
  EXPECT_EQ(turf_type_from_string("?????"), TurfType::UNKNOWN);
}
