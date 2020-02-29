#ifndef BLOWFISH_H
#define BLOWFISH_H

#include <array>
#include <endian.h>
#include "OPEN/Types/Defines.h"

typedef union BWord BWord;

/*
#if __BYTE_ORDER == __BIG_ENDIAN
typedef struct
{
    BYTE B0;
    BYTE B1;
    BYTE B2;
    BYTE B3;
}BBytes;
#endif

#if __BYTE_ORDER == __LITTLE_ENDIAN
typedef struct
{
    BYTE B3;
    BYTE B2;
    BYTE B1;
    BYTE B0;
}BBytes;
#endif

union BWord
{
    BBytes bbytes;
    DWORD  bword;

    BWord& operator=(const BWord& b);
};
*/

typedef std::array<DWORD, 2>  BData;
typedef std::array<DWORD, 14> BKey;

class Blowfish
{
public:
    Blowfish(BKey key);

    void BEncrypt(BData plain,  BData& cipher);
    void BDecrypt(BData cipher, BData& plain);

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

