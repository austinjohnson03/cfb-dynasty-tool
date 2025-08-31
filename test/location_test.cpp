#include "location.h"
#include "state.h"

#include <gtest/gtest.h>

class LocationTest : public ::testing::Test {
  protected:
    Location l1;
    Location l2;
    Location l3;
    void SetUp() override {
      l1 = Location("New York", State::NY);
      l2 = Location("New York", State::NY);
      l3 = Location("Albany", State::NY);
    }
};

TEST_F(LocationTest, operator_test) {
  EXPECT_TRUE(l1 == l2);
  EXPECT_TRUE(l1 != l3);
  EXPECT_TRUE(l2 != l3);
}

TEST(location_test, ConstructorWithEnum) {
  Location loc("Los Angeles", State::CA);

  EXPECT_EQ(loc.get_city(), "Los Angeles");
  EXPECT_EQ(loc.get_state(), State::CA);
}

TEST(location_test, ConstructorWithString) {
  Location loc("New York", "NY");

  EXPECT_EQ(loc.get_city(), "New York");
  EXPECT_EQ(loc.get_state(), State::NY);
}

TEST(location_test, SettersAndGetters) {
  Location loc; // Test empty setter

  loc.set_city("Chicago");
  EXPECT_EQ(loc.get_city(), "Chicago");

  loc.set_state(State::IL);
  EXPECT_EQ(loc.get_state(), State::IL);

  loc.set_state("CA");
  EXPECT_EQ(loc.get_state(), State::CA);

  loc.set_id(42);
  EXPECT_EQ(loc.get_id(), 42);
}

TEST(location_test, InternationalTest) {
  Location loc("Paris", "INT");

  EXPECT_EQ(loc.get_city(), "Paris");
  EXPECT_EQ(loc.get_state(), State::INT);
}

TEST(location_test, TestUnknown) {
  Location loc("Miami", "Gibberish");

  EXPECT_EQ(loc.get_state(), State::UNK);
}

TEST(location_test, ToString) {
  Location loc("Austin", State::TX);
  EXPECT_EQ(loc.to_string(), "Austin, TX");
}
