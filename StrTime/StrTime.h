﻿/*
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

/// @file StrTime.h
/// @brief Header de StrTime
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef STRTIME_H
#define STRTIME_H

#include <string>
#include <ctime>

/// @brief StrTime - Convertisseur temps/string
///
/// Classe qui convertit un temps en une chaîne de charactères.
class StrTime
{
public:
    StrTime();

    void GetTime(std::string& str_t, bool type = 0);
    void SetTime(std::time_t Time_T);

private:
    std::time_t Time_t;
};

#endif // STRTIME_H

