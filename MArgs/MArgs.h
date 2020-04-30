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

/// @file MArgs.h
/// @brief Header de MArgs
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef MARGS_H
#define MARGS_H

#include <regex>
#include <sstream>
#include <map>

/// @brief MArgs - Manager d'arguments de main()
///
/// Classe qui gère les arguments de la fonction main.
class MArgs
{
public:
    MArgs(int nargs, char *args[]);
    
    int GetArg(std::string name, std::string& value);

private:
    bool IsExist(std::string name);

    std::map<std::string, std::string> Arg;
};

#endif // MARGS_H

