#include "Bitwise.h"

Endian GetEndianness()
{
    int t = 1;

    if(*(char *)&t == 1) return Endian::LENDIAN;
    else                 return Endian::BENDIAN;
}


void SetBit(BYTE& data, BYTE pos, Bit  value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(value == 1) data |=  (1u << Pos);
    else           data &= ~(1u << Pos);
}

void GetBit(BYTE  data, BYTE pos, Bit& value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(data & (1u << Pos)) value = 1;
    else                   value = 0;
}

void RotL(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data << Shift) | (data >> (8 - Shift));
}

void RotR(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data >> Shift) | (data << (8 - Shift));
}

