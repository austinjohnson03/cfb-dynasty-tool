#pragma once 

#include <string>
#include <cstdint>
#include <functional>

namespace Utils {
  enum class LogLevel { INFO, WARNING, ERROR };

  inline std::string log_level_to_string(LogLevel level) {
    switch (level) {
      case LogLevel::INFO: return "INFO";
      case LogLevel::WARNING: return "WARNING";
      case LogLevel::ERROR: return "ERROR";
    }
    return "UNKNOWN";
  }

  std::string trim(const std::string& s);
  std::string to_upper(std::string s);
  std::string to_lower(std::string s);
  int convert_height_str(std::string s);

  void log(
      LogLevel level, 
      const std::string& msg, 
      const std::string& filename = "logs/log.txt"
      );
} // namespace Utils
