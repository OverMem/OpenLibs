#include "SHA256.h"

SHA256::SHA256()
{
    for(BYTE i = 0; i < 64; i++) K[i] = ConstK[i];
}

void SHA256::Hashr(DataHash data, Hash& H)
{
    DWORD H0, H1, H2, H3, H4, H5, H6, H7;
    DWORD a, b, c, d, e, f, g, h;
    DWORD T1, T2;
    std::array<DWORD, 64> W;

    H0 = 0x6A09E667;
    H1 = 0xBB67AE85;
    H2 = 0x3C6EF372;
    H3 = 0xA54FF53A;
    H4 = 0x510E527F;
    H5 = 0x9B05688C;
    H6 = 0x1F83D9AB;
    H7 = 0x5BE0CD19;

    for(BYTE i = 0; i < 16; i++) M[i] = data[i];

    for(BYTE t = 0; t < 64; t++)
    {
        if(t <= 15)
        {
            W[t] = M[t];
        }
        else
        {
            W[t] = Sig1(W[t - 2]) + W[t - 7] + Sig0(W[t - 15]) + W[t - 16];
        }
    }

    a = H0;
    b = H1;
    c = H2;
    d = H3;
    e = H4;
    f = H5;
    g = H6;
    h = H7;

    for(BYTE t = 0; t < 64; t++)
    {
        T1 = h + Sum1(e) + Ch(e, f, g) + K[t] + W[t];
        T2 = Sum0(a) + Maj(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    H0 = a + H0;
    H1 = b + H1;
    H2 = c + H2;
    H3 = d + H3;
    H4 = e + H4;
    H5 = f + H5;
    H6 = g + H6;
    H7 = h + H7;

    H[0] = H0;
    H[1] = H1;
    H[2] = H2;
    H[3] = H3;
    H[4] = H4;
    H[5] = H5;
    H[6] = H6;
    H[7] = H7;
}


DWORD SHA256::SHR(DWORD  x, BYTE n)
{
    return x >> n;
}

DWORD SHA256::ROTR(DWORD x, BYTE n)
{
    return (x >> n) | (x << (32 - n));
}


DWORD SHA256::Ch(DWORD  x, DWORD y, DWORD z)
{
    return (x & y) ^ ((~x) & z);
}

DWORD SHA256::Maj(DWORD x, DWORD y, DWORD z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}


DWORD SHA256::Sum0(DWORD x)
{
    return ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
}

DWORD SHA256::Sum1(DWORD x)
{
    return ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
}

DWORD SHA256::Sig0(DWORD x)
{
    return ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3);
}

DWORD SHA256::Sig1(DWORD x)
{
    return ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10);
}

