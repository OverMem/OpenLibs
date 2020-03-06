#include "BinRes.h"

/*!
 * @brief Opérateur d'affectation de la structure ResDesc
 *
 * @param a : La ressource à affecter
 * @return Une référence sur une ResDesc
 */
ResDesc& ResDesc::operator=(ResDesc& a)
{
	begin = a.begin;
	end   = a.end;
	size  = a.size;

	return *this;
}

/*!
 * @brief Opérateur d'égalité entre ResDesc
 *
 * @param a : ResDesc à gauche
 * @param b : ResDesc à droite
 * @return true si elles sont égales, false sinon
 */
bool operator==(ResDesc& a, ResDesc& b)
{
	if(a.begin != b.begin) return false;
	if(a.end != b.end)     return false;
	if(a.size != b.size)   return false;

	return true;
}

/*!
 * @brief Constructeur
 *
 * Constructeur de la classe BinRes
 */
BinRes::BinRes()
{
	Forward = 0;
}


/*!
 * @brief Ajout d'une ressource
 *
 * Méthode permettant d'ajouter une ressource au conteneur.
 *
 * @param desc : Ressource à ajouter
 * @return index de la ressource à ajouter
 */
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

/*!
 * @brief Suppression d'une ressource
 *
 * Méthode permettant de supprimer une ressource du conteneur.
 *
 * @param num : index de la ressource
 * @return 1 si elle n'existait pas, 0 sinon
 */
int BinRes::DelRes(int num)
{
	if(Res.find(num) == Res.end()) return 1;

	Res.erase(num);

	return 0;
}


/*!
 * @brief Lecture d'une ressource
 *
 * Méthode permettant de lire un octet.
 *
 * @param num    : index de la ressource
 * @param rd     : référence vers l'octet lu
 * @param cursor : position de lecture
 * @return 0 si réussite, 1 sinon
 */
int BinRes::Read(int num, char& rd, int cursor)
{
	char *cur;

	if(Res.find(num) == Res.end()) return 1;

	cur = (cursor > (long int)Res[num].size) ? Res[num].size - 1 : Res[num].begin + cursor;

	rd = *cur;

	return 0;
}

/*!
 * @brief Lecture d'une ressource
 *
 * Méthode permettant de la lire en entier (C style).
 *
 * @param num : index de la ressource
 * @param rd  : pointeur vers les octets lu (ne doit pas être alloué)
 * @return 0 si réussite
 */
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

/*!
 * @brief Lecture d'une ressource
 *
 * Méthode permettant de la lire en entier (C++ style).
 *
 * @param num : index de la ressource
 * @param rd  : référence vers la chaîne lu
 * @return 0 si réussite, 1 sinon
 */
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


