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

/// @file BinRes.cpp
/// @brief Source de BinRes
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#include "BinRes.h"

/// @brief operator= - Opérateur d'affectation entre ResDesc
///
/// @param a: ResDesc à affecter
///
/// @return Référence sur le ResDesc affecté.
ResDesc& ResDesc::operator=(ResDesc& a)
{
	begin = a.begin;
	end   = a.end;
	size  = a.size;

	return *this;
}

/// @brief operator== - Opérateur d'égalité entre ResDesc
///
/// @param a: ResDesc de gauche
/// @param b: ResDesc de droite
///
/// @return True si a = b, false sinon.
bool operator==(ResDesc& a, ResDesc& b)
{
	if(a.begin != b.begin) return false;
	if(a.end != b.end)     return false;
	if(a.size != b.size)   return false;

	return true;
}

/// @brief BinRes - Constructeur
///
/// Constructeur de la classe BinRes.
BinRes::BinRes()
{
	Forward = 0;
}


/// @brief AddRes - Ajout d'une ressource
///
/// @param desc: Ressource à ajouter
///
/// @return Index de la ressource ajoutée.
int BinRes::AddRes(ResDesc desc)
{
	int ret;
	int index;

	ret = GetIndex(desc);

	if(ret != -1) return ret;

	index = Forward;

	Res[index] = desc;

	Forward++;

	return index;
}

/// @brief DelRes - Suppression d'une ressource
///
/// @param num: Index de la ressource à supprimer
///
/// @return 1 si erreur, 0 sinon.
int BinRes::DelRes(int num)
{
	if(Res.find(num) == Res.end()) return 1;

	Res.erase(num);

	return 0;
}


/// @brief Read - Lecture d'une ressource
///
/// @param num: Index de la ressource à lire
/// @param rd: Charactère lu
/// @param cursor: Emplacement du charactère à lire
///
/// @return 1 si erreur, 0 sinon.
///
/// Lecture d'un charactère d'une ressource.
int BinRes::Read(int num, char& rd, int cursor)
{
	char *cur;

	if(Res.find(num) == Res.end()) return 1;

	cur = (cursor > (long int)Res[num].size) ? Res[num].size - 1 : Res[num].begin + cursor;

	rd = *cur;

	return 0;
}

/// @brief Read - Lecture d'une ressource
///
/// @param num: Index de la ressource à lire
/// @param rd: Tableau des charactères lus (non alloué)
///
/// @return 1 ou -1 si erreur, 0 sinon.
///
/// Lecture entière d'une ressource par tableau de charactères.
int BinRes::Read(int num, char* rd)
{
	char *cursor;
	std::string temp;

	if(Res.find(num) == Res.end()) return 1;

	cursor = Res[num].begin;
	temp   = "";

	rd = (char *)malloc((long int)Res[num].size * sizeof(char));

	if(rd == NULL) return -1;

	for(long int i = 0; i < (long int)Res[num].size; i++)
	{
		rd[i] = *cursor++;
	}

	return 0;
}

/// @brief Read - Lecture d'une ressource
///
/// @param num: Index de la ressource à lire
/// @param rd: Chaîne de caractère lue
///
/// @return 1 si erreur, 0 sinon.
///
/// Lecture entière d'une ressource par chaîne de charactères.
int BinRes::Read(int num, std::string& rd)
{
	char *cursor;
	std::string temp;

	if(Res.find(num) == Res.end()) return 1;

	cursor = Res[num].begin;
	temp   = "";

	while(cursor != Res[num].end)
	{
		temp += *cursor++;
	}

	rd = temp;

	return 0;
}


int BinRes::GetIndex(ResDesc desc)
{
	std::map<int, ResDesc>::iterator it;

	for(it = Res.begin(); it != Res.end(); it++)
	{
		if(it->second == desc)
		{
			return it->first;
		}
	}

	return -1;
}


