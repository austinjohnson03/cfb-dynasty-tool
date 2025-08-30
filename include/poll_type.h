#pragma once

#include "utils.h"
#include <unordered_map>

enum class PollType { AP, USA_TODAY, CFP, ERR };

inline bool operator<(PollType lhs, PollType rhs) { 
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator>(PollType lhs, PollType rhs) { return rhs < lhs; }
inline bool operator<=(PollType lhs, PollType rhs) { return !(rhs < lhs); }
inline bool operator>=(PollType lhs, PollType rhs) { return !(lhs < rhs); }

namespace std {
  template<>
    struct hash<PollType> {
      std::size_t operator()(const PollType& p) const noexcept {
        return static_cast<std::size_t>(p);
      }
    };
}

inline std::string poll_type_to_string(PollType p) { 
  switch (p) {
    case PollType::AP: return "AP";
    case PollType::USA_TODAY: return "USA Today";
    case PollType::CFP: return "CFP";
    case PollType::ERR: return "ERR";
    default: return "ERR";
  }
}

inline std::string poll_type_to_full_name(PollType p) {
  switch (p) {
    case PollType::AP: return "AP Media Poll";
    case PollType::USA_TODAY: return "USA Today Coaches Poll";
    case PollType::CFP: return "College Football Playoff Rankings";
    case PollType::ERR: return "Error";
    default: return "Error";
  }
}

inline PollType poll_type_from_string(std::string s) { 
  s = Utils::to_upper(Utils::trim(s));

  static const std::unordered_map<std::string, PollType> mp {
    {"AP", PollType::AP}, {"AP MEDIA POLL", PollType::AP},
    {"USA TODAY", PollType::USA_TODAY}, {"USA TODAY COACHES POLL", PollType::USA_TODAY},
    {"CFP", PollType::CFP}, {"COLLEGE FOOTBALL PLAYOFF RANKINGS", PollType::CFP}
  };

  auto it = mp.find(s);
  if (it != mp.end()) return it->second;

  return PollType::ERR;
}

inline bool is_valid_poll_type(PollType p) { return p != PollType::ERR; }
