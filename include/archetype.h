#pragma once

#include "archetype_type.h"
#include <string>

class Archetype {
  public:
    Archetype();
    Archetype(ArchetypeType at);
    ~Archetype() = default;

    std::string get_name() const;
    ArchetypeType get_archetype_type();

  private:
    std::string name;
    ArchetypeType archetype_type;
};
