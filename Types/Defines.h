#ifndef TYPES_H
#define TYPES_H

#include <cstdint>
#include <inttypes.h>
#include <iostream>

typedef struct Bit Bit;

typedef uint8_t      BYTE;
typedef uint16_t     WORD;
typedef uint32_t    DWORD;
typedef uint64_t    QWORD;
typedef __uint128_t SWORD;

typedef int8_t      sBYTE;
typedef int16_t     sWORD;
typedef int32_t    sDWORD;
typedef int64_t    sQWORD;
typedef __int128_t sSWORD;

struct Bit
{
    Bit& operator =(Bit& b);
    Bit& operator =(bool b);
    Bit& operator|=(Bit& b);
    Bit& operator&=(Bit& b);
    Bit& operator^=(Bit& b);
    Bit& operator~ ();

private:
    bool bit;

friend Bit operator|(Bit& b1, Bit& b2);
friend Bit operator&(Bit& b1, Bit& b2);
friend Bit operator^(Bit& b1, Bit& b2);

friend bool operator==(Bit b1, Bit b2);
friend bool operator!=(Bit b1, Bit b2);
friend bool operator==(Bit b1, bool b2);
friend bool operator!=(Bit b1, bool b2);
friend bool operator==(bool b1, Bit b2);
friend bool operator!=(bool b1, Bit b2);

friend std::ostream& operator<<(std::ostream& os, Bit  b);
friend std::istream& operator>>(std::istream& is, Bit& b);
};

typedef enum
{
    LENDIAN = 0,
    BENDIAN = 1
}Endian;
/*
std::ostream& operator<<(std::ostream& o_str, SWORD n);
std::istream& operator>>(std::istream& i_str, SWORD n);

std::ostream& operator<<(std::ostream& o_str, sSWORD n);
std::istream& operator>>(std::istream& i_str, sSWORD n);
*/
#endif // TYPES_H

