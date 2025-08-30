#include "poll_type.h"

#include <gtest/gtest.h>

TEST(poll_type_test, operator_tests) {
  EXPECT_TRUE(PollType::AP < PollType::USA_TODAY);
  EXPECT_TRUE(PollType::USA_TODAY <= PollType::USA_TODAY);
  EXPECT_FALSE(PollType::CFP < PollType::USA_TODAY);
}

TEST(poll_type_test, poll_to_string_test) {
  EXPECT_EQ(poll_type_to_string(PollType::AP), "AP");
  EXPECT_EQ(poll_type_to_string(PollType::USA_TODAY), "USA Today");
  EXPECT_EQ(poll_type_to_string(PollType::CFP), "CFP");
  EXPECT_EQ(poll_type_to_string(PollType::ERR), "ERR");
}

TEST(poll_type_test, poll_type_to_full_name_test) {
  EXPECT_EQ(poll_type_to_full_name(PollType::AP), "AP Media Poll");
  EXPECT_EQ(poll_type_to_full_name(PollType::USA_TODAY), "USA Today Coaches Poll");
  EXPECT_EQ(poll_type_to_full_name(PollType::CFP), "College Football Playoff Rankings");
  EXPECT_EQ(poll_type_to_full_name(PollType::ERR), "Error");
}

TEST(poll_type_test, poll_type_from_string_test)  {
  EXPECT_EQ(poll_type_from_string("  ap    "), PollType::AP);
  EXPECT_EQ(poll_type_from_string("???"), PollType::ERR);
  EXPECT_EQ(poll_type_from_string("usa ToDay"), PollType::USA_TODAY);
  EXPECT_EQ(poll_type_from_string("college football playoff Rankings"), PollType::CFP);
}

TEST(poll_type_test, poll_type_is_valid_test) {
  EXPECT_TRUE(is_valid_poll_type(PollType::AP));
  EXPECT_TRUE(is_valid_poll_type(PollType::USA_TODAY));
  EXPECT_FALSE(is_valid_poll_type(PollType::ERR));
}
