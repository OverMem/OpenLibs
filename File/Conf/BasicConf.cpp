#include "BasicConf.h"

BasicConf::BasicConf()
{
    File   = "DEFAULT_CONF";
    handle = NewHandle();

    std::cout << "BasicConf handle " << handle << " contructed." <<std::endl;
}


QWORD BasicConf::GetHandle()
{
    return handle;
}

QWORD BasicConf::NewHandle()
{
    static QWORD handle_t = 0;

    return handle_t = handle_t + 1;
}

ConfErr BasicConf::SetFile(std::string file)
{
    if(file == "DEFAULT_CONF") return ConfErr::Name;

    File = file;

    return ConfErr::NoErr;
}


BasicConf::~BasicConf(void)
{
    std::cout << "BasicConf handle " << handle << " destructed." <<std::endl;
}

