#include "SConf.h"

SConf::SConf() : BasicConf()
{
    return;
}


ConfErr SConf::Load()
{
    std::string line, key, value;
    SConfDesc temp;
    std::regex pattern   { "^[A-Za-z_]+[ \t]*=[ \t]*[A-Za-z]+|[0-9]+|[0-9]+\.([0-9])+$" };
    std::regex pattern_c { "#[:print:\t]" };

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ifstream file_t(File.c_str(), std::ios::in);

    if(file_t)
    {
        while(getline(file_t, line))
        {
            if(std::regex_match(line, pattern_c)) continue;
            else if(std::regex_match(line, pattern))
            {
                std::istringstream i_str(line);

                getline(i_str, key,   '=');
                getline(i_str, value, '=');

                temp.Key   = key;
                temp.Value = value;

                config.push_back(temp);
            }
            else
            {
                file_t.close();

                return ConfErr::Regex;
            }
        }
    }
    else return ConfErr::File;

    return ConfErr::NoErr;
}

ConfErr SConf::Save()
{
    std::string line, key, value;

    if(File == "DEFAULT_CONF") return ConfErr::Name;

    std::ofstream file_t(File.c_str(), std::ios::out | std::ios::trunc);

    if(file_t)
    {
        for(int i = 0; i < config.size(); i++)
        {
            line = config[i].Key + " = " + config[i].Value;

            file_t << line;
        }

        file_t.close();
    }
    else return ConfErr::File;

    return ConfErr::NoErr;
}


ConfErr SConf::SetArg(std::string Arg, std::string  value)
{
    if(IsExist(Arg)) config[GetIndex(Arg)].Value = value;
    else
    {
        SConfDesc temp;

        temp.Key   = Arg;
        temp.Value = value;

        config.push_back(temp);
    }

    return ConfErr::NoErr;
}

ConfErr SConf::GetArg(std::string Arg, std::string& value)
{
    if(IsExist(Arg)) value = config[GetIndex(Arg)].Value;
    else             return ConfErr::Exist;

    return ConfErr::NoErr;
}


bool SConf::IsExist(std::string Arg)
{
    std::vector<SConfDesc>::iterator it;

    for(it = config.begin(); it != config.end(); ++it)
    {
        if(it->Key == Arg) return true;
    }

    return false;
}

int SConf::GetIndex(std::string Arg)
{
    for(int i = 0; i < config.size(); i++)
    {
        if(config[i].Key == Arg) return i;
    }

    return -1;
}

SConf::~SConf()
{
    return;
}

