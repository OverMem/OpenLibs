#ifndef NUMTHEORIC_H
#define NUMTHEORIC_H

#include <algorithm>
#include "Boost/boost/random.hpp"
#include "OPEN/Math/Algorithm.h"

const Int q_err = 50;

bool MillerRabin(Int n, Int k);
bool isPrime(Int n);

Int NextPrime(Int m);

#endif // NUMTHEORIC_H

