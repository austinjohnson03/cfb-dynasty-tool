#include "location.h"
#include <utility>

Location::Location(std::string city, State state)
  : city(std::move(city)), state(state) {}

Location::Location(std::string city, std::string state_str)
  : city(std::move(city)), state(state_from_string(state_str)) {}


uint32_t Location::get_id() const { return id; }

void Location::set_id(uint32_t id) {
  this->id = id;
}

std::string Location::get_city() const { return city; }

void Location::set_city(std::string city) {
  this->city = std::move(city);
}

State Location::get_state() const { return state; }

std::string Location::get_state_str() const { return state_to_string(state); }

void Location::set_state(State state) {
  this->state = state;
}

void Location::set_state(std::string state) {
  this->state = state_from_string(state);
}

std::string Location::to_string() const {
  return city + ", " + state_to_string(state);
}
