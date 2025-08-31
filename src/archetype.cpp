#include "archetype.h"

Archetype::Archetype() 
  : name("Unknown"), archetype_type(ArchetypeType::UNKNOWN) {}

Archetype::Archetype(ArchetypeType at) : archetype_type(at) {
  this->name = archetype_type_to_string(at);
}

std::string Archetype::get_name() const { return name; }

ArchetypeType Archetype::get_archetype_type() const { return archetype_type; }
