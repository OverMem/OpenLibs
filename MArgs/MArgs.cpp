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

#include "MArgs.h"

MArgs::MArgs(int nargs, char *args[])
{
    std::string temp, key, value;
    std::regex pattern { "^--?[A-Za-z_]+=[A-Za-z0-9_]+$" };

    for(int i = 0; i < nargs; i++)
    {
        temp = args[i];

        if(std::regex_match(temp, pattern) == true)
        {
            std::istringstream Strs(temp);

            getline(Strs, key, '=');
            getline(Strs, value, '=');

	        Arg[key] = value;
        }
    }
}


int MArgs::GetArg(std::string name, std::string& value)
{
    if(IsExist(name)) value = Arg[name];
    else              return 1;

    return 0;
}

bool MArgs::IsExist(std::string name)
{
    if(Arg.find(name) != Arg.end()) return true;
    else                            return false;
}

