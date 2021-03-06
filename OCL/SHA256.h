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

/// @file SHA256.h
/// @brief Header de OCL/SHA256
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef SHA256_H
#define SHA256_H

#include <array>
#include "OPEN/Types/Defines.h"

typedef std::array<DWORD, 16> DataHash;
typedef std::array<DWORD, 8>  Hash;

const std::array<DWORD, 64> ConstK = { 0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
                                       0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
                                       0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
                                       0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
                                       0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
                                       0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
                                       0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
                                       0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2, };

/// @brief SHA256 - Hacheur SHA-256
///
/// Classe qui calcule un haché avec l'algorithme SHA-256.
class SHA256
{
public:
    SHA256();

    void Hashr(DataHash data, Hash& H);

private:
    DWORD SHR(DWORD  x, BYTE n);
    DWORD ROTR(DWORD x, BYTE n);

    DWORD Ch(DWORD  x, DWORD y, DWORD z);
    DWORD Maj(DWORD x, DWORD y, DWORD z);

    DWORD Sum0(DWORD x);
    DWORD Sum1(DWORD x);
    DWORD Sig0(DWORD x);
    DWORD Sig1(DWORD x);

    std::array<DWORD, 64> K;
    DataHash M;
};

#endif // SHA256_H

