#include <gtest/gtest.h>

#include "archetype.h"
#include "archetype_type.h"

class ArchetypeTest : public ::testing::Test {
  protected:
    Archetype a1;
    void SetUp() override {
      a1 = Archetype(ArchetypeType::BUMP_AND_RUN);
    }
};

TEST(archetype_type_test, archetype_type_to_string_test) {
  EXPECT_EQ(
      archetype_type_to_string(ArchetypeType::BACKFIELD_THREAT), "Backfield Threat"
      );
  EXPECT_EQ(archetype_type_to_string(ArchetypeType::UTILITY), "Utility");
  EXPECT_EQ(archetype_type_to_string(ArchetypeType::UNKNOWN), "Unknown");
}

TEST(archetype_type_test, archetype_type_is_valid_test) {
  EXPECT_TRUE(archetype_type_is_valid(ArchetypeType::BOX_SPECIALIST));
  EXPECT_TRUE(archetype_type_is_valid(ArchetypeType::POCKET_PASSER));
  EXPECT_FALSE(archetype_type_is_valid(ArchetypeType::UNKNOWN));
}

TEST(archetype_type_test, archetype_type_from_string_test) {
  EXPECT_EQ(archetype_type_from_string("BACKfield Creator"), ArchetypeType::BACKFIELD_CREATOR);
  EXPECT_EQ(archetype_type_from_string("    Gap SPECIALIST     "), ArchetypeType::GAP_SPECIALIST);
  EXPECT_EQ(archetype_type_from_string("???"), ArchetypeType::UNKNOWN);
}

TEST_F(ArchetypeTest, has_correct_name) {
  EXPECT_EQ(a1.get_name(), "Bump and Run");
}

TEST_F(ArchetypeTest, has_correct_archetype_type) {
  EXPECT_EQ(a1.get_archetype_type(), ArchetypeType::BUMP_AND_RUN);
}
