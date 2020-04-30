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

/// @file Bitwise.h
/// @brief Header de Types/Bitwise
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef BITWISE_H
#define BITWISE_H

#include "Defines.h"

Endian GetEndianness();

void SetBit(BYTE& data, BYTE pos, Bit  value);
void GetBit(BYTE  data, BYTE pos, Bit& value);

void RotL(BYTE& data, BYTE shift);
void RotR(BYTE& data, BYTE shift);

#endif // BITWISE_H

