#include <gtest/gtest.h>
#include "state.h"
#include <unordered_map>

TEST(StateTest, ToStringBasic) {
    EXPECT_EQ(state_to_string(State::TX), "TX");
    EXPECT_EQ(state_to_string(State::CA), "CA");
    EXPECT_EQ(state_to_string(State::UNK), "UNK");
}

TEST(StateTest, FromStringBasic) {
    EXPECT_EQ(state_from_string("TX"), State::TX);
    EXPECT_EQ(state_from_string("ca"), State::CA);
    EXPECT_EQ(state_from_string("invalid"), State::UNK);
}

TEST(StateTest, FromFullNameBasic) {
    EXPECT_EQ(state_from_full_name("Texas"), State::TX);
    EXPECT_EQ(state_from_full_name("District of Columbia"), State::DC);
    EXPECT_EQ(state_from_full_name("NotAState"), State::UNK);
}

TEST(StateTest, FullNameBasic) {
    EXPECT_EQ(full_name(State::TX), "Texas");
    EXPECT_EQ(full_name(State::CA), "California");
    EXPECT_EQ(full_name(State::UNK), "Unknown");
}

TEST(StateTest, ValidCheck) {
    EXPECT_TRUE(is_valid_state(State::TX));
    EXPECT_TRUE(is_valid_state(State::CA));
    EXPECT_FALSE(is_valid_state(State::UNK));
}

TEST(StateTest, HashSupport) {
    std::unordered_map<State, std::string> state_map;
    state_map[State::TX] = "Texas";
    state_map[State::CA] = "California";
    state_map[State::UNK] = "Unknown";

    EXPECT_EQ(state_map[State::TX], "Texas");
    EXPECT_EQ(state_map[State::CA], "California");
    EXPECT_EQ(state_map[State::UNK], "Unknown");
}
