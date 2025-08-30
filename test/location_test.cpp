#include "location.h"
#include "state.h"

#include <gtest/gtest.h>

TEST(LocationTest, ConstructorWithEnum) {
  Location loc("Los Angeles", State::CA);

  EXPECT_EQ(loc.get_city(), "Los Angeles");
  EXPECT_EQ(loc.get_state(), State::CA);
}

TEST(LocationTest, ConstructorWithString) {
  Location loc("New York", "NY");

  EXPECT_EQ(loc.get_city(), "New York");
  EXPECT_EQ(loc.get_state(), State::NY);
}

TEST(LocationTest, SettersAndGetters) {
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

TEST(LocationTest, InternationalTest) {
  Location loc("Paris", "INT");

  EXPECT_EQ(loc.get_city(), "Paris");
  EXPECT_EQ(loc.get_state(), State::INT);
}

TEST(LocationTest, TestUnknown) {
  Location loc("Miami", "Gibberish");

  EXPECT_EQ(loc.get_state(), State::UNK);
}

TEST(LocationTest, ToString) {
    Location loc("Austin", State::TX);
    EXPECT_EQ(loc.to_string(), "Austin, TX");
}
