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

/// @file Random.cpp
/// @brief Source de OCL/Random
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "Random.h"

/// @brief Random - Constructeur
///
/// Constructeur de la classe Random
Random::Random()
{
    Entropy_t = new sf::Thread(&Random::Entropy, this);
    Dispose_t = new sf::Thread(&Random::Dispose, this);
    stop      = false;
    size      = 0;

    Entropy_t->launch();
    Dispose_t->launch();
}


/// @brief StartEngine - Démarrage du Moteur d'entropie
///
/// @note Le Moteur d'aléa est composé d'un Collecteur d'entropie et d'un Hacheur (SHA-256)
/// Permet de mettre en marche le Moteur d'aléa si celui-ci a été arrêté.
void Random::StartEngine()
{
    if(stop)
    {
        stop = false;
        Entropy_t->launch();
        Dispose_t->launch();
    }
}

/// @brief StopEngine - Extinction du Moteur d'entropie
///
/// Permet d'arrêter le Moteur d'aléa si celui-ci est en marche.
void Random::StopEngine ()
{
    if(!stop)
    {
        stop = true;
        Entropy_t->wait();
        Dispose_t->wait();
    }
}

/// @brief GetRand - Génération de nombres pseudo-aléatoires
///
/// @param Rand: Tableau des nombres générés
/// @param len: Nombre de pseudo-aléatoires à générer
/// @param strict: Blocage de la génaration (true: attend suffisament d'entropie / false: n'attends pas)
///
/// @return True si la génération a réussi, false sinon.
bool Random::GetRand(DWORD* Rand, BYTE len, bool strict)
{
    if(strict)
    {
        while(1)
        {
            lockr.lock();

            if(size >= len)
            {
                lockr.unlock();
                break;
            }

            lockr.unlock();

            sf::sleep(sf::milliseconds(time_e));
        }
    }
    else
    {
        lockr.lock();

        if(size < len)
        {
            lockr.unlock();

            return false;
        }

        lockr.unlock();
    }

    lockr.lock();

    for(BYTE i = 0; i < len; i++)
    {
        Rand[i] = data[(size - 1) - i];
        data.pop_back();
    }

    size -= len;
    lockr.unlock();

    return true;
}

void Random::Entropy()
{
    std::random_device rd("/dev/random");

    while(1)
    {
        lockr.lock();

        if(stop)
        {
            lockr.unlock();
            break;
        }

        for(BYTE i = 0; i < 4; i++) entropy.push_back(rd());
        lockr.unlock();

        sf::sleep(sf::milliseconds(time_e));
    }
}

void Random::Dispose()
{
    DataHash temp_h;
    Hash     temp_H;
    DWORD    len_e;

    while(1)
    {
        lockr.lock();

        if(stop)
        {
            lockr.unlock();
            break;
        }

        len_e = entropy.size();

        if(len_e >= 16)
        {
            for(BYTE i = 0; i < 16; i++)
            {
                temp_h[i] = entropy[(len_e - 1) - i];
                entropy.pop_back();
            }

            Hashr.Hashr(temp_h, temp_H);

            for(BYTE i = 0; i < 8; i++) data.push_back(temp_H[i]);

            size += 8;
        }

        lockr.unlock();

        sf::sleep(sf::milliseconds(time_e));
    }
}


/// @brief ~Random - Destructeur
///
/// Destructeur de la classe Random.
Random::~Random()
{
    StopEngine();
}

