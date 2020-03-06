#include "Defines.h"

/*!
 * @brief Bit affect operator by a Bit
 *
 * @param[in] b : Bit to affect
 * @return Bit reference
 */
Bit& Bit::operator =(Bit& b)
{
    bit = b.bit;

    return *this;
}

/*!
 * @brief Bit affect operator by a boolean
 *
 * @param[in] b : bool to affect
 * @return Bit reference
 */
Bit& Bit::operator =(bool b)
{
    bit = b;

    return *this;
}

/*!
 * @brief Bit ior/affect operator
 *
 * @param[in] b : Bit to ior/affect
 * @return Bit reference
 */
Bit& Bit::operator|=(Bit& b)
{
    bit = bit | b.bit;

    return *this;
}

/*!
 * @brief Bit and/affect operator
 *
 * @param[in] b : Bit to and/affect
 * @return Bit reference
 */
Bit& Bit::operator&=(Bit& b)
{
    bit = bit & b.bit;

    return *this;
}

/*!
 * @brief Bit xor/affect operator
 *
 * @param[in] b : Bit to xor/affect
 * @return Bit reference
 */
Bit& Bit::operator^=(Bit& b)
{
    bit = bit ^ b.bit;

    return *this;
}

/*!
 * @brief Bit not operator
 *
 * @param[in] b : Bit to not
 * @return Bit reference
 */
Bit& Bit::operator~ ()
{
    bit = !bit;

    return *this;
}


/*!
 * @brief Bit ior operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b1 : right Bit
 * @return Bit result
 */
Bit operator|(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit | b2.bit;

    return ret;
}

/*!
 * @brief Bit and operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right Bit
 * @return Bit result
 */
Bit operator&(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit & b2.bit;

    return ret;
}

/*!
 * @brief Bit xor operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right Bit
 * @return Bit result
 */
Bit operator^(Bit& b1, Bit& b2)
{
    Bit ret;

    ret.bit = b1.bit ^ b2.bit;

    return ret;
}

/*!
 * @brief Bit equality operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right Bit
 * @return true if equals, false else
 */
bool operator==(Bit b1, Bit b2)
{
    return (b1.bit == b2.bit);
}

/*!
 * @brief Bit not equality operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right Bit
 * @return true if not equals, false else
 */
bool operator!=(Bit b1, Bit b2)
{
    return ~(b1 == b2);
}

/*!
 * @brief Bit/bool equality operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right bool
 * @return true if equals, false else
 */
bool operator==(Bit b1, bool b2)
{
    return (b1.bit == b2);
}

/*!
 * @brief Bit/bool not equality operator
 *
 * @param[in] b1 : left Bit
 * @param[in] b2 : right bool
 * @return true if not equals, false else
 */
bool operator!=(Bit b1, bool b2)
{
    return ~(b1 == b2);
}

/*!
 * @brief bool/Bit equality operator
 *
 * @param[in] b1 : left bool
 * @param[in] b2 : right Bit
 * @return true if equals, false else
 */
bool operator==(bool b1, Bit b2)
{
    return (b1 == b2.bit);
}

/*!
 * @brief bool/Bit not equality operator
 *
 * @param[in] b1 : left bool
 * @param[in] b2 : right Bit
 * @return true if not equals, false else
 */
bool operator!=(bool b1, Bit b2)
{
    return ~(b1 == b2);
}


/*!
 * @brief Bit stream out operator
 *
 * @param[in] os : ostream reference
 * @param[in] b  : Bit to in
 * @return ostream reference for chained operator
 */
std::ostream& operator<<(std::ostream& os, Bit  b)
{
    std::string temp;

    if(b == 1) temp = "1";
    else       temp = "0";
    os << temp;

    return os;
}

/*!
 * @brief Bit stream in operator
 *
 * @param[in] is : istream reference
 * @param[in] b  : Bit to out
 * @return istream reference for chained operator
 */
std::istream& operator>>(std::istream& is, Bit& b)
{
    std::string temp;

    is >> temp;
    if(temp == "1") b = 1;
    else            b = 0;

    return is;
}

