#ifndef BINRES_H
#define BINRES_H

/*!
 * @file BinRes.h
 * @brief Lecteur de ressources binaires
 * @author RemsPrgm
 * @version 1.0
 */

#include <string>
#include <map>

typedef struct ResDesc ResDesc;

/*!
 * @struct ResDesc
 * @brief Pointeurs sur une ressource
 *
 * ResDesc est une structure représentant une ressource par des pointeurs.
 */
struct ResDesc
{
	char *begin; /*!< Pointeur de début. */
	char *end;   /*!< Pointeur de fin. */
	char *size;  /*!< Pointeur sur la taille. */

    ResDesc& operator=(ResDesc& a);
};

bool operator==(ResDesc& a, ResDesc& b);

/*!
 * @class BinRes
 * @brief Classe représentant un conteneur à ressources
 *
 * La classe gère le stockage et la lecture de celles-ci.
 */ 
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

