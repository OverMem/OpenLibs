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

#ifndef LOGGR_H
#define LOGGR_H

#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>
#include <iomanip>
#include "OPEN/Types/Convert.h"

typedef struct
{
    std::string time_s;
    std::string msg;

    SWORD nlog;
}LogDesc;

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

