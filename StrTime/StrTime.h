#ifndef STRTIME_H
#define STRTIME_H

#include <ctime>

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

