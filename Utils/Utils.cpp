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

/// @brief ToChar - Conversion ASCII => char
///
/// @param ascii: Valeur ASCII à convertir
///
/// @return Charactère correspondant.
///
/// Permet de convertir une valeur en ASCII en charactère.
char ToChar(BYTE ascii)
{
	return (char)ascii;
}

/// @brief ToAscii - Conversion char => ASCII
///
/// @param c: Charactère à convertir
///
/// @return Valeur ASCII correspondante.
///
/// @note Fonction complémentaire à ToChar.
/// Permet de convertir un charactère en une valeur ASCII.
BYTE ToAscii(char c)
{
	return (BYTE)c;
}

/// @brief CompleteInt - Complète un int < 10
///
/// @param Nbr: Nombre à compléter
///
/// @return Chaîne de charactères complétée.
/// 
/// Permet de rajouter un 0 devant les nombres de 0 à 9.
std::string CompleteInt(int Nbr)
{
    std::string complete = "";

	if(Nbr < 10) complete = "0" + toStr<int>(Nbr);
	else         complete = toStr<int>(Nbr);

	return complete;
}

/// @brief TmToStr - Conversion tm => string
///
/// @param date: Structure tm à convertir
///
/// @return Chaîne de charactères formatée.
///
/// Permet de mettre en forme une struct tm suivant le 
/// format: [27/04/2020 15:38:33]: .
std::string TmToStr(const struct tm *date)
{
    std::string Date = "";

  	Date = "[" + CompleteInt(date->tm_mday);
  	Date += "/"  + CompleteInt(date->tm_mon + 1);
  	Date += "/"  + CompleteInt(date->tm_year + 1900);
  	Date += " "  + CompleteInt(date->tm_hour);
  	Date += ":"  + CompleteInt(date->tm_min);

  	if(date->tm_sec == 60)
  	{
  		Date += ":" + CompleteInt(0) + "]: ";
  	}
  	else
  	{
  		Date += ":" + CompleteInt(date->tm_sec) + "]: ";
  	}

  	return Date;
}

/// @brief DayToStr - Conversion numéro jour => string
///
/// @param day: Numéro du jour à convertir
/// @param type: Format de la conversion (Fr: 1 / En: 0)
///
/// @return Chaîne de charactères convertie.
///
/// Permet de convertir un numéro de jour (1-7) en 
/// chaîne de charactères (Ex: 1 => "Mon" OU "Lun").
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


/// @brief GetFileSize - Calcul de la taille d'un fichier
///
/// @param file: Chemin du fichier
///
/// @return Taille du fichier.
///
/// Permet de récupérer la taille d'un fichier.
DWORD GetFileSize(std::ifstream& file)
{
    DWORD pos, size;

    pos  = file.tellg();
    file.seekg(0,   std::ios_base::end);

    size = file.tellg();
    file.seekg(pos, std::ios_base::beg);

    return size;
}

