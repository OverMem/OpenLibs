#ifndef BINRES_H
#define BINRES_H

/*!
 * @file BinRes.h
 * @brief Binary ressources reader
 * @author RemsPrgm
 * @version 1.0
 */

#include <string>
#include <map>

typedef struct ResDesc ResDesc;

/*!
 * @struct ResDesc
 * @brief Res pointers
 *
 * ResDesc is a struct represent a ressource by pointers.
 */
struct ResDesc
{
	char *begin; /*!< Begin pointer. */
	char *end;   /*!< End pointer. */
	char *size;  /*!< Size pointer. */

    ResDesc& operator=(ResDesc& a);
};

bool operator==(ResDesc& a, ResDesc& b);

/*!
 * @class BinRes
 * @brief Class represent a ressource storage
 *
 * Class manage the storage and reading by use ResDesc.
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

