#include "Random.h"

Random::Random()
{
    Entropy_t = new sf::Thread(&Random::Entropy, this);
    Dispose_t = new sf::Thread(&Random::Dispose, this);
    stop      = false;
    size      = 0;

    Entropy_t->launch();
    Dispose_t->launch();
}


void Random::StartEngine()
{
    if(stop)
    {
        stop = false;
        Entropy_t->launch();
        Dispose_t->launch();
    }
}

void Random::StopEngine ()
{
    if(!stop)
    {
        stop = true;
        Entropy_t->wait();
        Dispose_t->wait();
    }
}

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


Random::~Random()
{
    StopEngine();
}

