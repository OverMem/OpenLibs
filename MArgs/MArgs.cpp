#include "MArgs.h"

/*!
 * @brief Constructor
 *
 * Constructor of class MArgs.
 */
MArgs::MArgs(int nargs, char *args[])
{
    std::string temp, key, value;
    std::regex pattern { "^--?[A-Za-z_]+=[A-Za-z0-9_]+$" };

    for(int i = 0; i < nargs; i++)
    {
        temp = args[i];

        if(std::regex_match(temp, pattern) == true)
        {
            std::istringstream Strs(temp);

            getline(Strs, key, '=');
            getline(Strs, value, '=');

	        Arg[key] = value;
        }
    }
}


/*!
 * @brief Get an argument
 *
 * Metho to get an arg by name.
 *
 * @param[in] name : name of arg
 * @param[out] value : string reference
 * @return 0 if arg exist, 1 else
 */
int MArgs::GetArg(std::string name, std::string& value)
{
    if(IsExist(name)) value = Arg[name];
    else              return 1;

    return 0;
}

bool MArgs::IsExist(std::string name)
{
    if(Arg.find(name) != Arg.end()) return true;
    else                            return false;
}

