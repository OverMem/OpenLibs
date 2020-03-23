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

#include "Defines.h"

Bit& Bit::operator =(Bit& b)
{
    bit = b.bit;

    return *this;
}

Bit& Bit::operator =(bool b)
{
    bit = b;

    return *this;
}

Bit& Bit::operator|=(Bit& b)
{
    bit = bit | b.bit;

    return *this;
}

Bit& Bit::operator&=(Bit& b)
{
    bit = bit & b.bit;

    return *this;
}

Bit& Bit::operator^=(Bit& b)
{
    bit = bit ^ b.bit;

    return *this;
}

Bit& Bit::operator~ ()
{
    bit = !bit;

    return *this;
}


Bit operator|(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit | b2.bit;

    return ret;
}

Bit operator&(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit & b2.bit;

    return ret;
}

Bit operator^(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit ^ b2.bit;

    return ret;
}

bool operator==(Bit b1, Bit b2)
{
    return (b1.bit == b2.bit);
}

bool operator!=(Bit b1, Bit b2)
{
    return !(b1 == b2);
}

bool operator==(Bit b1, bool b2)
{
    return (b1.bit == b2);
}

bool operator!=(Bit b1, bool b2)
{
    return !(b1 == b2);
}

bool operator==(bool b1, Bit b2)
{
    return (b1 == b2.bit);
}

bool operator!=(bool b1, Bit b2)
{
    return !(b1 == b2);
}


std::ostream& operator<<(std::ostream& os, Bit  b)
{
    std::string temp;

    if(b == 1) temp = "1";
    else       temp = "0";
    os << temp;

    return os;
}

std::istream& operator>>(std::istream& is, Bit& b)
{
    std::string temp;

    is >> temp;
    if(temp == "1") b = 1;
    else            b = 0;

    return is;
}

