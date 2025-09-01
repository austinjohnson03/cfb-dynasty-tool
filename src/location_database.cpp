#include "location_database.h"
#include "database.h"
#include "utils.h"

#include <stdexcept>
#include <algorithm>
#include <utility>

LocationDatabase::LocationDatabase(Database& db) : db(db) {}

std::string LocationDatabase::make_key(const std::string& city, const std::string& state) const {
  return Utils::to_lower(Utils::trim(city)) + ", " 
    + Utils::to_lower(Utils::trim(state));
}

std::string LocationDatabase::make_key(const Location& loc) const {
  return Utils::to_lower(Utils::trim(loc.get_city())) +
    ", " + Utils::to_lower(Utils::trim(loc.get_state_str()));
}

void LocationDatabase::create_location_table() {
  try {

    const std::string query = R"(
    CREATE TABLE IF NOT EXISTS locations (
      id INTEGER PRIMARY KEY,
      city VARCHAR(30) NOT NULL,
      state VARCHAR(3) NOT NULL
    );
  )";
    db.execute(query, {});
    Utils::log(Utils::LogLevel::INFO, "Locations table successfully created.");
  } catch (const std::exception& e) {
    Utils::log(Utils::LogLevel::ERROR, 
        std::string("Failed to create locations table: ") + e.what());
  }
}

void LocationDatabase::load_all() {
  try {
    create_location_table();

    locations.clear();
    location_index.clear();
    next_id = 1;

    db.query("SELECT id, city, state FROM locations;", {}, 
        [this](const std::vector<std::string>& row) {
        if (row.size() < 3) return;
        uint32_t id = static_cast<uint32_t>(std::stoi(row[0]));
        std::string city = row[1];
        std::string state = row[2];

        auto entry = std::make_unique<LocationEntry>();
        entry->loc = std::make_unique<Location>(city, state);

        locations[id] = std::move(entry);
        location_index[make_key(city, state)] = id;

        if (id >= next_id) next_id = id + 1;
        });
    Utils::log(Utils::LogLevel::INFO, "All locations loaded successfully.");
  } catch (const std::exception& e) {
    Utils::log(Utils::LogLevel::ERROR,
        std::string("Failed to load locations: ") + e.what()
        );
  }
}

Location* LocationDatabase::get_location(uint32_t id) {
  auto it = locations.find(id);

  if (it != locations.end()) return it->second->loc.get();

  return nullptr;
}

Location* LocationDatabase::get_location(
    const std::string& city, 
    const std::string& state
    ) {
  auto it = location_index.find(make_key(city, state));
  if (it != location_index.end()) {
    return get_location(it->second);
  }

  return nullptr;
}

std::optional<uint32_t> LocationDatabase::find_id(
    const std::string& city, const std::string& state
    ) const {
  auto it = location_index.find(make_key(city, state));
  if (it != location_index.end()) return it->second;
  return std::nullopt;
}

uint32_t LocationDatabase::add_location(
    const std::string& city, 
    const std::string& state
    ) {
  try {
    auto key = make_key(city, state);
    auto existing = location_index.find(key);
    if (existing != location_index.end()) return existing->second;

    uint32_t id = next_id++;
    auto entry = std::make_unique<LocationEntry>();
    entry->loc = std::make_unique<Location>(city, state);

    locations[id] = std::move(entry);
    location_index[key] = id;

    db.execute(R"(
  INSERT INTO locations (id, city, state) VALUES (?, ?, ?);
  )", {std::to_string(id), city, state});

    Utils::log(Utils::LogLevel::INFO, "Added location: " + city + ", " 
        + state + " (ID: " + std::to_string(id) + ")");
    return id;
  } catch (const std::exception& e) {
    Utils::log(Utils::LogLevel::ERROR, "Failed to add location '" + city + ", " 
        + state + "': " + e.what());
    throw;
  }
}

void LocationDatabase::delete_location(uint32_t id) {
  auto it = locations.find(id);

  if (it == locations.end()) {
    Utils::log(Utils::LogLevel::WARNING,
        "Attempted to delete non-existent location with ID: " 
        + std::to_string(id)
        );
    return;
  }

  try {
    it->second->notify_delete();  // Nullify all owner pointers
    auto city_state = make_key(*it->second->loc);
    location_index.erase(city_state);
    locations.erase(it);

    db.execute("DELETE FROM locations WHERE id = ?;", {std::to_string(id)});
    Utils::log(Utils::LogLevel::INFO, 
        "Deleted location with ID: " + std::to_string(id) 
        + " (" + city_state + ")"
        );
  } catch (const std::exception& e) {
    Utils::log(Utils::LogLevel::ERROR, "Failed to delete location with ID '" 
        + std::to_string(id) + "': " + e.what()
        );
    throw;
  }
}

void LocationDatabase::register_owner_callback(
    uint32_t id, 
    std::function<void()> cb
    ) {
  auto it = locations.find(id);
  if (it != locations.end()) {
    it->second->nullify_callbacks.push_back(std::move(cb));
    Utils::log(
        Utils::LogLevel::INFO, 
        "Registered owner callback for location ID: " + std::to_string(id)
        );
  } else {
    Utils::log(
        Utils::LogLevel::WARNING,
        "Attempted to register owner callback for non-existent location ID: " 
        + std::to_string(id)
        );
  }
}
