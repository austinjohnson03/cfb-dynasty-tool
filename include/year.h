#pragma once

#include <string>
#include <unordered_map>

enum class Year {
  HS,
  FR,
  SO,
  JR,
  SR,
  UNK
};

inline std::string year_to_string(Year y) {
  switch (y) {
    case Year::HS: return "HS";
    case Year::FR: return "FR";
    case Year::SO: return "SO";
    case Year::JR: return "JR";
    case Year::SR: return "SR";
    case Year::UNK: return "UNK";
    default: return "UNK";
  }
}

inline Year year_from_string(const std::string& s) {
  // Convert string to upper
  std::string s_upper = s;
  std::transform(s_upper.begin(), s_upper.end(), s_upper.begin(), ::toupper);

  static const std::unordered_map<std::string, Year> mp = {
    {"HS", Year::HS}, {"FR", Year::FR}, {"SO", Year::SO}, 
    {"JR", Year::JR}, {"SR", Year::SR}, {"UNK", Year::UNK}
  };

  auto it = mp.find(s_upper);
  if (it != mp.end()) {
    return it->second;
  }
  return Year::UNK;
}

inline bool is_valid_year(Year y) { return y != Year::UNK; }
