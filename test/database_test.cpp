#include <gtest/gtest.h>
#include "database.h"

class DatabaseTest : public ::testing::Test {
protected:
    Database db{":memory:"}; // in-memory DB

    void SetUp() override {
        db.execute(
            "CREATE TABLE players ("
            "id INTEGER PRIMARY KEY,"
            "first_name TEXT,"
            "last_name TEXT);"
        );
    }
};

TEST_F(DatabaseTest, InsertAndSelectTest) {
    db.execute(
        "INSERT INTO players (id, first_name, last_name) VALUES (?, ?, ?);",
        {"1", "Austin", "Johnson"}
    );

    bool found = false;
    db.query(
        "SELECT id, first_name, last_name FROM players WHERE id=?;",
        {"1"},
        [&](const std::vector<std::string>& row) {
            EXPECT_EQ(row[0], "1");
            EXPECT_EQ(row[1], "Austin");
            EXPECT_EQ(row[2], "Johnson");
            found = true;
        }
    );

    EXPECT_TRUE(found);
}

TEST_F(DatabaseTest, UpdateTest) {
    db.execute(
        "INSERT INTO players (id, first_name, last_name) VALUES (?, ?, ?);",
        {"2", "John", "Doe"}
    );

    db.execute(
        "UPDATE players SET last_name=? WHERE id=?;",
        {"Smith", "2"}
    );

    db.query(
        "SELECT last_name FROM players WHERE id=?;",
        {"2"},
        [&](const std::vector<std::string>& row) {
            EXPECT_EQ(row[0], "Smith");
        }
    );
}

TEST_F(DatabaseTest, MultipleRowsTest) {
    db.execute(
        "INSERT INTO players (id, first_name, last_name) VALUES (?, ?, ?);",
        {"3", "Alice", "Wonder"}
    );
    db.execute(
        "INSERT INTO players (id, first_name, last_name) VALUES (?, ?, ?);",
        {"4", "Bob", "Builder"}
    );

    std::vector<std::string> names;
    db.query(
        "SELECT first_name FROM players ORDER BY id;",
        {},
        [&](const std::vector<std::string>& row) {
            names.push_back(row[0]);
        }
    );

    EXPECT_EQ(names.size(), 2);
    EXPECT_EQ(names[0], "Alice");
    EXPECT_EQ(names[1], "Bob");
}
