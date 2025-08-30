#pragma once 

#include "utils.h"
#include <unordered_map>

enum class CoachPosition { HC, OC, DC, UE, UNDEFINED };

inline bool operator<(CoachPosition lhs, CoachPosition rhs) {
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator>(CoachPosition lhs, CoachPosition rhs) { 
  return rhs < lhs; 
}
inline bool operator<=(CoachPosition lhs, CoachPosition rhs) { 
  return !(rhs < lhs); 
}
inline bool operator>=(CoachPosition lhs, CoachPosition rhs) { 
  return !(lhs < rhs); 
}

namespace std {
  template<>
    struct hash<CoachPosition> {
      std::size_t operator()(const CoachPosition& cp) const noexcept {
        return static_cast<std::size_t>(cp);
      }
    };
}

inline std::string coach_position_to_string(CoachPosition cp) {
  switch (cp) {
    case CoachPosition::HC: return "HC";
    case CoachPosition::OC: return "OC";
    case CoachPosition::DC: return "DC";
    case CoachPosition::UE: return "UE";
    case CoachPosition::UNDEFINED: return "UND";
    default: return "UND";
  }
}

inline std::string coach_position_to_full_name(CoachPosition cp) {
  switch (cp) {
    case CoachPosition::HC: return "Head Coach";
    case CoachPosition::OC: return "Offensive Coordinator";
    case CoachPosition::DC: return "Defensive Coordinator";
    case CoachPosition::UE: return "Unemployed";
    case CoachPosition::UNDEFINED: return "Undefined";
    default: return "Undefined";
  }
}

inline CoachPosition position_from_string(std::string str) {
  str = Utils::to_upper(Utils::trim(str));  // Preprocess string
  
  static const std::unordered_map<std::string, CoachPosition> mp {
    {"HC", CoachPosition::HC}, {"HEAD COACH", CoachPosition::HC},
    {"OC", CoachPosition::OC}, {"OFFENSIVE COORDINATOR", CoachPosition::OC},
    {"DC", CoachPosition::DC}, {"DEFENSIVE COORDINATOR", CoachPosition::DC},
    {"UE", CoachPosition::UE}, {"UNEMPLOYED", CoachPosition::UE},
    {"UND", CoachPosition::UNDEFINED}, {"UNDEFINED", CoachPosition::UNDEFINED}
  };

  auto it = mp.find(str);
  if (it != mp.end()) return it->second;

  return CoachPosition::UNDEFINED;
}

inline bool is_valid_coach_position(CoachPosition cp) { 
  return cp != CoachPosition::UNDEFINED; 
}

