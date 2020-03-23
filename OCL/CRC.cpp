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

#include "CRC.h"

void SetType(bool type)
{
    type16 = type;
}


CRC::CRC()
{
}


WORD  CRC::CRC16(std::vector<BYTE> data)
{
    WORD  crc, byte, mix;
    DWORD len = data.size();

    if(len == 0) return 0;

    if(type16)
    {
        crc = 0x0000;

        for(QWORD i = 0; i < len; ++i)
        {
            byte = Invert16(data[i], 8);
            crc ^= byte << 8;

            for(BYTE j = 0; j < 8; ++j)
            {
                mix = crc & 0x8000;
                crc = (crc << 1);

                if(mix) crc ^= 0x8005;
            }
        }

        return Invert16(crc, 16);
    }
    else
    {
        crc = 0xFFFF;

        for(QWORD i = 0; i < len; ++i)
        {
            byte = data[i];
            crc ^= byte << 8;

            for(BYTE j = 0; j < 8; ++j)
            {
                mix = crc & 0x8000;
                crc = (crc << 1);

                if(mix) crc ^= 0x1021;
            }
        }

        return crc;
    }
}

DWORD CRC::CRC32(std::vector<BYTE> data)
{
    DWORD crc = 0xFFFFFFFF, byte, mix;
    DWORD len = data.size();

    if(len == 0) return 0;

    for(QWORD i = 0; i < len; ++i)
    {
        byte = Invert32(data[i], 8);
        crc ^= byte << 24;

        for(BYTE j = 0; j < 8; ++j)
        {
            mix = crc & 0x80000000;
            crc = (crc << 1);

            if(mix) crc ^= 0x04C11DB7;
        }
    }

    return Invert32(crc, 32) ^ 0xFFFFFFFF;
}


WORD  CRC::Invert16(WORD  data, BYTE nbits)
{
    WORD ret = 0;

    for(WORD i = 0; i < nbits; ++i)
    {
        if(data & 1)
        {
            ret |= 1 << ((nbits - 1) - i);
        }

        data >>= 1;
    }

    return ret;
}

DWORD CRC::Invert32(DWORD data, BYTE nbits)
{
    DWORD ret = 0;

    for(WORD i = 0; i < nbits; ++i)
    {
        if(data & 1)
        {
            ret |= 1 << ((nbits - 1) - i);
        }

        data >>= 1;
    }

    return ret;
}

