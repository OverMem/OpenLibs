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

/// @file RSA.h
/// @brief Header de OCL/RSA
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef RSA_H
#define RSA_h

#include "MP/gmp.h"
#include "MP/gmpxx.h"
#include "Random.h"

typedef mpz_class Int;

/// @brief KeyRSA - Représente une clé RSA
///
/// Structure qui définit une clé publique et privée RSA.
typedef struct
{
    Int N;  //!< Module.
    Int E;  //!< Exposant publique.
    Int U;  //!< Exposant privé.

    WORD S; //!< Taille de la clé.
}KeyRSA;

/// @brief MakeRSA - Générateur de clé RSA
///
/// Classe qui génère une paire de clés RSA.
class MakeRSA
{
public:
    MakeRSA(WORD size = 8192);

    void Gen();
    void GetGen(KeyRSA& key);

private:
    KeyRSA Key;
};

/// @brief RSA - Encrypteur RSA
///
/// Classe qui chiffre et déchiffre avec l'algorithme RSA.
class RSA
{
public:
    RSA(KeyRSA key);

    void Encrypt(Int plain,  Int& cipher);
    void Decrypt(Int cipher, Int& plain);

private:
    KeyRSA Key;
};

#endif // RSA_H

