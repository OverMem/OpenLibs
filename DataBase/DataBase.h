/*
Copyright © 2020 Nicolle Rémi

This file is part of OpenLibs.

OpenLibs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenLibs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLibs.  If not, see <https://www.gnu.org/licenses/>.
*/

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

