#pragma once

#include "turf_type.h"
#include "location.h"

class Stadium {
  public:
    Stadium();
    Stadium(
        unsigned int id, 
        std::string short_name, 
        std::string full_name, 
        Location* location, 
        unsigned int capacity, 
        unsigned short year_built, 
        TurfType surface_type
        );
    Stadium(
        unsigned int id, 
        std::string short_name, 
        Location* location, 
        unsigned int capacity, 
        unsigned short year_built, 
        TurfType surface_type
        );
    ~Stadium() = default;

    static constexpr unsigned short MIN_YEAR = 1900;

    bool operator==(const Stadium& other) const {
      return 
        id == other.get_id() &&
        short_name == other.get_short_name() &&
        full_name == other.get_full_name() &&
        location && other.get_location() &&
        *location == *other.get_location();
    }

    bool operator!=(const Stadium& other) const {
      return !(*this == other);
    }

    unsigned int get_id() const;
    void set_id(unsigned int new_id);

    std::string get_short_name() const;
    void set_short_name(std::string new_name);

    std::string get_full_name() const;
    void set_full_name(std::string new_name);

    const Location* get_location() const;
    void set_location(Location* loc);

    unsigned int get_capacity() const;
    void set_capacity(unsigned int new_cap);

    unsigned short get_year_built() const;
    void set_year_built(unsigned short new_year);

    TurfType get_surface_type() const;
    void set_surface_type(TurfType new_type);
    void set_surface_type(std::string type);

  private:
    unsigned int id;
    std::string short_name;
    std::string full_name;
    Location* location;
    unsigned int capacity;
    unsigned short year_built;
    TurfType surface_type;
};
