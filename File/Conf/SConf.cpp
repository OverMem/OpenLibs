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

/// @file SConf.cpp
/// @brief Source de SConf
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "SConf.h"

/// @brief SConf - Constructeur
///
/// Constructeur de la classe SConf.
SConf::SConf() : BasicConf()
{
    return;
}


/// @brief Load - Chargement du fichier
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet de charger en mémoire le fichier de configuration.
ConfErr SConf::Load()
{
    std::string line, key, value;
    ConfDesc temp;
    std::regex pattern   { "^[A-Za-z_]+[ \t]*=[ \t]*[A-Za-z]+|[0-9]+|[0-9]+\\.([0-9])+$" };
    std::regex pattern_c { "#[:print:\t]" };

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ifstream file_t(File.c_str(), std::ios::in);

    if(file_t)
    {
        while(getline(file_t, line))
        {
            if(std::regex_match(line, pattern_c)) continue;
            else if(std::regex_match(line, pattern))
            {
                std::istringstream i_str(line);

                getline(i_str, key,   '=');
                getline(i_str, value, '=');

                for(std::string::size_type i = 0; i < key.length(); ++i)
                    if(key[i] == ' ') key.erase(i, 1);
                for(std::string::size_type i = 0; i < value.length(); ++i)
                    if(value[i] == ' ') value.erase(i, 1);

                temp.Key   = key;
                temp.Value = value;

                config.push_back(temp);
            }
            else
            {
                file_t.close();

                return ConfErr::Regex;
            }
        }
    }
    else return ConfErr::File;

    return ConfErr::NoErr;
}

/// @brief Save - Sauvegarde du fichier
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet d'enregistrer les modifications dans le fichier.
ConfErr SConf::Save()
{
    std::string line, key, value;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ofstream file_t(File.c_str(), std::ios::out | std::ios::trunc);

    if(file_t)
    {
        for(std::vector<ConfDesc>::size_type i = 0; i < config.size(); i++)
        {
            line = config[i].Key + " = " + config[i].Value + "\n";

            file_t << line;
        }

        file_t.close();
    }
    else return ConfErr::File;

    return ConfErr::NoErr;
}


/// @brief SetArg - Création/Mise à jour d'une clé de config
///
/// @param Arg: Clé de config
/// @param value: Valeur à écrire
///
/// @return ConfErr::NoErr tout le temps.
ConfErr SConf::SetArg(std::string Arg, std::string  value)
{
    if(IsExist(Arg)) config[GetIndex(Arg)].Value = value;
    else
    {
        ConfDesc temp;

        temp.Key   = Arg;
        temp.Value = value;

        config.push_back(temp);
    }

    return ConfErr::NoErr;
}

/// @brief GetArg - Lecture d'une clé de config
///
/// @param Arg: Clé de config
/// @param value: Valeur lue
///
/// @return ConfErr::NoErr si pas d'erreur.
ConfErr SConf::GetArg(std::string Arg, std::string& value)
{
    if(IsExist(Arg)) value = config[GetIndex(Arg)].Value;
    else             return ConfErr::Exist;

    return ConfErr::NoErr;
}


bool SConf::IsExist(std::string Arg)
{
    std::vector<ConfDesc>::iterator it;

    for(it = config.begin(); it != config.end(); ++it)
    {
        if(it->Key == Arg) return true;
    }

    return false;
}

int SConf::GetIndex(std::string Arg)
{
    for(std::vector<ConfDesc>::size_type i = 0; i < config.size(); i++)
    {
        if(config[i].Key == Arg) return i;
    }

    return -1;
}

/// @brief SetFile - Sélection du fichier de config
///
/// @param file: Fichier de configuration
///
/// @return ConfErr::NoErr si pas d'erreur.
ConfErr SConf::SetFile(std::string file)
{
    return BasicConf::SetFile(file);
}

/// @brief ~SConf - Destructeur
///
/// Destructeur de la classe SConf
SConf::~SConf()
{
    return;
}

