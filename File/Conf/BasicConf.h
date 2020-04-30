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

/// @file BasicConf.h
/// @brief Header de BasicConf
/// @author RemsPrgm
/// @version 1.0
/// @date 2020-04-27

#ifndef BASICCONF_H
#define BASICCONF_H

#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>
#include "OPEN/Types/Defines.h"

/// @brief ConfErr - Énumération d'erreurs
///
/// Énumération listant les différentes erreurs possibles.
enum class ConfErr : sBYTE
{
    Name  = -1, //!< Erreur de nom.
    File  = -2, //!< Erreur de fichier.
    Regex = -3, //!< Match regex <=> string impossible.
    Exist = -4, //!< Élément introuvable.
    NoErr =  0  //!< Pas d'erreur.
};

/// @brief ConfDesc - Représente une valeur de config
///
/// Structure décrivant une valeur de config du type key/value.
typedef struct
{
    std::string Key;   //!< Clé de configuration.
    std::string Value; //!< Valeur de configuration.
}ConfDesc;

/// @brief BasicConf - Manager de fichier de config
///
/// Classe abstraite qui définit un modèle de gestion 
/// de fichier de configuration.
class BasicConf
{
public:
    BasicConf();

    QWORD GetHandle();

    virtual ConfErr Load() =0;
    virtual ConfErr Save() =0;

    ConfErr SetFile(std::string file);

    virtual ConfErr SetArg(std::string Arg, std::string  value) =0;
    virtual ConfErr GetArg(std::string Arg, std::string& value) =0;

    virtual ~BasicConf(void);

private:
    QWORD NewHandle();

    QWORD handle;

protected:
    std::string File;
};

#endif // BASICCONF_H

