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

#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <cstdint>
#include <inttypes.h>
#include <iostream>

typedef struct Bit Bit;

typedef uint8_t      BYTE;
typedef uint16_t     WORD;
typedef uint32_t    DWORD;
typedef uint64_t    QWORD;
typedef __uint128_t SWORD;

typedef int8_t      sBYTE;
typedef int16_t     sWORD;
typedef int32_t    sDWORD;
typedef int64_t    sQWORD;
typedef __int128_t sSWORD;

typedef std::string Str;

struct Bit
{
    Bit& operator =(Bit& b);
    Bit& operator =(bool b);
    Bit& operator|=(Bit& b);
    Bit& operator&=(Bit& b);
    Bit& operator^=(Bit& b);
    Bit& operator~ ();

private:
    bool bit;

friend Bit operator|(Bit& b1, Bit& b2);
friend Bit operator&(Bit& b1, Bit& b2);
friend Bit operator^(Bit& b1, Bit& b2);

friend bool operator==(Bit b1, Bit b2);
friend bool operator!=(Bit b1, Bit b2);
friend bool operator==(Bit b1, bool b2);
friend bool operator!=(Bit b1, bool b2);
friend bool operator==(bool b1, Bit b2);
friend bool operator!=(bool b1, Bit b2);

friend std::ostream& operator<<(std::ostream& os, Bit  b);
friend std::istream& operator>>(std::istream& is, Bit& b);
};

typedef enum
{
    LENDIAN = 0,
    BENDIAN = 1
}Endian;

#endif // TYPES_H

