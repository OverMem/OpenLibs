#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <random>
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Thread.hpp"
#include "SFML/System/Mutex.hpp"
#include "SHA256.h"

const DWORD time_e = 50;

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

