#include "Bitwise.h"

/*!
 * @brief Get system endiannes
 *
 * Function for get the endiannesss of the system.
 *
 * @return Endiann struct represent the sys endianness
 */
Endian GetEndianness()
{
    int t = 1;

    if(*(char *)&t == 1) return Endian::LENDIAN;
    else                 return Endian::BENDIAN;
}


/*!
 * @brief Set bit bitwise
 *
 * Function for set a bit in a BYTE var.
 *
 * @param[out] data : BYTE to set bit
 * @param[in] pos   : position of bit to set
 * @param[in] value : Bit value to set
 * @return void
 */
void SetBit(BYTE& data, BYTE pos, Bit  value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(value == 1) data |=  (1u << Pos);
    else           data &= ~(1u << Pos);
}

/*!
 * @brief Get bit bitwise
 *
 * Function for get a bit in a BYTE var.
 *
 * @param[in] data   : BYTE to get bit
 * @param[in] pos    : position of bit to get
 * @param[out] value : Bit refeerence to bit getted
 * @return void
 */
void GetBit(BYTE  data, BYTE pos, Bit& value)
{
    BYTE Pos = pos;

    if(pos > 7) Pos = 7;

    if(data & (1u << Pos)) value = 1;
    else                   value = 0;
}

/*!
 * @brief Rotation left bitwise
 *
 * Function for rotate left a BYTE value.
 *
 * @param[out] data : BYTE to rotate
 * @param[in] shift : number of bits to rotate left
 * @return void
 */
void RotL(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data << Shift) | (data >> (8 - Shift));
}

/*!
 * @brief Rotation right bitwise
 *
 * Function to rotate right a BYTE value.
 *
 * @param[out] data : BYTE to rotate
 * @param[in] shift : number of bits to rotate right
 * @return void
 */
void RotR(BYTE& data, BYTE shift)
{
    BYTE Shift = shift;

    if(shift > 7) Shift = 7;

    data = (data >> Shift) | (data << (8 - Shift));
}

