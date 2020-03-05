#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SQLite/sqlite3.h"

typedef std::vector<std::string>           Row;
typedef std::map<std::string, std::string> RowDesc;

static Row R = {};

int Callback(void *data, int ncol, char **field, char **col);

class DataBase
{
public:
    DataBase(std::string file);

    bool Connect();
    void Disconnect();

    bool Create(std::string table, RowDesc     field);
    bool Select(std::string table, std::string field, std::string where, Row& row);
    bool Update(std::string table, std::string field, std::string where, std::string value);
    bool Insert(std::string table, std::string field, Row values);
    bool Delete(std::string table, std::string where, std::string value);
    bool Search(std::string table, std::string where, std::string value, bool& exist);

    ~DataBase();

private:
    std::string dbf;
    std::string cmd;
    bool connected;
    char *err;

    sqlite3 *db;
};

#endif // DATABASE_H

