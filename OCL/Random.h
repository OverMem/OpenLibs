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

/// @file Random.h
/// @brief Header de OCL/Random
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <random>
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Thread.hpp"
#include "SFML/System/Mutex.hpp"
#include "SHA256.h"

const DWORD time_e = 50;

/// @brief Random - Générateur de nombres pseudo-aléatoires cryptographique
///
/// Classe qui génére des nombres pseudo-aléatoires de 32 bits. 
/// Architecture proche de Fortuna ou Yarrow => générateur cryptographique.
class Random
{
public:
    Random();

    void StartEngine();
    void StopEngine ();
    bool GetRand(DWORD* Rand, BYTE len, bool strict = true);

    ~Random();

private:
    void Entropy();
    void Dispose();

    sf::Thread *Entropy_t;
    sf::Thread *Dispose_t;
    sf::Mutex  lockr;
    bool stop;

    SHA256 Hashr;
    DWORD size;

    std::vector<DWORD> entropy;
    std::vector<DWORD> data;
};

#endif // RANDOM_H

