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

/// @file Loggr.cpp
/// @brief Source de Loggr
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "Loggr.h"

/// @brief Loggr - Constructeur
///
/// Constructeur de la classe Loggr.
Loggr::Loggr()
{
    File = "DEFAULT_LOG";
    load = false;
}


/// @brief Load - Lecture d'un log
///
/// @param n: Numéro du log à lire
/// @param desc: Log lu
///
/// @return 0 si pas d'erreur.
int Loggr::Load(SWORD n, LogDesc& desc)
{
    std::string line, temp_n;
    std::regex pattern { "^[0-9]+:[:print:]:[:print:\t]$" };
    LogDesc temp;

    if(!load)
    {
        if(File == "DEFAULT_LOG") return -2;

        std::ifstream file_t(File.c_str(), std::ios::in);

        if(file_t)
        {
            while(getline(file_t, line))
            {
                if(std::regex_match(line, pattern))
                {
                    std::istringstream i_str(line);

                    getline(i_str, temp_n,      ':');
                    getline(i_str, temp.time_s, ':');
                    getline(i_str, temp.msg,    ':');

                    temp.nlog = toNbr<SWORD>(temp_n);

                    logs.push_back(temp);

                    nlogs++;
                }
                else continue;
            }

            file_t.close();
        }
        else return -1;

        load = true;
    }

    if(n >= nlogs) return -3;

    desc.time_s = logs[n].time_s;
    desc.msg    = logs[n].msg;
    desc.nlog   = logs[n].nlog;

    return 0;
}

/// @brief Save - Écriture d'un log
///
/// @param n: Numéro du log écrit
/// @param msg: Message à écrire
///
/// @return 0 tout le temps.
int Loggr::Save(SWORD& n, std::string msg)
{
    std::time_t t;
    std::tm tm_s;
    std::ostringstream o_str;
    LogDesc temp;

    t    = std::time(nullptr);
    tm_s = *std::localtime(&t);

    o_str.imbue(std::locale("en_US.utf8"));

    o_str << std::put_time(&tm_s, "%c %Z");

    temp.msg    = msg;
    temp.time_s = "[ " + o_str.str() + " ]";
    temp.nlog   = nlogs;

    logs.push_back(temp);

    nlogs++;
    n = nlogs - 1;

    return 0;
}


/// @brief SetFile - Sélection du fichier de logs
///
/// @param file: Fichier de logs
///
/// @return 0 si pas d'erreur.
int Loggr::SetFile(std::string file)
{
    if(file == "DEFAULT_LOG") return -1;
    else                      File = file;

    return 0;
}

/// @brief ~Loggr - Destructeur
///
/// @note Sauvegarde les modifications dans le fichier.
/// Destructeur de la classe Loggr.
Loggr::~Loggr()
{
    if(load)
    {
        std::ofstream file_t(File.c_str(), std::ios::out | std::ios::trunc);

        if(file_t)
        {
            for(SWORD i = 0; i < logs.size(); i++)
            {
                file_t << toStr<SWORD>(logs[i].nlog) << ":" << logs[i].time_s << ":" << logs[i].msg << "\n";
            }

            file_t.close(); 
        }
        else std::cerr << "Loggr: Error: Unable to save logs." <<std::endl;
    }
}

