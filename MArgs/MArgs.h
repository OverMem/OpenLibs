#ifndef MARGS_H
#define MARGS_H

#include <regex>
#include <sstream>
#include <map>

class MArgs
{
public:
    MArgs(int nargs, char *args[]);
    
    int GetArg(std::string name, std::string& value);

private:
    bool IsExist(std::string name);

    std::map<std::string, std::string> Arg;
};

#endif // MARGS_H

