#pragma once
#include <sqlite3.h>
#include <string>

class Database
{
private:
    sqlite3 *db;
    std::string dbName;

public:
    Database(const std::string &filename);
    ~Database();

    bool open();
    void close();

    bool execute(const std::string &sql);
    bool executeWithCallback(const std::string &sql, int (*callback)(void *, int, char **, char **), void *data);

    sqlite3 *getDB();
};