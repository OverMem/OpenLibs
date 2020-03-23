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

#include "Bitwise.h"

Endian GetEndianness()
{
    int t = 1;

    if(*(char *)&t == 1) return Endian::LENDIAN;
    else                 return Endian::BENDIAN;
}


void SetBit(BYTE& data, BYTE pos, Bit  value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(value == 1) data |=  (1u << Pos);
    else           data &= ~(1u << Pos);
}

void GetBit(BYTE  data, BYTE pos, Bit& value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(data & (1u << Pos)) value = 1;
    else                   value = 0;
}

void RotL(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data << Shift) | (data >> (8 - Shift));
}

void RotR(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data >> Shift) | (data << (8 - Shift));
}

