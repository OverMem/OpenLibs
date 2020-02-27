#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include "Bitwise.h"

class ByteArray
{
public:
    ByteArray();

    BYTE GetSize();

    template<typename T>
    void Rd(T& data, Bit& ret);
    template<typename T>
    void Wr(T  data);

    ByteArray& operator=(ByteArray& bytes);
    template<typename T>
    ByteArray& operator=(T data);

    BYTE& operator[](BYTE i);

private:
    BYTE *Array;
    BYTE size;

template<typename T>
friend ByteArray& operator<<(ByteArray& bytes, T  data);
template<typename T>
friend ByteArray& operator>>(ByteArray& bytes, T& data);
};


template<typename T>
ByteArray& ByteArray::operator=(T data)
{
    Wr(data);

    return *this;
}


template<typename T>
void ByteArray::Rd(T& data, Bit& ret)
{
    BYTE stop = size;
    BYTE temp;

    if(size > sizeof(T)) stop = sizeof(T);

    data = 0;
    for(BYTE i = 0; i < stop; i++)
    {
        temp = sizeof(T) - i;

        data |= (Array[temp] << (8 * temp));
    }

    if(size != sizeof(T)) ret = 1;
    else                  ret = 0;
}

template<typename T>
void ByteArray::Wr(T  data)
{
    delete[] Array;

    Array = new BYTE[sizeof(T)];
    size  = sizeof(T);

    for(BYTE i = 0; i < size; i++)
    {
        Array[i] = (BYTE)(data >> (8 * i));
    }
}


template<typename T>
ByteArray& operator<<(ByteArray& bytes, T  data)
{
    bytes.Wr(data);

    return bytes;
}

template<typename T>
ByteArray& operator>>(ByteArray& bytes, T& data)
{
    bytes.Rd(data);

    return bytes;
}

#endif // BYTEARRAY_H

