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

/// @file BinRes.h
/// @brief Header de BinRes
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef BINRES_H
#define BINRES_H

#include <string>
#include <map>

typedef struct ResDesc ResDesc;

/// @brief ResDesc - Représente une ressource
///
/// Strcture permettant de représenter une ressource 
/// par 3 pointeurs: début, fin et taille.
struct ResDesc
{
	char *begin; //!< Pointeur de début.
	char *end;   //!< Pointeur de fin.
	char *size;  //!< Pointeur de taille.

    ResDesc& operator=(ResDesc& a);
};

bool operator==(ResDesc& a, ResDesc& b);

/// @brief BinRes - Conteneur et Manager pour ressources
/// 
/// Classe qui stocke et permet la lecture de ressources binaires.
class BinRes
{
public:
    BinRes();

	int AddRes(ResDesc desc);
	int DelRes(int num);

	int Read(int num, char& rd, int cursor);
	int Read(int num, char* rd);
	int Read(int num, std::string& rd);

private:
	int GetIndex(ResDesc desc);

	std::map<int, ResDesc> Res;
	int Forward;
};

#endif // BINRES_H

