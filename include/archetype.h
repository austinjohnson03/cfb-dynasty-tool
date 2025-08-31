#pragma once

#include "archetype_type.h"
#include <string>

class Archetype {
  public:
    Archetype();
    Archetype(ArchetypeType at);
    Archetype(std::string at);
    ~Archetype() = default;

    bool operator==(const Archetype& other) const {
      return archetype_type == other.get_archetype_type();
    }

    bool operator!=(const Archetype& other) const {
      return !(*this == other);
    }

    std::string get_name() const;
    ArchetypeType get_archetype_type() const;


  private:
    std::string name;
    ArchetypeType archetype_type;
};
