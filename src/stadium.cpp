#include "stadium.h"

#include <utility>
#include "utils.h"

Stadium::Stadium() : id(0), short_name(""), full_name(""), location(nullptr), 
  capacity(0), year_built(MIN_YEAR), surface_type(TurfType::UNKNOWN) {}

Stadium::Stadium(
    unsigned int id,
    std::string short_name,
    std::string full_name,
    Location* location,
    unsigned int capacity,
    unsigned short year_built,
    TurfType surface_type
    ) :
  id(id),
  short_name(std::move(short_name)),
full_name(std::move(full_name)),
  location(location),
  capacity(capacity),
  year_built(year_built),
  surface_type(surface_type)
{}

Stadium::Stadium(
    unsigned int id,
    std::string short_name,
    Location* location,
    unsigned int capacity,
    unsigned short year_built,
    TurfType surface_type
    ) :
  id(id),
  short_name(std::move(Utils::trim(short_name))),
  full_name(std::move(Utils::trim(short_name))),
  location(location),
  capacity(capacity),
  year_built(year_built),
  surface_type(surface_type)
{}

unsigned int Stadium::get_id() const { return id; }

void Stadium::set_id(unsigned int new_id) {
  this->id = new_id;
}

std::string Stadium::get_short_name() const { return short_name; }

void Stadium::set_short_name(std::string new_name) {
  this->short_name = std::move(Utils::trim(new_name));
}

std::string Stadium::get_full_name() const { return full_name; }

void Stadium::set_full_name(std::string new_name) {
  this->full_name = std::move(Utils::trim(new_name));
}

const Location* Stadium::get_location() const { return location; }

void Stadium::set_location(Location* loc) {
  this->location = loc;  // No ownership, managed in locations data struct
}

unsigned int Stadium::get_capacity() const { return capacity; }

void Stadium::set_capacity(unsigned int new_cap) {
  this->capacity = new_cap;
}

unsigned short Stadium::get_year_built() const { return year_built; }

void Stadium::set_year_built(unsigned short new_year) {
  this->year_built = new_year;
}

TurfType Stadium::get_surface_type() const { return surface_type; }

void Stadium::set_surface_type(TurfType new_type) {
  this->surface_type = new_type;
}

void Stadium::set_surface_type(std::string type) {
  this->surface_type = turf_type_from_string(type);
}

