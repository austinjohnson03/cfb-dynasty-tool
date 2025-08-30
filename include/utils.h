#pragma once 

#include <string>
#include <algorithm>
#include <cctype>

namespace Utils {
  inline std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\n\r\f\v ");
    auto end = s.find_last_not_of(" \t\n\r\f\v ");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
  }

  inline std::string to_upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::toupper(c); });

    return s;
  }

  inline std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return s;
  }
}
