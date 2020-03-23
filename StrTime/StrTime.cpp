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

#include "StrTime.h"

StrTime::StrTime()
{
    Time_t = 0;
}

void StrTime::GetTime(std::string& str_t, bool type)
{
    char buf[18];
    struct tm* timeinfo;

    timeinfo = localtime(&Time_t);

    if(type == 0) strftime(buf, 18, "%d/%m/%y %H:%M:%S", timeinfo);
    else          strftime(buf, 18, "%m/%d/%y %H:%M:%S", timeinfo);
    
    str_t = buf;
}

void StrTime::SetTime(std::time_t Time_T)
{
    Time_t = Time_T;
}

