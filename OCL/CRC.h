#ifndef CRC_H
#define CRC_H

#include <vector>
#include "OPEN/Types/Defines.h"

static bool type16 = true;

void SetType(bool type);

class CRC
{
public:
    CRC();

    WORD  CRC16(std::vector<BYTE> data);
    DWORD CRC32(std::vector<BYTE> data);

private:
    WORD  Invert16(WORD  data, BYTE nbits);
    DWORD Invert32(DWORD data, BYTE nbits);
};

#endif // CRC_H

