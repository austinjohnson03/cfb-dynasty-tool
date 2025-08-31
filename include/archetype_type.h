#pragma once

#include "utils.h"
#include <unordered_map>

enum class ArchetypeType {
  UNKNOWN,
  // Quarterbacks
  BACKFIELD_CREATOR,
  DUAL_THREAT,
  POCKET_PASSER,
  PURE_RUNNER,
  // Half Backs
  BACKFIELD_THREAT,
  CONTACT_SEEKER,
  EAST_WEST_PLAYMAKER,
  ELUSIVE_BRUISER,
  NORTH_SOUTH_RECEIVER,
  NORTH_SOUTH_BLOCKER,
  // Fullbacks
  BLOCKING,
  UTILITY,
  // Wide Receivers
  CONTESTED_SPECIALIST,
  ELUSIVE_ROUTE_RUNNER,
  GADGET,
  ROUTE_ARTIST,
  SPEEDSTER,
  // Wide Receivers & Tight Ends
  GRITTY_POSSESSION,
  PHYSICAL_ROUTE_RUNNER,
  // Tight Ends
  POSSESSION,
  PURE_BLOCKER,
  VERTICAL_THREAT,
  // Offensive Line
  AGILE,
  PASS_PROTECTOR,
  RAW_STRENGTH,
  WELL_ROUNDED,
  // Defensive Line 
  POWER_RUSHER,
  PURE_POWER,
  SPEED_RUSHER,
  // EDGE only
  EDGE_SETTER,
  // DT Only 
  GAP_SPECIALIST,
  // Linebackers 
  LURKER,
  SIGNAL_CALLER,
  THUMPER,
  // Cornerbacks
  BOUNDARY,
  BUMP_AND_RUN,
  FIELD,
  ZONE,
  // Safeties
  BOX_SPECIALIST,
  COVERAGE_SPECIALIST,
  HYBRID,
  // Kickers and Punters
  ACCURATE,
  POWER
};

namespace std {
  template<>
  struct hash<ArchetypeType> {
    std::size_t operator()(const ArchetypeType& t) const noexcept {
      return static_cast<std::size_t>(t);
    }
  };
}

inline std::string archetype_type_to_string(ArchetypeType t) {
  switch (t) {
    case ArchetypeType::UNKNOWN: return "Unknown";
    case ArchetypeType::BACKFIELD_CREATOR: return "Backfield Creator";
    case ArchetypeType::DUAL_THREAT: return "Dual Threat";
    case ArchetypeType::POCKET_PASSER: return "Pocket Passer";
    case ArchetypeType::PURE_RUNNER: return "Pure Runner";
    case ArchetypeType::BACKFIELD_THREAT: return "Backfield Threat";
    case ArchetypeType::CONTACT_SEEKER: return "Contact Seeker";
    case ArchetypeType::EAST_WEST_PLAYMAKER: return "East/West Playmaker";
    case ArchetypeType::ELUSIVE_BRUISER: return "Elusive Bruiser";
    case ArchetypeType::NORTH_SOUTH_RECEIVER: return "North/South Receiver";
    case ArchetypeType::NORTH_SOUTH_BLOCKER: return "North/South Blocker";
    case ArchetypeType::BLOCKING: return "Blocking";
    case ArchetypeType::UTILITY: return "Utility";
    case ArchetypeType::CONTESTED_SPECIALIST: return "Contested Specialist";
    case ArchetypeType::ELUSIVE_ROUTE_RUNNER: return "Elusive Route Runner";
    case ArchetypeType::GADGET: return "Gadget";
    case ArchetypeType::ROUTE_ARTIST: return "Route Artist";
    case ArchetypeType::SPEEDSTER: return "Speedster";
    case ArchetypeType::GRITTY_POSSESSION: return "Gritty Possession";
    case ArchetypeType::PHYSICAL_ROUTE_RUNNER: return "Physicall Route Runner";
    case ArchetypeType::POSSESSION: return "Possession";
    case ArchetypeType::PURE_BLOCKER: return "Pure Blocker";
    case ArchetypeType::VERTICAL_THREAT: return "Vertical Threat";
    case ArchetypeType::AGILE: return "Agile";
    case ArchetypeType::PASS_PROTECTOR: return "Pass Protector";
    case ArchetypeType::RAW_STRENGTH: return "Raw Strength";
    case ArchetypeType::WELL_ROUNDED: return "Well Rounded";
    case ArchetypeType::POWER_RUSHER: return "Power Rusher";
    case ArchetypeType::PURE_POWER: return "Pure Power";
    case ArchetypeType::SPEED_RUSHER: return "Speed Rusher";
    case ArchetypeType::EDGE_SETTER: return "Edge Setter";
    case ArchetypeType::GAP_SPECIALIST: return "Gap Specialist";
    case ArchetypeType::LURKER: return "Lurker";
    case ArchetypeType::SIGNAL_CALLER: return "Signal Caller";
    case ArchetypeType::THUMPER: return "Thumper";
    case ArchetypeType::BOUNDARY: return "Boundary";
    case ArchetypeType::BUMP_AND_RUN: return "Bump and Run";
    case ArchetypeType::FIELD: return "Field";
    case ArchetypeType::ZONE: return "Zone";
    case ArchetypeType::BOX_SPECIALIST: return "Box Specialist";
    case ArchetypeType::COVERAGE_SPECIALIST: return "Coverage Specialist";
    case ArchetypeType::HYBRID: return "Hybrid";
    case ArchetypeType::ACCURATE: return "Accurate";
    case ArchetypeType::POWER: return "Power";
    default: return "Unknown";
  }
}

inline ArchetypeType archetype_type_from_string(std::string s) {
  s = Utils::to_lower(Utils::trim(s));

  static const std::unordered_map<std::string, ArchetypeType> mp = {
    {"backfield creator", ArchetypeType::BACKFIELD_CREATOR},
    {"dual threat", ArchetypeType::DUAL_THREAT},
    {"pocket_passer", ArchetypeType::POCKET_PASSER},
    {"pure runner", ArchetypeType::PURE_RUNNER},
    {"backfield threat", ArchetypeType::BACKFIELD_THREAT},
    {"contact seeker", ArchetypeType::CONTACT_SEEKER},
    {"east/west playmaker", ArchetypeType::EAST_WEST_PLAYMAKER},
    {"east west playmaker", ArchetypeType::EAST_WEST_PLAYMAKER},
    {"elusive bruiser", ArchetypeType::ELUSIVE_BRUISER},
    {"north/south receiver", ArchetypeType::NORTH_SOUTH_RECEIVER},
    {"north south receiver", ArchetypeType::NORTH_SOUTH_RECEIVER},
    {"north/south reciever", ArchetypeType::NORTH_SOUTH_RECEIVER},
    {"north south reciever", ArchetypeType::NORTH_SOUTH_RECEIVER},
    {"north/south blocker", ArchetypeType::NORTH_SOUTH_BLOCKER},
    {"north south blocker", ArchetypeType::NORTH_SOUTH_BLOCKER},
    {"blocking", ArchetypeType::BLOCKING},
    {"utility", ArchetypeType::UTILITY},
    {"contested specialist", ArchetypeType::CONTESTED_SPECIALIST},
    {"contest specialist", ArchetypeType::CONTESTED_SPECIALIST},
    {"elusive route runner", ArchetypeType::ELUSIVE_ROUTE_RUNNER},
    {"gadget", ArchetypeType::GADGET},
    {"route artist", ArchetypeType::ROUTE_ARTIST},
    {"speedster", ArchetypeType::SPEEDSTER},
    {"gritty possession", ArchetypeType::GRITTY_POSSESSION},
    {"physical route runner", ArchetypeType::PHYSICAL_ROUTE_RUNNER},
    {"possession", ArchetypeType::POSSESSION},
    {"pure blocker", ArchetypeType::PURE_BLOCKER},
    {"vertical threat", ArchetypeType::VERTICAL_THREAT},
    {"agile", ArchetypeType::AGILE},
    {"pass protector", ArchetypeType::PASS_PROTECTOR},
    {"raw strength", ArchetypeType::RAW_STRENGTH},
    {"well rounded", ArchetypeType::WELL_ROUNDED},
    {"power rusher", ArchetypeType::POWER_RUSHER},
    {"pure power", ArchetypeType::PURE_POWER},
    {"speed rusher", ArchetypeType::SPEED_RUSHER},
    {"edge setter", ArchetypeType::EDGE_SETTER},
    {"gap specialist", ArchetypeType::GAP_SPECIALIST},
    {"lurker", ArchetypeType::LURKER},
    {"signal caller", ArchetypeType::SIGNAL_CALLER},
    {"thumper", ArchetypeType::THUMPER},
    {"boundary", ArchetypeType::BOUNDARY},
    {"bump and run", ArchetypeType::BUMP_AND_RUN},
    {"field", ArchetypeType::FIELD},
    {"zone", ArchetypeType::ZONE},
    {"box specialist", ArchetypeType::BOX_SPECIALIST},
    {"coverage specialist", ArchetypeType::COVERAGE_SPECIALIST},
    {"hybrid", ArchetypeType::HYBRID},
    {"accurate", ArchetypeType::ACCURATE},
    {"power", ArchetypeType::POWER},
    {"unknown", ArchetypeType::UNKNOWN}
  };

  auto it = mp.find(s);
  if (it != mp.end()) return it->second;

  return ArchetypeType::UNKNOWN;
}

inline bool archetype_type_is_valid(ArchetypeType at) { 
  return at != ArchetypeType::UNKNOWN;
}
