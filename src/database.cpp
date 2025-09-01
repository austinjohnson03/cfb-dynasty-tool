#include "database.h"
#include <sqlite3.h>

Database::Database(const std::string& db_file) {
    if (sqlite3_open(db_file.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error(
            "Failed to open database: " + std::string(sqlite3_errmsg(db))
        );
    }
}

Database::~Database() {
    if (db) sqlite3_close(db);
}

void Database::bind_params(
    sqlite3_stmt* stmt, 
    const std::vector<std::string>& params
    ) {
    for (size_t i = 0; i < params.size(); ++i) {
        sqlite3_bind_text(
            stmt, static_cast<int>(i + 1), 
            params[i].c_str(), -1, SQLITE_TRANSIENT
        );
    }
}

void Database::execute(
    const std::string& query,
    const std::vector<std::string>& params
    ) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(
            "Failed to prepare statement: " + std::string(sqlite3_errmsg(db))
        );
    }

    bind_params(stmt, params);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error(
            "Failed to execute statement: " + std::string(sqlite3_errmsg(db))
        );
    }

    sqlite3_finalize(stmt);
}

void Database::query(const std::string& query, 
        const std::vector<std::string>& params,
        const std::function<void(const std::vector<std::string>&)>& callback
    ) {
    sqlite3_stmt* stmt;
    if (
        sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK
    ) {
        throw std::runtime_error(
            "Prepare failed: " + std::string(sqlite3_errmsg(db))
        );
    }

    bind_params(stmt, params);

    int rc;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int cols = sqlite3_column_count(stmt);
        std::vector<std::string> row;
        for (int i = 0; i < cols; ++i) {
            const char* val = reinterpret_cast<const char*>(
                sqlite3_column_text(stmt, i)
            );
            row.push_back(val ? val : "");
        }
        callback(row);
    }

    if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error(
            "Query failed: " + std::string(sqlite3_errmsg(db))
        );
    }

    sqlite3_finalize(stmt);
}
