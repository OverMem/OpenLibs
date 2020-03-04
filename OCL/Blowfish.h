#ifndef BLOWFISH_H
#define BLOWFISH_H

#include <array>
#include <endian.h>
#include "OPEN/Types/Defines.h"

typedef std::array<DWORD, 2>  BData;
typedef std::array<DWORD, 14> BKey;

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

