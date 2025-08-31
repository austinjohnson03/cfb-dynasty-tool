#include "utils.h"
#include <unordered_map>

enum class TurfType { UNKNOWN, GRASS, TURF, HYBRID };

inline bool operator<(TurfType lhs, TurfType rhs) {
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator>(TurfType lhs, TurfType rhs) { return rhs < lhs; }
inline bool operator<=(TurfType lhs, TurfType rhs) { return !(rhs < lhs); }
inline bool operator>=(TurfType lhs, TurfType rhs) { return !(lhs < rhs); }

namespace std {
  template<>
    struct hash<TurfType> {
      std::size_t operator()(const TurfType& t) const noexcept {
        return static_cast<std::size_t>(t);
      }
    };
}

inline std::string turf_type_to_string(TurfType t) {
  switch (t) {
    case TurfType::UNKNOWN: return "Unknown";
    case TurfType::GRASS: return "Grass";
    case TurfType::TURF: return "Turf";
    case TurfType::HYBRID: return "Hybrid";
    default: return "Unknown";
  }
}

inline TurfType turf_type_from_string(std::string s) {
  s = Utils::to_lower(Utils::trim(s));

  static const std::unordered_map<std::string, TurfType> mp = {
    {"unknown", TurfType::UNKNOWN}, {"grass", TurfType::GRASS},
    {"turf", TurfType::TURF}, {"hybrid", TurfType::HYBRID}
  };

  auto it = mp.find(s);
  if (it != mp.end()) return it->second;

  return TurfType::UNKNOWN;
}
