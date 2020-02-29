#ifndef BASICCONF_H
#define BASICCONF_H

#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>
#include "OPEN/Types/Defines.h"

enum class ConfErr : sBYTE
{
    Name  = -1,
    File  = -2,
    Regex = -3,
    Exist = -4,
    NoErr =  0
};

typedef struct
{
    std::string Key;
    std::string Value;
}ConfDesc;

class BasicConf
{
public:
    BasicConf();

    QWORD GetHandle();

    virtual ConfErr Load() =0;
    virtual ConfErr Save() =0;

    ConfErr SetFile(std::string file);

    virtual ConfErr SetArg(std::string Arg, std::string  value) =0;
    virtual ConfErr GetArg(std::string Arg, std::string& value) =0;

    virtual ~BasicConf(void);

private:
    QWORD NewHandle();

    QWORD handle;

protected:
    std::string File;
};

#endif // BASICCONF_H

