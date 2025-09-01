#include <gtest/gtest.h>

#include "location.h"
#include "stadium.h"



class StadiumTest : public ::testing::Test {
  protected:
    Location loc1{"Miami Gardens", "FL"};
    Location loc2{"Auburn", "AL"};
    Location loc3{"Honolulu", "HI"};
    Stadium s1;
    Stadium s2;
    Stadium s3;
    void SetUp() override {
      s1 = Stadium(1, "Hard Rock Stadium", &loc1, 65326, 1987, TurfType::TURF);
      s2 = Stadium(
          2, 
          "Jordan-Hare Stadium", 
          "Pat Dye Field at Jordan-Hare Stadium",
          &loc2, 
          88043, 
          1939, 
          TurfType::GRASS
          );
      s3 = Stadium();
    }
};

TEST_F(StadiumTest, comparison_test) {
  EXPECT_TRUE(s1 == s1);
  EXPECT_TRUE(s1 != s2);
  EXPECT_FALSE(s2 == s3);
}

TEST_F(StadiumTest, id_test) {
  EXPECT_EQ(s1.get_id(), 1);
  s1.set_id(4);
  EXPECT_EQ(s1.get_id(), 4);
  EXPECT_EQ(s3.get_id(), 0);
  s3.set_id(5);
  EXPECT_EQ(s3.get_id(), 5);
}

TEST_F(StadiumTest, name_test) {
  EXPECT_EQ(s1.get_short_name(), s1.get_full_name());
  s1.set_short_name("    Pitbull Stadium     ");
  EXPECT_EQ(s1.get_short_name(), "Pitbull Stadium");
  EXPECT_EQ(s2.get_full_name(), "Pat Dye Field at Jordan-Hare Stadium");
  s2.set_full_name("      Jordan-Hare Stadium    ");
  EXPECT_EQ(s2.get_full_name(), s2.get_short_name());
}

TEST_F(StadiumTest, location_test) {
  EXPECT_EQ(*s1.get_location(), loc1);
  s1.set_location(&loc3);
  EXPECT_EQ(*s1.get_location(), loc3);
}

TEST_F(StadiumTest, capacity_test) {
  EXPECT_EQ(s1.get_capacity(), 65326);
  s1.set_capacity(60000);
  EXPECT_EQ(s1.get_capacity(), 60000);
}

TEST_F(StadiumTest, year_built_test) {
  EXPECT_EQ(s1.get_year_built(), 1987);
  s1.set_year_built(1989);
  EXPECT_EQ(s1.get_year_built(), 1989);
}

TEST_F(StadiumTest, surface_type_test) {
  EXPECT_EQ(s1.get_surface_type(), TurfType::TURF);
  s1.set_surface_type("   grass   ");
  EXPECT_EQ(s1.get_surface_type(), TurfType::GRASS);
  s1.set_surface_type(TurfType::HYBRID);
  EXPECT_EQ(s1.get_surface_type(), TurfType::HYBRID);
}

