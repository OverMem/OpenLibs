#include "Defines.h"

Bit& Bit::operator =(Bit& b)
{
    bit = b.bit;

    return *this;
}

Bit& Bit::operator =(bool b)
{
    bit = b;

    return *this;
}

Bit& Bit::operator|=(Bit& b)
{
    bit = bit | b.bit;

    return *this;
}

Bit& Bit::operator&=(Bit& b)
{
    bit = bit & b.bit;

    return *this;
}

Bit& Bit::operator^=(Bit& b)
{
    bit = bit ^ b.bit;

    return *this;
}

Bit& Bit::operator~ ()
{
    bit = !bit;

    return *this;
}


Bit operator|(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit | b2.bit;

    return ret;
}

Bit operator&(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit & b2.bit;

    return ret;
}

Bit operator^(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit ^ b2.bit;

    return ret;
}

bool operator==(Bit b1, Bit b2)
{
    return (b1.bit == b2.bit);
}

bool operator!=(Bit b1, Bit b2)
{
    return ~(b1 == b2);
}

bool operator==(Bit b1, bool b2)
{
    return (b1.bit == b2);
}

bool operator!=(Bit b1, bool b2)
{
    return ~(b1 == b2);
}

bool operator==(bool b1, Bit b2)
{
    return (b1 == b2.bit);
}

bool operator!=(bool b1, Bit b2)
{
    return ~(b1 == b2);
}


std::ostream& operator<<(std::ostream& os, Bit  b)
{
    std::string temp;

    if(b == 1) temp = "1";
    else       temp = "0";
    os << temp;

    return os;
}

std::istream& operator>>(std::istream& is, Bit& b)
{
    std::string temp;

    is >> temp;
    if(temp == "1") b = 1;
    else            b = 0;

    return is;
}


/*
std::ostream& operator<<(std::ostream& o_str, SWORD n)
{
    std::string temp_s;
    int digit;

    do
    {
        digit  = n % 10;
        temp_s = std::to_string(digit) + temp_s;
        n = (n - digit) / 10;
    }while(n != 0);

    return o_str << temp_s;
}

std::istream& operator>>(std::istream& i_str, SWORD n)
{
    std::string temp_s;
    int digit;


}


std::ostream& operator<<(std::ostream& o_str, sSWORD n)
{
    std::string temp_s;
    int digit;

    do
    {
        digit  = n % 10;
        temp_s = std::to_string(digit) + temp_s;
        n = (n - digit) / 10;
    }while(n != 0);

    return o_str << temp_s;
}

std::istream& operator>>(std::istream& i_str, sSWORD n)
{
    
}
*/
