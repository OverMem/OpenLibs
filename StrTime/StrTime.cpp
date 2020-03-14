#include "StrTime.h"

StrTime::StrTime()
{
    Time_t = 0;
}

void StrTime::GetTime(std::string& str_t, bool type)
{
    char buf[18];
    struct tm* timeinfo;

    timeinfo = localtime(&Time_t);

    if(type == 0) strftime(buf, 18, "%d/%m/%y %H:%M:%S", timeinfo);
    else          strftime(buf, 18, "%m/%d/%y %H:%M:%S", timeinfo);
    
    str_t = buf;
}

void StrTime::SetTime(std::time_t Time_T)
{
    Time_t = Time_T;
}

