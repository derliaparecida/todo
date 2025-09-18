#include "Database.hpp"
#include <iostream>
#include <sqlite3.h>

Database::Database(const std::string &filename) : db(nullptr), dbName(filename) {}

Database::~Database()
{
    close();
}

bool Database::open()
{
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Database::close()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::execute(const std::string &sql)
{
    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Erro SQLite: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::executeWithCallback(const std::string &sql, int (*callback)(void *, int, char **, char **), void *data)
{
    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, data, &errMsg) != SQLITE_OK)
    {
        std::cerr << "Erro SQLite: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

sqlite3 *Database::getDB()
{
    return db;
}
