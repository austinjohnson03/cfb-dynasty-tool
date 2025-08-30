#pragma once

#include "utils.h"
#include <unordered_map>

enum class DevTrait { UNKNOWN, NORMAL, IMPACT, STAR, ELITE };

inline bool operator<(DevTrait lhs, DevTrait rhs) {
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator>(DevTrait lhs, DevTrait rhs) { return rhs < lhs; }
inline bool operator<=(DevTrait lhs, DevTrait rhs) { return !(rhs < lhs); }
inline bool operator>=(DevTrait lhs, DevTrait rhs) { return !(lhs < rhs); }

namespace std {
  template<>
    struct hash<DevTrait> {
      std::size_t operator()(const DevTrait& dt) const noexcept {
        return static_cast<std::size_t>(dt);
      }
    };
}

inline std::string dev_trait_to_string(DevTrait dt) {
  switch (dt) {
    case DevTrait::UNKNOWN: return "Unknown";
    case DevTrait::NORMAL: return "Normal";
    case DevTrait::IMPACT: return "Impact";
    case DevTrait::STAR: return "Star";
    case DevTrait::ELITE: return "Elite";
    default: return "Unknown";
  }
}

inline DevTrait dev_trait_from_string(std::string s) {
  s = Utils::to_upper(Utils::trim(s));

  static const std::unordered_map<std::string, DevTrait> mp = {
    {"UNKNOWN", DevTrait::UNKNOWN}, {"NORMAL", DevTrait::NORMAL},
    {"IMPACT", DevTrait::IMPACT}, {"STAR", DevTrait::STAR},
    {"ELITE", DevTrait::ELITE}
  };

  auto it = mp.find(s);
  if (it != mp.end()) return it->second;

  return DevTrait::UNKNOWN;
}

inline bool dev_trait_is_valid(DevTrait dt) { return dt != DevTrait::UNKNOWN; }
