#pragma once

#include "utils.h"
#include <unordered_map>

enum class Position {
  QB, HB, FB, TE, WR, OT, OG, C, EDGE, 
  DT, LB, CB, S, P, K, ATH, UNDEFINED
};

inline bool operator<(Position lhs, Position rhs) {
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}
inline bool operator>(Position lhs, Position rhs) { return rhs < lhs; }
inline bool operator<=(Position lhs, Position rhs) { return !(rhs < lhs); }
inline bool operator>=(Position lhs, Position rhs) { return !(lhs < rhs); }

namespace std {
  template<>
    struct hash<Position> {
      std::size_t operator()(const Position& p) const noexcept {
        return static_cast<std::size_t>(p);
      }
    };
}

inline std::string position_to_string(Position p) {
  switch (p) {
    case Position::QB: return "QB";
    case Position::HB: return "HB";
    case Position::FB: return "FB";
    case Position::TE: return "TE";
    case Position::WR: return "WR";
    case Position::OT: return "OT";
    case Position::OG: return "OG";
    case Position::C: return "C";
    case Position::EDGE: return "EDGE";
    case Position::DT: return "DT";
    case Position::LB: return "LB";
    case Position::CB: return "CB";
    case Position::S: return "S";
    case Position::P: return "P";
    case Position::K: return "K";
    case Position::ATH: return "ATH";
    case Position::UNDEFINED: return "UND";
    default: return "UND";
  }
}

inline std::string position_to_full_name(Position p) {
  switch(p) {
    case Position::QB: return "Quarterback";
    case Position::HB: return "Half Back";
    case Position::FB: return "Fullback";
    case Position::TE: return "Tight End";
    case Position::WR: return "Wide Receiver";
    case Position::OT: return "Offensive Tackle";
    case Position::OG: return "Offensive Guard";
    case Position::C: return "Center";
    case Position::EDGE: return "Edge Rusher";
    case Position::DT: return "Defensive Tackle";
    case Position::LB: return "Linebacker";
    case Position::CB: return "Corner Back";
    case Position::S: return "Safety";
    case Position::P: return "Punter";
    case Position::K: return "Kicker";
    case Position::ATH: return "Athlete";
    case Position::UNDEFINED: return "Undefined";
    default: return "Undefined";
  }
}

inline Position position_from_string(const std::string& str) {
  std::string str_upper = str;
  str_upper = Utils::trim(str_upper);
  str_upper = Utils::to_upper(str_upper);

  static const std::unordered_map<std::string, Position> str_to_pos = {
    {"QB", Position::QB}, {"QUARTERBACK", Position::QB}, 
    {"HB", Position::HB}, {"HALF BACK", Position::HB}, 
    {"FB", Position::FB}, {"FULLBACK", Position::FB}, 
    {"WR", Position::WR}, {"WIDE RECEIVER", Position::WR}, 
    {"OT", Position::OT}, {"OFFENSIVE TACKLE", Position::OT},
    {"OG", Position::OG}, {"OFFENSIVE GUARD", Position::OG}, 
    {"C", Position::C}, {"CENTER", Position::C}, 
    {"EDGE", Position::EDGE}, {"EDGE RUSHER", Position::EDGE}, 
    {"DT", Position::DT}, {"DEFENSIVE TACKLE", Position::DT},
    {"LB", Position::LB}, {"LINEBACKER", Position::LB}, 
    {"CB", Position::CB}, {"CORNER BACK", Position::CB}, 
    {"S", Position::S}, {"SAFETY", Position::S},
    {"P", Position::P}, {"PUNTER", Position::P}, 
    {"K", Position::K}, {"KICKER", Position::K}, 
    {"ATH", Position::ATH}, {"ATHLETE", Position::ATH},
    {"UND", Position::UNDEFINED}, {"UNDEFINED", Position::UNDEFINED}
  };

  auto it = str_to_pos.find(str_upper);
  if (it != str_to_pos.end()) return it->second;

  return Position::UNDEFINED;
}

inline bool is_valid_position(Position p) { return p != Position::UNDEFINED; }

