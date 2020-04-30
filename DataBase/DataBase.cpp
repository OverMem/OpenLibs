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

/// @file DataBase.cpp
/// @brief Source de DataBase
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "DataBase.h"

/// @brief Callback - Fonction callback pour SQLite
///
/// @param data: Données récupérées
/// @param ncol: Nombre de colonnes
/// @param field: Champs récupérées
/// @param col: colonnes récupérées
///
/// @return 0 tout le temps.
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


/// @brief DataBase - Constructeur
///
/// @param file: Fichier de base de données
///
/// Constructeur de la classe DataBase.
DataBase::DataBase(std::string file)
{
    dbf = file;
    connected = false;
}


/// @brief Connect - Connection à la base de données
///
/// @return False si erreur, true sinon.
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

/// @brief Disconnect - Déconnexion de la base de données
void DataBase::Disconnect()
{
    if(connected)
    {
        sqlite3_close(db);

        connected = false;
    }
}


/// @brief Create - Commande CREATE
///
/// @param table: Le nom de la table à créer
/// @param field: Les champs à inclure dans la table (sauf ID)
///
/// @return False si erreur, true sinon.
///
/// Permet de créer une table dans la base de données.
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

/// @brief Select - Commande SELECT
///
/// @param table: Nom de la table
/// @param field: Champs à récupérer
/// @param where: Filtre WHERE (Ex: "ID=2")
/// @param row: Données récupérées
///
/// @return False si erreur, true sinon.
///
/// Permet de récupérer des données de la base avec un filtre WHERE.
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

/// @brief Update - Commande UPDATE
///
/// @param table: Nom de la table
/// @param field: Champs à modifier
/// @param where: Filtre WHERE (Ex: "ID")
/// @param value: Valeur du filtre (Ex: "2")
///
/// @return False si erreur, true sinon.
///
/// Permet de modifier un ou plusieurs champs avec un filtre WHERE.
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

/// @brief Insert - Commande INSERT
///
/// @param table: Nom de la table
/// @param field: Nom des champs
/// @param values: Valeurs à insérer
///
/// @return False si erreur, true sinon.
///
/// Permet d'insérer une ligne dans une table.
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

/// @brief Delete - Commande DELETE
///
/// @param table: Nom de la table
/// @param where: Filtre WHERE (Ex: "ID")
/// @param value: Valeur du filtre (Ex: "2")
///
/// @return False si erreur, true sinon.
///
/// Permet de supprimer une ligne d'une table avec un filtre WHERE.
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

/// @brief Search - Ajout de la commande SEARCH
///
/// @param table: Nom de la table
/// @param where: Filtre WHERE (Ex: "ID")
/// @param value: Valeur du filtre (Ex: "2")
/// @param exist: Retour de la commande
///
/// @return False si erreur, true sinon.
///
/// Permet de rechercher si un élément existe à l'aide 
/// d'un filtre WHERE.
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


/// @brief ~DataBase - Destructeur
///
/// Destructeur de la classe DataBase.
DataBase::~DataBase()
{
    if(connected) sqlite3_close(db);
}

