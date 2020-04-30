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

/// @file Blowfish.h
/// @brief Header de OCL/Blowfish
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef BLOWFISH_H
#define BLOWFISH_H

#include <array>
#include <endian.h>
#include "OPEN/Types/Defines.h"

typedef std::array<DWORD, 2>  BData;
typedef std::array<DWORD, 14> BKey;

/// @brief Blowfish - Encrypteur Blowfish
///
/// Classe qui chiffre et déchiffre avec l'algorithme Blowfish.
class Blowfish
{
public:
    Blowfish(BKey key);

    void Encrypt(BData plain,  BData& cipher);
    void Decrypt(BData cipher, BData& plain);

    ~Blowfish();

private:
    void GenKeys();
    void Reset();

    DWORD F(DWORD W);

    BKey Key;
    std::array<DWORD, 18> P;
    std::array<std::array<DWORD, 256>, 4> SBox;
};

#endif // BLOWFISH_H

