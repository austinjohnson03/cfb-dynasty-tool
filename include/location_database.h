#pragma once 

#include "location.h"
#include "database.h"
#include "utils.h"
#include <unordered_map>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <cstdint>
#include <functional>

class LocationDatabase {
  public:
    explicit LocationDatabase(Database& db);
    ~LocationDatabase() = default;

    void create_location_table();

    void load_all();

    Location* get_location(uint32_t id);
    Location* get_location(const std::string& city, const std::string& state);
    std::optional<uint32_t> find_id(
        const std::string& city, 
        const std::string& state
    ) const;

    uint32_t add_location(const std::string& city, const std::string& state);

    void delete_location(uint32_t id);

    void register_owner_callback(uint32_t id, std::function<void()> cb);

  private:
    Database& db;
   
    struct LocationEntry {
      std::unique_ptr<Location> loc;

      // Owners of location entry for delete 
      std::vector<std::function<void()>> nullify_callbacks; 

      void notify_delete() {
        for (auto& cb : nullify_callbacks) {
          cb();
        }
        nullify_callbacks.clear();
      }
    };

    std::unordered_map<uint32_t, std::unique_ptr<LocationEntry>> locations;
    std::unordered_map<std::string, uint32_t> location_index;
    uint32_t next_id = 1;

    std::string make_key(
        const std::string& city, 
        const std::string& state
    ) const;
    std::string make_key(const Location& loc) const;
};
