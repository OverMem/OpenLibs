#ifndef MATH_DEFINES_H
#define MATH_DEFINES_H

#include <sstream>
#include "Boost/boost/multiprecision/cpp_int.hpp"

typedef boost::multiprecision::cpp_int Int;

Int operator<<(const Int& a, const Int& b);
Int operator>>(const Int& a, const Int& b);

Int& operator<<=(Int& a, const Int& b);
Int& operator>>=(Int& a, const Int& b);

#endif // MATH_DEFINES_H

