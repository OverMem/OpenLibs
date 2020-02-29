#include "BConf.h"

BConf::BConf() : BasicConf()
{
    return;
}


ConfErr BConf::Load()
{
    WORD temp_c, size_v;
    DWORD size_f, size_u = 0;
    BYTE temp_v;
    ConfDesc temp;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    config.clear();
    std::ifstream file_t(File.c_str(), std::ios::in | std::ios::binary);

    if(!file_t.is_open()) return ConfErr::File;
    else
    {
        size_f = GetFileSize(file_t);

        while(size_u < size_f)
        {
            file_t.read((char *)&temp_c, 2);

            if(command.find(temp_c) != command.end())
            {
                temp.Key = command[temp_c];

                file_t.read((char *)&size_v, 2);

                temp.Value = "";
                for(DWORD i = 0; i < size_v; i++)
                {
                    file_t.read((char *)&temp_v, 1);

                    temp.Value += ToChar(temp_v);
                }

                config.push_back(temp);

                size_u += (4 + size_v);
            }
            else return ConfErr::Exist;
        }

        file_t.close();
    }

    return ConfErr::NoErr;
}

ConfErr BConf::Save()
{
    WORD temp_c, size_v;
    BYTE temp_v;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ofstream file_t(File.c_str(), std::ios::in | std::ios::binary | std::ios::trunc);

    if(!file_t.is_open()) return ConfErr::File;
    else
    {
        for(int i = 0; i < config.size(); i++)
        {
            temp_c = GetCommand(config[i].Key);
            file_t.write((char *)&temp_c, 2);

            for(std::string::size_type j = 0; j < config[i].Value.length(); j++)
            {
                temp_v = ToAscii(config[i].Value[j]);

                file_t.write((char *)&temp_v, 1);
            }
        }

        file_t.close();
    }

    return ConfErr::NoErr;
}


ConfErr BConf::SetArg(std::string Arg, std::string  value)
{
    std::map<WORD, std::string>::iterator it;

    if(IsExist(Arg)) config[GetIndex(Arg)].Value = value;
    else
    {
        for(it = command.begin(); it != command.end(); ++it)
        {
            if(it->second == Arg)
            {
                ConfDesc temp;

                temp.Key   = Arg;
                temp.Value = value;

                config.push_back(temp);

                return ConfErr::NoErr;
            }
        }

        return ConfErr::Exist;
    }
}

ConfErr BConf::GetArg(std::string Arg, std::string& value)
{
    if(IsExist(Arg)) value = config[GetIndex(Arg)].Value;
    else             return ConfErr::Exist;

    return ConfErr::NoErr;
}


ConfErr BConf::AddCmd(WORD cmd, std::string Arg)
{
    if(cmd == 0)                           return ConfErr::Name;
    if(command.find(cmd) != command.end()) return ConfErr::Exist;

    command[cmd] = Arg;
}

ConfErr BConf::DelCmd(WORD cmd)
{
    if(command.find(cmd) == command.end()) return ConfErr::Exist;
    else                                   command.erase(cmd);
}


bool BConf::IsExist(std::string Arg)
{
    std::vector<ConfDesc>::iterator it;

    for(it = config.begin(); it != config.end(); ++it)
    {
        if(it->Key == Arg) return true;
    }

    return false;
}

int BConf::GetIndex(std::string Arg)
{
    for(int i = 0; i < config.size(); i++)
    {
        if(config[i].Key == Arg)
        {
            return i;
        }
    }

    return -1;
}

WORD BConf::GetCommand(std::string Arg)
{
    std::map<WORD, std::string>::iterator it;

    for(it = command.begin(); it != command.end(); ++it)
    {
        if(it->second == Arg)
        {
            return it->first;
        }
    }

    return 0;
}


ConfErr BConf::SetFile(std::string file)
{
    return BasicConf::SetFile(file);
}

BConf::~BConf()
{
    return;
}

