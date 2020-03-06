#ifndef UTILS_H
#define UTILS_H

/*!
 * @file Utils.h
 * @brief Define utils functions
 * @author RemsPrgm
 * @version 1.0
 */
#include <ctime>
#include <string>
#include <fstream>
#include "OPEN/Types/Convert.h"

char ToChar(BYTE ascii);
BYTE ToAscii(char c);
std::string CompleteInt(int Nbr);
std::string TmToStr(const struct tm *date);
std::string DayToStr(int day, bool type = 0);

DWORD GetFileSize(std::ifstream& file);

#endif // UTILS_H

