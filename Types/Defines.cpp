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

/// @file Defines.cpp
/// @brief Source de Types/Defines
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "Defines.h"

/// @brief operator= - Opérateur d'affection Bit <= Bit
///
/// @param b: Bit à affecter
///
/// @return Référence sur le bit affecté.
Bit& Bit::operator =(Bit& b)
{
    bit = b.bit;

    return *this;
}

/// @brief operator= - Opérateur d'affectation Bit <= bool
///
/// @param b: bool à affecter
///
/// @return Référence sur le bit affecté.
Bit& Bit::operator =(bool b)
{
    bit = b;

    return *this;
}

/// @brief operator|= - Opérateur OR-affect Bit <= Bit
///
/// @param b: Bit à affecter
///
/// @return Référence sur le Bit affecté.
Bit& Bit::operator|=(Bit& b)
{
    bit = bit | b.bit;

    return *this;
}

/// @brief operator&= - Opérateur AND-affect Bit <= Bit
///
/// @param b: Bit à affecter
///
/// @return Référence sur le Bit affecté.
Bit& Bit::operator&=(Bit& b)
{
    bit = bit & b.bit;

    return *this;
}

/// @brief operator^= - Opérateur XOR-affect Bit <= Bit
///
/// @param b: Bit à affecter
///
/// @return Référence sur le Bit affecté.
Bit& Bit::operator^=(Bit& b)
{
    bit = bit ^ b.bit;

    return *this;
}

/// @brief operator~ - Opérateur NOT sur Bit
///
/// @return Référence sur le Bit affecté.
Bit& Bit::operator~ ()
{
    bit = !bit;

    return *this;
}


/// @brief operator| - Opérateur OR entre Bit
///
/// @param b1: Bit de gauche
/// @param b2: Bit de droite
///
/// @return Bit résultant du OR.
Bit operator|(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit | b2.bit;

    return ret;
}

/// @brief operator& - Opérateur AND entre Bit
///
/// @param b1: Bit de gauche
/// @param b2: Bit de droite
///
/// @return Bit résultant du AND.
Bit operator&(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit & b2.bit;

    return ret;
}

/// @brief operator^ - Opérateur XOR entre Bit
///
/// @param b1: Bit de gauche
/// @param b2: Bit de droite
///
/// @return Bit résultant du XOR.
Bit operator^(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit ^ b2.bit;

    return ret;
}

/// @brief operator== - Opérateur d'égalité entre Bit
///
/// @param b1: Bit de gauche
/// @param b2: Bit de droite
///
/// @return True si a = b, false sinon.
bool operator==(Bit b1, Bit b2)
{
    return (b1.bit == b2.bit);
}

/// @brief operator!= - Opérateur d'inégalité entre Bit
///
/// @param b1: Bit de gauche
/// @param b2: Bit de droite
///
/// @return True si a != b, false sinon.
bool operator!=(Bit b1, Bit b2)
{
    return !(b1 == b2);
}

/// @brief operator== - Opérateur d'égalité (Bit == bool)
///
/// @param b1: Bit de gauche
/// @param b2: bool de droite
///
/// @return True si a = b, false sinon.
bool operator==(Bit b1, bool b2)
{
    return (b1.bit == b2);
}

/// @brief operator!= - Opérateur d'inégalité (Bit != bool)
///
/// @param b1: Bit de gauche 
/// @param b2: bool de droite
///
/// @return True si a != b, false sinon.
bool operator!=(Bit b1, bool b2)
{
    return !(b1 == b2);
}

/// @brief operator== - Opérateur d'égalité (bool == Bit)
///
/// @param b1: bool de gauche
/// @param b2: Bit de droite
///
/// @return True si a = b, false sinon.
bool operator==(bool b1, Bit b2)
{
    return (b1 == b2.bit);
}

/// @brief operator!= - Opérateur d'inégalité (bool != Bit)
///
/// @param b1: bool de gauche
/// @param b2: Bit de droite
///
/// @return True si a != b, false sinon.
bool operator!=(bool b1, Bit b2)
{
    return !(b1 == b2);
}


/// @brief operator<< - Opérateur de flux sortant sur Bit
///
/// @param os: Flux sortant
/// @param b: Bit à sortir
///
/// @return Référence sur le flux sortant.
std::ostream& operator<<(std::ostream& os, Bit  b)
{
    std::string temp;

    if(b == 1) temp = "1";
    else       temp = "0";
    os << temp;

    return os;
}

/// @brief operator>> - Opérateur de flux entrant sur Bit
///
/// @param is: Flux entrant
/// @param b: Bit à entrer
///
/// @return Référence sur le flux entrant.
std::istream& operator>>(std::istream& is, Bit& b)
{
    std::string temp;

    is >> temp;
    if(temp == "1") b = 1;
    else            b = 0;

    return is;
}

