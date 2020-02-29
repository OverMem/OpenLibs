#include <iostream>
#include "Blowfish.h"

int main(void)
{
    BData data_p, data_c, data_r;
    BKey key;
    //QWORD Data_p, Data_c, Data_r;

    for(BYTE i = 0; i < 14; i++)
    {
        key[i] = i + 0xBA124547;
    }

    data_p[0] = 0x00000001;
    data_p[1] = 0x00000002;

    Blowfish bl_cipher(key);

    bl_cipher.BEncrypt(data_p, data_c);
    bl_cipher.BDecrypt(data_c, data_r);

    //Data_p = ((QWORD)data_p[0].bword << 32) ^ data_p[1].bword;
    //Data_c = ((QWORD)data_c[0].bword << 32) ^ data_c[1].bword;
    //Data_r = ((QWORD)data_r[0].bword << 32) ^ data_r[1].bword;

    std::cout << "Plain: "    << data_p[0] << " / " << data_p[1] <<std::endl;
    std::cout << "Cipher: "   << data_c[0] << " / " << data_c[1] <<std::endl;
    std::cout << "Retrieve: " << data_r[0] << " / " << data_r[1] <<std::endl;

    return 0;
}

