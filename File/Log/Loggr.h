#ifndef LOGGR_H
#define LOGGR_H

#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>
#include <iomanip>
#include "OPEN/Types/Convert.h"

typedef struct
{
    std::string time_s;
    std::string msg;

    SWORD nlog;
}LogDesc;

class Loggr
{
public:
    Loggr();

    int Load(SWORD  n, LogDesc& desc);
    int Save(SWORD& n, std::string msg);

    int SetFile(std::string file);

    ~Loggr();

private:
    std::vector<LogDesc> logs;
    std::string File;

    bool load;
    SWORD nlogs;
};

#endif // LOGGR_H

