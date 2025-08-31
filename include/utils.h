#pragma once 

#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

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

  inline int convert_height_str(std::string s) {
    s = trim(s);
    size_t pos = s.find('\'');
    if (pos == std::string::npos) {
      throw std::invalid_argument("Invalid height format, expected ft'in\"");
    }

    int ft = std::stoi(s.substr(0, pos));

    int in = std::stoi(s.substr(pos + 1));

    return ft * 12 + in;
  }
}
