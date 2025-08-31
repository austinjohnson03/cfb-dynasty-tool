#include <gtest/gtest.h>

#include "player.h"
#include "archetype.h"
#include "position.h"
#include "year.h"
#include "location.h"
#include "dev_trait.h"

class PlayerTest : public ::testing::Test {
  protected:
    Player p1;
    Player p2;
    Player p3;
    void SetUp() override {
      p1 = Player(
          1,
          "John",
          "Doe",
          Position::QB,
          Archetype(ArchetypeType::POCKET_PASSER),
          Year::FR,
          true,
          74,
          225,
          Location("New York", State::NY),
          DevTrait::STAR
          );
      p2 = Player(
          1,
          "John",
          "Doe",
          Position::QB,
          Archetype(ArchetypeType::POCKET_PASSER),
          Year::FR,
          true,
          74,
          225,
          Location("New York", State::NY),
          DevTrait::STAR
          );
      p3 = Player(
          3,
          "John",
          "Deere",
          Position::QB,
          Archetype(ArchetypeType::POCKET_PASSER),
          Year::SO,
          true,
          74,
          225,
          Location("Los Angeles", State::CA),
          DevTrait::STAR
          );
    }
};

TEST_F(PlayerTest, comparison_test) {
  EXPECT_TRUE(p1 == p2);
  EXPECT_TRUE(p1 != p3);
  EXPECT_FALSE(p2 == p3);
}

TEST_F(PlayerTest, id_test) {
  EXPECT_EQ(p1.get_id(), 1);
  p1.set_id(7);
  EXPECT_EQ(p1.get_id(), 7);
}

TEST_F(PlayerTest, has_correct_first_name) {
  EXPECT_EQ(p1.get_first_name(), "John");
}

TEST_F(PlayerTest, has_correct_last_name) {
  EXPECT_EQ(p1.get_last_name(), "Doe");
}

TEST_F(PlayerTest, has_correct_full_name) {
  EXPECT_EQ(p1.get_full_name(), "John Doe");
}

TEST_F(PlayerTest, set_name_test) {
  p1.set_first_name("Nick");
  p1.set_last_name("Saban");

  EXPECT_EQ(p1.get_full_name(),"Nick Saban");
}

TEST_F(PlayerTest, position_test) {
  EXPECT_EQ(p1.get_position(), Position::QB);

  p1.set_position(Position::EDGE);

  EXPECT_EQ(p1.get_position(), Position::EDGE);

  p1.set_position("hb");

  EXPECT_EQ(p1.get_position(), Position::HB);

  p1.set_position("wide receiver");
  EXPECT_EQ(p1.get_position(), Position::WR);
}

TEST_F(PlayerTest, archetype_test) {
  EXPECT_EQ(p1.get_archetype(), Archetype(ArchetypeType::POCKET_PASSER));

  p1.set_archetype(ArchetypeType::GAP_SPECIALIST);
  EXPECT_EQ(p1.get_archetype(), Archetype(ArchetypeType::GAP_SPECIALIST));

  p1.set_archetype("north south reciever");  // misspelled on purpose
  EXPECT_EQ(p1.get_archetype(), Archetype(ArchetypeType::NORTH_SOUTH_RECEIVER));
}

TEST_F(PlayerTest, year_test) {
  EXPECT_EQ(p1.get_year(), Year::FR);
  EXPECT_EQ(p1.get_year_str(), "FR (RS)");

  p1.set_year(Year::JR);
  p1.set_redshirt(false);
  EXPECT_EQ(p1.get_year(), Year::JR);
  EXPECT_EQ(p1.get_year_str(), "JR");

  p1.set_year("???");
  EXPECT_EQ(p1.get_year(), Year::UNK);

  p1.set_year("sr");
  p1.set_redshirt(true);
  EXPECT_EQ(p1.get_year(), Year::SR);
  EXPECT_EQ(p1.get_year_str(), "SR (RS)");
}

TEST_F(PlayerTest, height_test) {
  EXPECT_EQ(p1.get_height(), 74);
  p1.set_height(62);
  EXPECT_EQ(p1.get_height(), 62);
  p1.set_height("6'0\"");
  EXPECT_EQ(p1.get_height(), 72);
  p1.set_height(74);
  EXPECT_EQ(p1.get_height_str(), "6' 2\"");

  p1.set_height(40);
  EXPECT_EQ(p1.get_height(), 48);
  p1.set_height("8'3\"");
  EXPECT_EQ(p1.get_height(), 90);
  EXPECT_EQ(p1.get_height_str(), "7' 6\"");
  p1.set_height(72);
}

TEST_F(PlayerTest, weight_test) {
  EXPECT_EQ(p1.get_weight(), 225);
  p1.set_weight(200);
  EXPECT_EQ(p1.get_weight(), 200);
  p1.set_weight(100);
  EXPECT_EQ(p1.get_weight(), 150);
  p1.set_weight(600);
  EXPECT_EQ(p1.get_weight(), 500);
  p1.set_weight(225);
}

TEST_F(PlayerTest, location_test) {
  EXPECT_EQ(p1.get_hometown(), Location("New York", State::NY));
  Location l1("Los Angeles", State::CA);
  p1.set_hometown(l1);
  EXPECT_EQ(p1.get_hometown(), l1);
  p1.set_hometown("Quebec", "INT");
  EXPECT_EQ(p1.get_hometown(), Location("Quebec", "INT"));
  p1.set_hometown("Los Angeles", State::CA);
  EXPECT_EQ(p1.get_hometown(), l1);
}

TEST_F(PlayerTest, dev_trait_test) {
  EXPECT_EQ(p1.get_dev_trait(), DevTrait::STAR);
  p1.set_dev_trait(DevTrait::NORMAL);
  EXPECT_EQ(p1.get_dev_trait(), DevTrait::NORMAL);
  p1.set_dev_trait("????");
  EXPECT_EQ(p1.get_dev_trait(), DevTrait::UNKNOWN);
  p1.set_dev_trait("Elite");
  EXPECT_EQ(p1.get_dev_trait(), DevTrait::ELITE);
}
