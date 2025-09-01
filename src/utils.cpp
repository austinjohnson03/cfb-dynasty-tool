#include "utils.h"

#include <fstream>
#include <mutex>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <stdexcept>
#include <cctype>

namespace Utils {

  std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\n\r\f\v ");
    auto end = s.find_last_not_of(" \t\n\r\f\v ");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
  }

  std::string to_upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::toupper(c); });

    return s;
  }

  std::string to_lower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return s;
  }

  int convert_height_str(std::string s) {
    s = trim(s);
    size_t pos = s.find('\'');
    if (pos == std::string::npos) {
      throw std::invalid_argument("Invalid height format, expected ft'in\"");
    }

    int ft = std::stoi(s.substr(0, pos));

    int in = std::stoi(s.substr(pos + 1));

    return ft * 12 + in;
  }

  void log(
      LogLevel level, const std::string& msg, const std::string& filename) {
    static std::mutex log_mutex;

    std::lock_guard<std::mutex> lock(log_mutex);

    std::filesystem::create_directories(
        std::filesystem::path(filename).parent_path()
        );

    std::ofstream out(filename, std::ios::app);
    if (!out.is_open()) return;

    std::time_t t = std::time(nullptr);
    char buff[64];
    std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
    out << "[" << buff << "] [" << log_level_to_string(level) << "] " 
      << msg << "\n";
  }

}
