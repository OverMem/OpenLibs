#include "StrTime.h"

/*!
 * @brief Constructor
 *
 * Constructor of class StrTime.
 */
StrTime::StrTime()
{
    Time_t = 0;
}

/*!
 * @brief Get the Date/Time
 *
 * Method to get formated Date/Time.
 *
 * @param[out] str_t : string reference
 * @param[in] type : format type (0 for fr / 1 for en)
 * @return void
 */
void StrTime::GetTime(std::string& str_t, bool type)
{
    char buf[18];
    struct tm* timeinfo;

    timeinfo = localtime(&Time_t);

    if(type == 0) strftime(buf, 18, "%d/%m/%y %H:%M:%S", timeinfo);
    else          strftime(buf, 18, "%m/%d/%y %H:%M:%S", timeinfo);
    
    str_t = buf;
}

/*!
 * @brief Set the Date/Time
 *
 * Method to set the timestamp.
 *
 * @param[in] Time_T : timestamp to set
 * @return void
 */
void StrTime::SetTime(std::time_t Time_T)
{
    Time_t = Time_T;
}

