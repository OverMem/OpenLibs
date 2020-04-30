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

/// @file Loggr.h
/// @brief Header de Loggr
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef LOGGR_H
#define LOGGR_H

#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>
#include <iomanip>
#include "OPEN/Types/Convert.h"

/// @brief LogDesc - Représente un message de log
///
/// Structure décrivant un message de log avec 
/// date, numéro et message.
typedef struct
{
    std::string time_s; //!< Date du log.
    std::string msg;    //!< Message du log.

    SWORD nlog;         //!< Numéro de log.
}LogDesc;

/// @brief Loggr - Manager de fichier de logs
///
/// Classe qui gère un fichier de logs.
class Loggr
{
public:
    Loggr();

    int Load(SWORD  n, LogDesc& desc);
    int Save(SWORD& n, std::string msg);

    int SetFile(std::string file);

    ~Loggr();

private:
    std::vector<LogDesc> logs;
    std::string File;

    bool load;
    SWORD nlogs;
};

#endif // LOGGR_H

