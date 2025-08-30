#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <vector>
#include <algorithm>

enum class State {
  AL, AK, AZ, AR, CA, CO, CT, DC, DE, FL,
  GA, HI, ID, IL, IN, INT, IA, KS, KY, LA,
  ME, MD, MA, MI, MN, MS, MO, MT, NE, NV,
  NH, NJ, NM, NY, NC, ND, OH, OK, OR, PA,
  RI, SC, SD, TN, TX, UT, VT, VA, WA, WV,
  WI, WY, UNK
};

inline bool operator<(State lhs, State rhs) { return static_cast<int>(lhs) < static_cast<int>(rhs); }
inline bool operator>(State lhs, State rhs) { return rhs < lhs; }
inline bool operator<=(State lhs, State rhs) { return !(rhs < lhs); }
inline bool operator>=(State lhs, State rhs) { return !(lhs < rhs); }

namespace std {
  template<>
    struct hash<State> {
      std::size_t operator()(const State& s) const noexcept {
        return static_cast<std::size_t>(s);
      }
    };
}

inline std::string state_to_string(State s) {
  switch(s) {
    case State::AL: return "AL";
    case State::AK: return "AK";
    case State::AZ: return "AZ";
    case State::AR: return "AR";
    case State::CA: return "CA";
    case State::CO: return "CO";
    case State::CT: return "CT";
    case State::DC: return "DC";
    case State::DE: return "DE";
    case State::FL: return "FL";
    case State::GA: return "GA";
    case State::HI: return "HI";
    case State::ID: return "ID";
    case State::IL: return "IL";
    case State::IN: return "IN";
    case State::INT: return "INT";
    case State::IA: return "IA";
    case State::KS: return "KS";
    case State::KY: return "KY";
    case State::LA: return "LA";
    case State::ME: return "ME";
    case State::MD: return "MD";
    case State::MA: return "MA";
    case State::MI: return "MI";
    case State::MN: return "MN";
    case State::MS: return "MS";
    case State::MO: return "MO";
    case State::MT: return "MT";
    case State::NE: return "NE";
    case State::NV: return "NV";
    case State::NH: return "NH";
    case State::NJ: return "NJ";
    case State::NM: return "NM";
    case State::NY: return "NY";
    case State::NC: return "NC";
    case State::ND: return "ND";
    case State::OH: return "OH";
    case State::OK: return "OK";
    case State::OR: return "OR";
    case State::PA: return "PA";
    case State::RI: return "RI";
    case State::SC: return "SC";
    case State::SD: return "SD";
    case State::TN: return "TN";
    case State::TX: return "TX";
    case State::UT: return "UT";
    case State::VT: return "VT";
    case State::VA: return "VA";
    case State::WA: return "WA";
    case State::WV: return "WV";
    case State::WI: return "WI";
    case State::WY: return "WY";
    case State::UNK: return "UNK";
    default: return "UNK";
  }
}

inline State state_from_string(const std::string& str) {
    // Convert to upper
    std::string str_upper = str;
    std::transform(str_upper.begin(), str_upper.end(), str_upper.begin(), ::toupper);

    static const std::unordered_map<std::string, State> str_to_state = {
    {"AL", State::AL}, {"AK", State::AK}, {"AZ", State::AZ}, {"AR", State::AR},
    {"CA", State::CA}, {"CO", State::CO}, {"CT", State::CT}, {"DC", State::DC},
    {"DE", State::DE}, {"FL", State::FL}, {"GA", State::GA}, {"HI", State::HI},
    {"ID", State::ID}, {"IL", State::IL}, {"IN", State::IN}, {"INT", State::INT},
    {"IA", State::IA}, {"KS", State::KS}, {"KY", State::KY}, {"LA", State::LA},
    {"ME", State::ME}, {"MD", State::MD}, {"MA", State::MA}, {"MI", State::MI},
    {"MN", State::MN}, {"MS", State::MS}, {"MO", State::MO}, {"MT", State::MT},
    {"NE", State::NE}, {"NV", State::NV}, {"NH", State::NH}, {"NJ", State::NJ},
    {"NM", State::NM}, {"NY", State::NY}, {"NC", State::NC}, {"ND", State::ND},
    {"OH", State::OH}, {"OK", State::OK}, {"OR", State::OR}, {"PA", State::PA},
    {"RI", State::RI}, {"SC", State::SC}, {"SD", State::SD}, {"TN", State::TN},
    {"TX", State::TX}, {"UT", State::UT}, {"VT", State::VT}, {"VA", State::VA},
    {"WA", State::WA}, {"WV", State::WV}, {"WI", State::WI}, {"WY", State::WY},
    {"UNK", State::UNK}
  };

  auto it = str_to_state.find(str_upper);
  if (it != str_to_state.end()) {
    return it->second;
  }

  return State::UNK;
}

inline State state_from_full_name(const std::string& full_name) {
    // Convert to lower
    std::string full_name_lower = full_name;
    std::transform(full_name_lower.begin(), full_name_lower.end(), full_name_lower.begin(), ::tolower);

    static const std::unordered_map<std::string, State> name_to_state = {
        {"alabama", State::AL}, {"alaska", State::AK}, {"arizona", State::AZ}, {"arkansas", State::AR},
        {"california", State::CA}, {"colorado", State::CO}, {"connecticut", State::CT}, {"district of columbia", State::DC},
        {"delaware", State::DE}, {"florida", State::FL}, {"georgia", State::GA}, {"hawaii", State::HI},
        {"idaho", State::ID}, {"illinois", State::IL}, {"indiana", State::IN}, {"interstate", State::INT},
        {"iowa", State::IA}, {"kansas", State::KS}, {"kentucky", State::KY}, {"louisiana", State::LA},
        {"maine", State::ME}, {"maryland", State::MD}, {"massachusetts", State::MA}, {"michigan", State::MI},
        {"minnesota", State::MN}, {"mississippi", State::MS}, {"missouri", State::MO}, {"montana", State::MT},
        {"nebraska", State::NE}, {"nevada", State::NV}, {"new hampshire", State::NH}, {"new jersey", State::NJ},
        {"new mexico", State::NM}, {"new york", State::NY}, {"north carolina", State::NC}, {"north dakota", State::ND},
        {"ohio", State::OH}, {"oklahoma", State::OK}, {"oregon", State::OR}, {"pennsylvania", State::PA},
        {"rhode island", State::RI}, {"south carolina", State::SC}, {"south dakota", State::SD}, {"tennessee", State::TN},
        {"texas", State::TX}, {"utah", State::UT}, {"vermont", State::VT}, {"virginia", State::VA},
        {"washington", State::WA}, {"west virginia", State::WV}, {"wisconsin", State::WI}, {"wyoming", State::WY}
  };

  auto it = name_to_state.find(full_name_lower);
  if (it != name_to_state.end()) {
    return it->second;
  }

  return State::UNK;
}

inline std::string full_name(State s) {
  switch(s) {
    case State::AL: return "Alabama";
    case State::AK: return "Alaska";
    case State::AZ: return "Arizona";
    case State::AR: return "Arkansas";
    case State::CA: return "California";
    case State::CO: return "Colorado";
    case State::CT: return "Connecticut";
    case State::DC: return "District of Columbia";
    case State::DE: return "Delaware";
    case State::FL: return "Florida";
    case State::GA: return "Georgia";
    case State::HI: return "Hawaii";
    case State::ID: return "Idaho";
    case State::IL: return "Illinois";
    case State::IN: return "Indiana";
    case State::INT: return "Interstate";
    case State::IA: return "Iowa";
    case State::KS: return "Kansas";
    case State::KY: return "Kentucky";
    case State::LA: return "Louisiana";
    case State::ME: return "Maine";
    case State::MD: return "Maryland";
    case State::MA: return "Massachusetts";
    case State::MI: return "Michigan";
    case State::MN: return "Minnesota";
    case State::MS: return "Mississippi";
    case State::MO: return "Missouri";
    case State::MT: return "Montana";
    case State::NE: return "Nebraska";
    case State::NV: return "Nevada";
    case State::NH: return "New Hampshire";
    case State::NJ: return "New Jersey";
    case State::NM: return "New Mexico";
    case State::NY: return "New York";
    case State::NC: return "North Carolina";
    case State::ND: return "North Dakota";
    case State::OH: return "Ohio";
    case State::OK: return "Oklahoma";
    case State::OR: return "Oregon";
    case State::PA: return "Pennsylvania";
    case State::RI: return "Rhode Island";
    case State::SC: return "South Carolina";
    case State::SD: return "South Dakota";
    case State::TN: return "Tennessee";
    case State::TX: return "Texas";
    case State::UT: return "Utah";
    case State::VT: return "Vermont";
    case State::VA: return "Virginia";
    case State::WA: return "Washington";
    case State::WV: return "West Virginia";
    case State::WI: return "Wisconsin";
    case State::WY: return "Wyoming";
    case State::UNK: return "Unknown";
    default: return "Unknown";
  }
}

inline bool is_valid_state(State s) {
  return s != State::UNK;
}
