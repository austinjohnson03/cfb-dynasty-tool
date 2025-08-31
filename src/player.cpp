#include "player.h"
#include "utils.h"
#include "year.h"
#include "position.h"
#include <algorithm>
#include <utility>
#include <iostream>

Player::Player() :
  id(0), first_name("Undefined"), last_name("Undefined"), position(Position::UNDEFINED),
  archetype(Archetype()), year(Year::UNK), redshirt(false), ht(48), wt(150),
  hometown(Location("New York", State::NY)), dev_trait(DevTrait::UNKNOWN) {}

Player::Player(
    unsigned int id,
    std::string first_name,
    std::string last_name,
    Position position,
    Archetype archetype,
    Year year,
    bool is_redshirt,
    int height,
    int weight,
    Location hometown,
    DevTrait dev_trait
    ) : 
  id(id),
  first_name(std::move(first_name)),
  last_name(std::move(last_name)),
  position(position),
  archetype(archetype),
  year(year),
  redshirt(is_redshirt),
  hometown(hometown),
  dev_trait(dev_trait),
  wt(std::clamp(weight, WEIGHT_MIN, WEIGHT_MAX)),
  ht(std::clamp(height, HEIGHT_MIN, HEIGHT_MAX)) {}


unsigned int Player::get_id() const { return id; }

void Player::set_id(unsigned int new_id) {
  this->id = new_id;
}

std::string Player::get_first_name() const { return first_name; }

void Player::set_first_name(std::string new_first) {
  this->first_name = std::move(new_first);
}

std::string Player::get_last_name() const { return last_name; }

void Player::set_last_name(std::string new_last) {
  this->last_name = std::move(new_last);
}

std::string Player::get_full_name() const { 
  return first_name + " " + last_name;
}

Position Player::get_position() const { return position; }

void Player::set_position(Position pos) { this->position = pos; }

void Player::set_position(std::string pos) {
  this->position = position_from_string(std::move(pos));
}

Archetype Player::get_archetype() const { return archetype; }

void Player::set_archetype(Archetype new_arch) {
  this->archetype = new_arch;
}

void Player::set_archetype(std::string new_arch) {
  this->archetype = archetype_type_from_string(new_arch);
}

Year Player::get_year() const { return year; }

void Player::set_year(Year new_year) {
  this->year = new_year;
}

void Player::set_year(std::string new_year) {
  this->year = year_from_string(std::move(new_year));
}

bool Player::is_redshirt() const { return redshirt; }

void Player::set_redshirt(bool is_redshirt) {
  this->redshirt = is_redshirt;
}

std::string Player::get_year_str() const {
  std::string year_str = year_to_string(this->year);
  if (!is_valid_year(this->year)) {
    return year_str;
  }
  return year_str + (this->redshirt ? " (RS)" : "");
}

int Player::get_height() const { return ht; }

std::string Player::get_height_str() {
  std::string ft = std::to_string(this->ht / 12);
  std::string in = std::to_string(this->ht % 12);
  return ft + "' " + in + "\"";
}


void Player::set_height(int new_height) {
  this->ht = std::clamp(new_height, HEIGHT_MIN, HEIGHT_MAX);
}

bool Player::set_height(std::string s) {
  try {
    int unclamped_ht = Utils::convert_height_str(s);
    this->ht = std::clamp(unclamped_ht, HEIGHT_MIN, HEIGHT_MAX);
    return true;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error parsing height: " << e.what() << "\n";
    return false;
  }
}

int Player::get_weight() const { return wt; }

void Player::set_weight(int new_weight) {
  this->wt = std::clamp(new_weight, WEIGHT_MIN, WEIGHT_MAX);
}

const Location& Player::get_hometown() const { return hometown; }

void Player::set_hometown(Location location) {
  this->hometown = location;
}

void Player::set_hometown(std::string city, std::string state) {
  this->hometown = Location(city, state_from_string(state));
}

void Player::set_hometown(std::string city, State state) {
  this->hometown = Location(city, state);
}

DevTrait Player::get_dev_trait() const { return dev_trait; }

void Player::set_dev_trait(DevTrait new_dev_trait) {
  this->dev_trait = new_dev_trait;
}

void Player::set_dev_trait(std::string new_dev_trait) {
  this->dev_trait = dev_trait_from_string(new_dev_trait);
}

