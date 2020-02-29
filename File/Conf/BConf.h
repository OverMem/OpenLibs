#ifndef BCONF_H
#define BCONF_H

#include "OPEN/Utils.h"
#include "BasicConf.h"

class BConf : public BasicConf
{
public:
    BConf();

    ConfErr Load();
    ConfErr Save();

    ConfErr SetArg(std::string Arg, std::string  value);
    ConfErr GetArg(std::string Arg, std::string& value);

    ConfErr AddCmd(WORD cmd, std::string Arg);
    ConfErr DelCmd(WORD cmd);

    ConfErr SetFile(std::string file);

    ~BConf();

private:
    bool IsExist(std::string Arg);
    int GetIndex(std::string Arg);
    WORD GetCommand(std::string Arg);

    std::vector<ConfDesc> config;
    std::map<WORD, std::string> command;
};

#endif // BCONF_H

