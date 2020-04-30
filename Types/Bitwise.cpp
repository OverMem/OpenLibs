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

/// @file Bitwise.cpp
/// @brief Source de Types/Bitwise
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "Bitwise.h"

/// @brief GetEndianness - Lectude de l'endianness du processeur cible
///
/// @Return Énumération de type Endian.
Endian GetEndianness()
{
    int t = 1;

    if(*(char *)&t == 1) return Endian::LENDIAN;
    else                 return Endian::BENDIAN;
}


/// @brief SetBit - Modification d'un bit d'un octet
///
/// @param data: Octet écrit/à écrire
/// @param pos: Position du bit à modifier
/// @param value: Valeur du bit
void SetBit(BYTE& data, BYTE pos, Bit  value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(value == 1) data |=  (1u << Pos);
    else           data &= ~(1u << Pos);
}

/// @brief GetBit - Lecture d'un bit d'un octet
///
/// @param data: Octet à lire
/// @param pos: Position du bit à lire
/// @param value: Valeur du bit lue
void GetBit(BYTE  data, BYTE pos, Bit& value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(data & (1u << Pos)) value = 1;
    else                   value = 0;
}

/// @brief RotL - Implémentation de ROTL sur un octet
///
/// @param data: Octet à modifier
/// @param shift: Nombre de bits à tourner
void RotL(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data << Shift) | (data >> (8 - Shift));
}

/// @brief RotR - Implémentation de ROTR sur un octet
///
/// @param data: Octet à tourner
/// @param shift: Nombre de bits à tourner
void RotR(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data >> Shift) | (data << (8 - Shift));
}

