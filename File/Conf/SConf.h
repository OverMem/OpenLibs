#ifndef SCONF_H
#define SCONF_H

#include <vector>
#include "BasicConf.h"

typedef struct
{
    std::string Key;
    std::string Value;
}SConfDesc;

class SConf : public BasicConf
{
public:
    SConf();

    ConfErr Load();
    ConfErr Save();

    ConfErr SetArg(std::string Arg, std::string  value);
    ConfErr GetArg(std::string Arg, std::string& value);

    ~SConf();

private:
    bool IsExist(std::string Arg);
    int GetIndex(std::string Arg);

    std::vector<SConfDesc> config;
};

#endif // SCONF_H

