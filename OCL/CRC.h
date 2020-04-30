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

/// @file CRC.h
/// @brief Header de OCL/CRC
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef CRC_H
#define CRC_H

#include <vector>
#include "OPEN/Types/Defines.h"

static bool type16 = true;

void SetType(bool type);

/// @brief CRC - Calculateur de somme de contrôle CRC
///
/// Classe qui calcule une somme de contrôle CRC avec les 
/// standards ANSI, CCITT et Ethernet.
class CRC
{
public:
    CRC();

    WORD  CRC16(std::vector<BYTE> data);
    DWORD CRC32(std::vector<BYTE> data);

private:
    WORD  Invert16(WORD  data, BYTE nbits);
    DWORD Invert32(DWORD data, BYTE nbits);
};

#endif // CRC_H

