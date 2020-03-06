#ifndef BITWISE_H
#define BITWISE_H

/*!
 * @file Bitwise.h
 * @brief Some functions for manipulate bits in types
 * @author RemsPrgm
 * @version 1.0
 */
#include "Defines.h"

Endian GetEndianness();

void SetBit(BYTE& data, BYTE pos, Bit  value);
void GetBit(BYTE  data, BYTE pos, Bit& value);

void RotL(BYTE& data, BYTE shift);
void RotR(BYTE& data, BYTE shift);

#endif // BITWISE_H

