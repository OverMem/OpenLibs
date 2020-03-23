/*
Copyright © 2020 Nicolle Rémi

This file is part of OpenLibs.

OpenLibs is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenLibs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLibs.  If not, see <https://www.gnu.org/licenses/>.
*/

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

