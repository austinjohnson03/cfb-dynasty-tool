#include "dev_trait.h"
#include <gtest/gtest.h>

TEST(dev_trait_test, operator_test) {
  EXPECT_TRUE(DevTrait::UNKNOWN < DevTrait::NORMAL);
  EXPECT_TRUE(DevTrait::IMPACT <= DevTrait::IMPACT);
  EXPECT_TRUE(DevTrait::ELITE >= DevTrait::STAR);
}

TEST(dev_trait_test, dev_trait_to_string_test) {
  EXPECT_EQ(dev_trait_to_string(DevTrait::NORMAL), "Normal");
  EXPECT_EQ(dev_trait_to_string(DevTrait::UNKNOWN), "Unknown");
  EXPECT_EQ(dev_trait_to_string(DevTrait::STAR), "Star");
}

TEST(dev_trait_test, dev_trait_from_string_test) {
  EXPECT_EQ(dev_trait_from_string("Normal"), DevTrait::NORMAL);
  EXPECT_EQ(dev_trait_from_string("???"), DevTrait::UNKNOWN);
  EXPECT_EQ(dev_trait_from_string("     Star         "), DevTrait::STAR);
}

TEST(dev_trait_test, dev_trait_is_valid_test) {
  EXPECT_TRUE(dev_trait_is_valid(DevTrait::NORMAL));
  EXPECT_TRUE(dev_trait_is_valid(DevTrait::ELITE));
  EXPECT_FALSE(dev_trait_is_valid(DevTrait::UNKNOWN));
}
