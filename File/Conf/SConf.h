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

/// @file SConf.h
/// @brief Header de SConf
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef SCONF_H
#define SCONF_H

#include <vector>
#include "BasicConf.h"

/// @brief SConf - Manager de fichier de config
///
/// Classe qui gére un fichier de configuration de 
/// la forme: key=value.  
class SConf : public BasicConf
{
public:
    SConf();

    ConfErr Load();
    ConfErr Save();

    ConfErr SetArg(std::string Arg, std::string  value);
    ConfErr GetArg(std::string Arg, std::string& value);

    ConfErr SetFile(std::string file);

    ~SConf();

private:
    bool IsExist(std::string Arg);
    int GetIndex(std::string Arg);

    std::vector<ConfDesc> config;
};

#endif // SCONF_H

