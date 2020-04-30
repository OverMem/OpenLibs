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

/// @file BConf.cpp
/// @brief Source de BConf
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "BConf.h"

/// @brief BConf - Constructeur
///
/// Constructeur de la classe BConf.
BConf::BConf() : BasicConf()
{
    return;
}


/// @brief Load - Chargement du fichier
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet de charger en mémoire le fichier de configuration.
ConfErr BConf::Load()
{
    WORD temp_c, size_v;
    DWORD size_f, size_u = 0;
    BYTE temp_v;
    ConfDesc temp;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    config.clear();
    std::ifstream file_t(File.c_str(), std::ios::in | std::ios::binary);

    if(!file_t.is_open()) return ConfErr::File;
    else
    {
        size_f = GetFileSize(file_t);

        while(size_u < size_f)
        {
            file_t.read((char *)&temp_c, 2);

            if(command.find(temp_c) != command.end())
            {
                temp.Key = command[temp_c];

                file_t.read((char *)&size_v, 2);

                temp.Value = "";
                for(DWORD i = 0; i < size_v; i++)
                {
                    file_t.read((char *)&temp_v, 1);

                    temp.Value += ToChar(temp_v);
                }

                config.push_back(temp);

                size_u += (4 + size_v);
            }
            else return ConfErr::Exist;
        }

        file_t.close();
    }

    return ConfErr::NoErr;
}

/// @brief Save - Sauvegarde du fichier
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet d'enregistrer le modifications dans le fichier.
ConfErr BConf::Save()
{
    WORD temp_c, size_v;
    BYTE temp_v;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ofstream file_t(File.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);

    if(!file_t.is_open()) return ConfErr::File;
    else
    {
        for(std::vector<ConfDesc>::size_type i = 0; i < config.size(); i++)
        {
            temp_c = GetCommand(config[i].Key);
            file_t.write((char *)&temp_c, 2);

            size_v = (WORD)config[i].Value.length();
            file_t.write((char *)&size_v, 2);

            for(std::string::size_type j = 0; j < config[i].Value.length(); j++)
            {
                temp_v = ToAscii(config[i].Value[j]);

                file_t.write((char *)&temp_v, 1);
            }
        }

        file_t.close();
    }

    return ConfErr::NoErr;
}


/// @brief SetArg - Création/Mise à jour d'une clé de config
///
/// @param Arg: Clé de config
/// @param value: Valeur à écrire
///
/// @return ConfErr::NoErr si pas d'erreur.
ConfErr BConf::SetArg(std::string Arg, std::string  value)
{
    std::map<WORD, std::string>::iterator it;

    if(IsExist(Arg)) config[GetIndex(Arg)].Value = value;
    else
    {
        for(it = command.begin(); it != command.end(); ++it)
        {
            if(it->second == Arg)
            {
                ConfDesc temp;

                temp.Key   = Arg;
                temp.Value = value;

                config.push_back(temp);

                return ConfErr::NoErr;
            }
        }

        return ConfErr::Exist;
    }

    return ConfErr::NoErr;
}

/// @brief GetArg - Lecture d'une clé de config
///
/// @param Arg: Clé de config
/// @param value: Valeur à lire
///
/// @return ConfErr::NoErr si pas d'erreur.
ConfErr BConf::GetArg(std::string Arg, std::string& value)
{
    if(IsExist(Arg)) value = config[GetIndex(Arg)].Value;
    else             return ConfErr::Exist;

    return ConfErr::NoErr;
}


/// @brief AddCmd - Ajout d'une clé binaire
///
/// @param cmd: Valeur binaire
/// @param Arg: Clé de config
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet d'ajouter une correspondance entre une clé de config 
/// et une valeur binaire dans le fichier.
ConfErr BConf::AddCmd(WORD cmd, std::string Arg)
{
    if(cmd == 0)                           return ConfErr::Name;
    if(command.find(cmd) != command.end()) return ConfErr::Exist;

    command[cmd] = Arg;

    return ConfErr::NoErr;
}

/// @brief DelCmd - Suppression d'une clé binaire
///
/// @param cmd: Valeur binaire
///
/// @return ConfErr::NoErr si pas d'erreur.
///
/// Permet de supprimer une correspondance entre une clé de config 
/// et une valeur binaire du fichier.
ConfErr BConf::DelCmd(WORD cmd)
{
    if(command.find(cmd) == command.end()) return ConfErr::Exist;
    else                                   command.erase(cmd);

    return ConfErr::NoErr;
}


bool BConf::IsExist(std::string Arg)
{
    std::vector<ConfDesc>::iterator it;

    for(it = config.begin(); it != config.end(); ++it)
    {
        if(it->Key == Arg) return true;
    }

    return false;
}

int BConf::GetIndex(std::string Arg)
{
    for(std::vector<ConfDesc>::size_type i = 0; i < config.size(); i++)
    {
        if(config[i].Key == Arg)
        {
            return i;
        }
    }

    return -1;
}

WORD BConf::GetCommand(std::string Arg)
{
    std::map<WORD, std::string>::iterator it;

    for(it = command.begin(); it != command.end(); ++it)
    {
        if(it->second == Arg)
        {
            return it->first;
        }
    }

    return 0;
}


/// @brief SetFile - Sélection du fichier de config
///
/// @param file: Fichier de configuration
///
/// @return ConfErr::NoErr si pas d'erreur.
ConfErr BConf::SetFile(std::string file)
{
    return BasicConf::SetFile(file);
}

/// @brief ~BConf - Destructeur
///
/// Destructeur de la classe BConf.
BConf::~BConf()
{
    return;
}

