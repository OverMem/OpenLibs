#ifndef TYPES_H
#define TYPES_H

#include <string>
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

typedef std::string Str;

/*!
 * @struct Bit
 * @brief Bit define
 *
 * Bit is a struct who represent a single bit and define a lot of operators for use it.
 */
struct Bit
{
    Bit& operator =(Bit& b);
    Bit& operator =(bool b);
    Bit& operator|=(Bit& b);
    Bit& operator&=(Bit& b);
    Bit& operator^=(Bit& b);
    Bit& operator~ ();

private:
    bool bit; /*!< Bit value. */

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

/*!
 * @enum Endian
 * @brief Endiannes define
 *
 * Endian is an enum who represent a type of endianness.
 */
typedef enum
{
    LENDIAN = 0, /*!< Little endian. */
    BENDIAN = 1  /*!< Big endian. */
}Endian;

#endif // TYPES_H

