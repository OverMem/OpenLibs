#include "ByteArray.h"

ByteArray::ByteArray()
{
    Wr(BYTE(0));
}

BYTE ByteArray::GetSize()
{
    return size;
}

ByteArray& ByteArray::operator=(ByteArray& bytes)
{
    delete[] Array;

    Array = new BYTE[bytes.GetSize()];
    size  = bytes.GetSize();

    for(BYTE i = 0; i < size; i++)
    {
        Array[i] = bytes[i];
    }

    return *this;
}

BYTE& ByteArray::operator[](BYTE i)
{
    if(i < size) return Array[i];
    else         return Array[size - 1];
}

