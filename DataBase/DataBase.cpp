#include "DataBase.h"

int Callback(void *data, int ncol, char **field, char **col)
{
    std::cout << (char *)data <<std::endl;
    std::string kvalue;

    R.clear();
    for(int i = 0; i < ncol; i++)
    {
        kvalue  = col[i];
        kvalue += " = ";
        kvalue += field[i] ? field[i] : "Nothing";

        R.push_back(kvalue);
    }

    return 0;
}


DataBase::DataBase(std::string file)
{
    dbf = file;
    connected = false;
}


bool DataBase::Connect()
{
    int ret;

    if(!connected)
    {
        ret = sqlite3_open(dbf.c_str(), &db);

        if(ret)
        {
            std::cerr << "Can't open DataBase: " << sqlite3_errmsg(db) <<std::endl;
            
            return false;
        }

        connected = true;
    }

    return true;
}

void DataBase::Disconnect()
{
    if(connected)
    {
        sqlite3_close(db);

        connected = false;
    }
}


bool DataBase::Create(std::string table, RowDesc     field)
{
    RowDesc::iterator it, it2 = field.end();
    int ret;
    char *sql;

    --it2;

    cmd = "CREATE TABLE " + table + "(" + \
          "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,";

    for(it = field.begin(); it != field.end(); ++it)
    {
        cmd += it->first + " " + it->second;

        if(it != it2)
            cmd += ",";
        else
            cmd += " );";
    }

    sql = (char *)cmd.c_str();
    ret = sqlite3_exec(db, sql, Callback, 0, &err);

    if(ret != SQLITE_OK)
    {
        std::cerr << "Can't create table " << table << ": " << err <<std::endl;
        sqlite3_free(err);

        return false;
    }

    return true;
}

bool DataBase::Select(std::string table, std::string field, std::string where, Row& row)
{
    int ret;
    char *sql;
    std::string data;

    cmd  = "SELECT " + field + " from " + table + " where " + where;

    sql = (char *) cmd.c_str();
    ret = sqlite3_exec(db, sql, Callback, (void *)cmd.c_str(), &err);

    if(ret != SQLITE_OK)
    {
        std::cerr << "Can't select " << field << " in " << table << ": " << err <<std::endl;
        sqlite3_free(err);

        return false;
    }

    row.clear();
    for(Row::size_type i = 0; i < R.size(); i++)
    {
        row.push_back(R[i]);
    }

    return true;
}

bool DataBase::Update(std::string table, std::string field, std::string where, std::string value)
{
    int ret;
    char *sql;

    cmd = "UPDATE " + table + " set " + field + " where " + where + "=" + value + ";";
    
    sql = (char *)cmd.c_str();
    ret = sqlite3_exec(db, sql, Callback, 0, &err);

    if(ret != SQLITE_OK)
    {
        std::cerr << "Can't update " << table << ": " << err <<std::endl;
        sqlite3_free(err);

        return false;
    }

    return true;
}

bool DataBase::Insert(std::string table, std::string field, Row values)
{
    int ret;
    char *sql;

    cmd = "INSERT INTO " + table + " (" + field + ") VALUES (";

    for(Row::size_type i = 0; i < values.size(); i++)
    {
        cmd += values[i];

        if(i != (values.size() - 1))
            cmd += ", ";
        else
            cmd += " );";
    }

    sql = (char *)cmd.c_str();
    ret = sqlite3_exec(db, sql, Callback, 0, &err);

    if(ret != SQLITE_OK)
    {
        std::cerr << "Can't insert into " << table << ": " << err <<std::endl;
        sqlite3_free(err);

        return false;
    }

    return true;
}

bool DataBase::Delete(std::string table, std::string where, std::string value)
{
    int ret;
    char *sql;

    cmd = "DELETE from " + table + " where " + where + "=" + value;

    sql = (char *)cmd.c_str();
    ret = sqlite3_exec(db, sql, Callback, 0, &err);

    if(ret != SQLITE_OK)
    {
        std::cerr << "Can't delete * into " << table << "in " << where << "=" << value << ": " << err <<std::endl;
        sqlite3_free(err);

        return false;
    }

    return true;
}

bool DataBase::Search(std::string table, std::string where, std::string value, bool& exist)
{
    std::string where_t;
    bool ret;
    Row rw;

    where_t = where + " = " + value;

    ret = Select(table, "*", where_t, rw);
    if(!ret) return false;

    if(rw.size() == 0) exist = false;
    else               exist = true;

    return true;
}


DataBase::~DataBase()
{
    if(connected) sqlite3_close(db);
}

