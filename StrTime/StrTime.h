#ifndef STRTIME_H
#define STRTIME_H

/*!
 * @file StrTime.h
 * @brief Represent a time in a string
 * @author RemsPrgm
 * @version 1.0
 */
#include <string>
#include <ctime>

/*!
 * @class StrTime
 * @brief Class represent a time
 *
 * The class manage format by strftime and can use french/english format.
 */
class StrTime
{
public:
    StrTime();

    void GetTime(std::string& str_t, bool type = 0);
    void SetTime(std::time_t Time_T);

private:
    std::time_t Time_t;
};

#endif // STRTIME_H

