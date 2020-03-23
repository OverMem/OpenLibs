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

#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <string>
#include <fstream>
#include "OPEN/Types/Convert.h"

char ToChar(BYTE ascii);
BYTE ToAscii(char c);
std::string CompleteInt(int Nbr);
std::string TmToStr(const struct tm *date);
std::string DayToStr(int day, bool type = 0);

DWORD GetFileSize(std::ifstream& file);

#endif // UTILS_H

