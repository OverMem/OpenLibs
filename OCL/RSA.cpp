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

#include "RSA.h"

MakeRSA::MakeRSA(WORD size)
{
    Key.S = size;
}


void MakeRSA::Gen()
{
    Int p, q, P, Q, M, e, u, v, pgcd, k = 1;
    Random randr;
    gmp_randstate_t state_r;
    DWORD seed_mt;

    randr.GetRand(&seed_mt, 1);
    randr.StopEngine();

    gmp_randinit_mt(state_r);
    gmp_randseed_ui(state_r, seed_mt);

    mpz_rrandomb(p.get_mpz_t(), state_r, Key.S / 2);
    mpz_rrandomb(q.get_mpz_t(), state_r, Key.S / 2);

    mpz_nextprime(P.get_mpz_t(), p.get_mpz_t());
    mpz_nextprime(Q.get_mpz_t(), q.get_mpz_t());

    M = (P - 1) * (Q - 1);


    e = 65537;
    do
    {
        mpz_gcdext(pgcd.get_mpz_t(), u.get_mpz_t(), v.get_mpz_t(), e.get_mpz_t(), M.get_mpz_t());
    }while(pgcd != 1);

    if(u <= 2 || u >= M)
    {
        if(u <= 2) k = ((2 - u) / (-M)) - 1;
        if(u >= M) k = ((M - u) / (-M)) + 1;

        u = u - k * M;
    }


    Key.N = P * Q;
    Key.E = e;
    Key.U = u;
}

void MakeRSA::GetGen(KeyRSA& key)
{
    key.N = Key.N;
    key.E = Key.E;
    key.U = Key.U;
    key.S = Key.S;
}



RSA::RSA(KeyRSA key)
{
    Key.N = key.N;
    Key.E = key.E;
    Key.U = key.U;

    Key.S = key.S;
}


void RSA::Encrypt(Int plain,  Int& cipher)
{
    mpz_powm(cipher.get_mpz_t(), plain.get_mpz_t(), Key.E.get_mpz_t(), Key.N.get_mpz_t());
}

void RSA::Decrypt(Int cipher, Int& plain)
{
    mpz_powm(plain.get_mpz_t(), cipher.get_mpz_t(), Key.U.get_mpz_t(), Key.N.get_mpz_t());
}

