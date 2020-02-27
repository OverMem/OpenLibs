#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <string>
#include "OPEN/Types/Convert.h"

char ToChar(BYTE ascii);
BYTE ToAscii(char c);
std::string CompleteInt(int Nbr);
std::string TmToStr(const struct tm *date);
std::string DayToStr(int day, bool type = 0);

#endif // UTILS_H

