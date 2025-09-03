-- Varchar is used in case of migration to non-Sqlite DB in future

CREATE TABLE IF NOT EXISTS states (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    abbreviation VARCHAR(3) NOT NULL,
    name VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS positions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(16) NOT NULL,
    abbr VARCHAR(4) NOT NULL
);

CREATE TABLE IF NOT EXISTS depth_chart_positions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(23) NOT NULL,
    abbr VARCHAR(5) NOT NULL
);

CREATE TABLE IF NOT EXISTS conferences (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(30) NOT NULL,
    abbreviation VARCHAR(4) NOT NULL,
    UNIQUE(name, abbreviation)
);

CREATE TABLE IF NOT EXISTS divisions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(30),
    conference_id INTEGER NOT NULL,
    UNIQUE(name, conference_id),
    FOREIGN KEY (conference_id) REFERENCES conferences (id)
);

CREATE TABLE IF NOT EXISTS locations (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    city VARCHAR(30) NOT NULL,
    state_id INTEGER NOT NULL,
    UNIQUE(city, state_id),
    FOREIGN KEY (state_id) REFERENCES states (id)
);

CREATE TABLE IF NOT EXISTS dev_traits (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(7) NOT NULL
);

CREATE TABLE IF NOT EXISTS poll_types (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    short_name VARCHAR(9) NOT NULL,
    full_name VARCHAR(33) NOT NULL,
    UNIQUE(short_name, full_name)
);

CREATE TABLE IF NOT EXISTS pipelines (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(30) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS player_archetypes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(20) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS teams (
    id INTEGER PRIMARY KEY,
    school VARCHAR(31) NOT NULL,
    mascot VARCHAR(16) NOT NULL,
    abbreviation VARCHAR(8) NOT NULL,
    location_id INTEGER NOT NULL,
    conference_id INTEGER NOT NULL,
    division_id INTEGER NOT NULL,
    UNIQUE(school, location_id),
    FOREIGN KEY (conference_id) REFERENCES conferences (id),
    FOREIGN KEY (division_id) REFERENCES divisions (id),
    FOREIGN KEY (location_id) REFERENCES locations (id)
);
