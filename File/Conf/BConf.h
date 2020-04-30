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

/// @file BConf.h
/// @brief Header de BConf
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef BCONF_H
#define BCONF_H

#include "OPEN/Utils.h"
#include "BasicConf.h"

/// @brief BConf - Manager de fichier de config
///
/// Classe qui gère un fichier de configuration binaire.
class BConf : public BasicConf
{
public:
    BConf();

    ConfErr Load();
    ConfErr Save();

    ConfErr SetArg(std::string Arg, std::string  value);
    ConfErr GetArg(std::string Arg, std::string& value);

    ConfErr AddCmd(WORD cmd, std::string Arg);
    ConfErr DelCmd(WORD cmd);

    ConfErr SetFile(std::string file);

    ~BConf();

private:
    bool IsExist(std::string Arg);
    int GetIndex(std::string Arg);
    WORD GetCommand(std::string Arg);

    std::vector<ConfDesc> config;
    std::map<WORD, std::string> command;
};

#endif // BCONF_H

