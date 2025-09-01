#include "location_database.h"
#include "database.h"
#include "utils.h"

#include <gtest/gtest.h>
#include <memory>

class LocationDatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        db = std::make_unique<Database>(":memory:");
        loc_db = std::make_unique<LocationDatabase>(*db);
        loc_db->create_location_table();
    }

    void TearDown() override {
        loc_db.reset();
        db.reset();
    }

    std::unique_ptr<Database> db;
    std::unique_ptr<LocationDatabase> loc_db;
};

TEST_F(LocationDatabaseTest, AddAndFindLocation) {
    unsigned int id = loc_db->add_location("Louisville", "KY");
    EXPECT_NE(id, 0);

    auto* loc = loc_db->get_location(id);
    ASSERT_NE(loc, nullptr);
    EXPECT_EQ(loc->get_city(), "Louisville");
    EXPECT_EQ(loc->get_state_str(), "KY");
}

TEST_F(LocationDatabaseTest, PreventsDuplicate) {
    unsigned int id1 = loc_db->add_location("Louisville", "KY");
    unsigned int id2 = loc_db->add_location("louisville", "ky"); // normalized

    EXPECT_EQ(id1, id2);
}

TEST_F(LocationDatabaseTest, DeleteLocationRemovesFromMemory) {
    unsigned int id = loc_db->add_location("Lexington", "KY");
    auto* loc = loc_db->get_location(id);
    ASSERT_NE(loc, nullptr);

    loc_db->delete_location(id);
    EXPECT_EQ(loc_db->get_location(id), nullptr);
}

