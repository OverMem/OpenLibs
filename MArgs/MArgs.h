#ifndef MARGS_H
#define MARGS_H

/*!
 * @file MArgs.h
 * @brief Main arguments reader
 * @author RemsPrgm
 * @version 1.0
 */
#include <regex>
#include <sstream>
#include <map>

/*!
 * @class MArgs
 * @brief Class represent the args reader
 *
 * Class manage the storage and reading.
 */
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

