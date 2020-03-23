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

#include "Utils.h"

char ToChar(BYTE ascii)
{
	return (char)ascii;
}

BYTE ToAscii(char c)
{
	return (BYTE)c;
}

std::string CompleteInt(int Nbr)
{
    std::string complete = "";

	if(Nbr < 10) complete = "0" + toStr<int>(Nbr);
	else         complete = toStr<int>(Nbr);

	return complete;
}

std::string TmToStr(const struct tm *date)
{
    std::string Date = "";

  	Date = "[--" + CompleteInt(date->tm_mday);
  	Date += "/"  + CompleteInt(date->tm_mon + 1);
  	Date += "/"  + CompleteInt(date->tm_year + 1900);
  	Date += " "  + CompleteInt(date->tm_hour);
  	Date += ":"  + CompleteInt(date->tm_min);

  	if(date->tm_sec == 60)
  	{
  		Date += ":" + CompleteInt(0) + "--]: ";
  	}
  	else
  	{
  		Date += ":" + CompleteInt(date->tm_sec) + "--]: ";
  	}

  	return Date;
}

std::string DayToStr(int day, bool type)
{
	if(type == 0)
	{
		switch(day)
		{
			case 1:
				return "Mon";
		 		break;
			case 2:
		 		return "Tue";
				break;
			case 3:
		 		return "Wed";
				break;
			case 4:
		 		return "Thu";
				break;
			case 5:
		 		return "Fri";
				break;
			case 6:
		 		return "Sat";
				break;
			case 7:
		 		return "Sun";
				break;
			default:
				return "Mon";
		 		break;
		}
	}
	else
	{
		switch(day)
		{
			case 1:
		 		return "Lun";
				break;
			case 2:
		 		return "Mar";
				break;
			case 3:
				return "Mer";
		 		break;
			case 4:
		 		return "Jeu";
				break;
			case 5:
		 		return "Ven";
				break;
			case 6:
		 		return "Sam";
				break;
			case 7:
		 		return "Dim";
				break;
			default:
				return "Lun";
				break;
        }
    }
}


DWORD GetFileSize(std::ifstream& file)
{
    DWORD pos, size;

    pos  = file.tellg();
    file.seekg(0,   std::ios_base::end);

    size = file.tellg();
    file.seekg(pos, std::ios_base::beg);

    return size;
}

