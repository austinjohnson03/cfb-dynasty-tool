#pragma once

#include "state.h"
#include <string>
#include <cstdint>

class Location {
  public:
    Location() : id(0), city(""), state(State::UNK) {}
    Location(std::string city, State state);
    Location(std::string city, std::string state_str);

    uint32_t get_id() const;
    void set_id(uint32_t id);

    std::string get_city() const;
    void set_city(std::string city);

    State get_state() const;
    void set_state(State state);
    void set_state(std::string state);

    std::string to_string() const;

    bool operator==(const Location& other) const {
      return city == other.get_city() &&
        state == other.get_state();
    }

    bool operator!=(const Location& other) const {
      return !(*this == other);
    }

  private:
    uint32_t id;
    std::string city;
    State state;
};
