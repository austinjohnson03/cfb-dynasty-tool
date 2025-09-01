#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <functional>

class Database {
  public:
    Database(const std::string& db_file);
    ~Database();

    void execute(
        const std::string& query,
        const std::vector<std::string>& params = {}
    );

    void query(const std::string& sql, 
        const std::vector<std::string>& params,
        const std::function<void(const std::vector<std::string>&)>& callback
    );

  private:
    sqlite3* db = nullptr;

    void bind_params(
        sqlite3_stmt* stmt, 
        const std::vector<std::string>& params
    );
};