#pragma once

#include "archetype.h"
#include "position.h"
#include "location.h"
#include "year.h"
#include "dev_trait.h"
#include <string>


class Player {
  public:
    Player();
    Player(
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
        );
    ~Player() = default;

    static constexpr int HEIGHT_MIN = 48;
    static constexpr int HEIGHT_MAX = 90;
    static constexpr int WEIGHT_MIN = 150;
    static constexpr int WEIGHT_MAX = 500;

    unsigned int get_id() const;

    void set_id(unsigned int new_id);

    std::string get_first_name() const;

    void set_first_name(std::string new_first);

    std::string get_last_name() const;

    void set_last_name(std::string new_last);

    std::string get_full_name() const;

    Position get_position() const;

    void set_position(Position pos);

    void set_position(std::string pos);

    Archetype get_archetype() const;

    void set_archetype(Archetype new_arch);

    void set_archetype(std::string new_arch);

    Year get_year() const;

    void set_year(Year new_year);

    void set_year(std::string new_year);

    bool is_redshirt() const;

    void set_redshirt(bool is_redshirt);

    std::string get_year_str() const;

    int get_height() const;

    std::string get_height_str();

    void set_height(int new_height);

    bool set_height(std::string new_height);

    int get_weight() const;

    void set_weight(int new_weight);

    const Location& get_hometown() const;

    void set_hometown(Location location);

    void set_hometown(std::string city, std::string state);

    void set_hometown(std::string city, State state);

    DevTrait get_dev_trait() const;

    void set_dev_trait(DevTrait new_dev_trait);

    void set_dev_trait(std::string new_dev_trait);
  
    bool operator==(const Player& other) const {
      return 
        id == other.get_id() &&
        first_name == other.get_first_name() &&
        last_name == other.get_last_name() &&
        hometown == other.get_hometown();
    }

    bool operator!=(const Player& other) const {
      return !(*this == other);
    }

  private:
    unsigned int id;
    std::string first_name;
    std::string last_name;
    Position position;
    Archetype archetype;
    Year year;
    bool redshirt;
    int ht;
    int wt;
    Location hometown;
    DevTrait dev_trait;
};
