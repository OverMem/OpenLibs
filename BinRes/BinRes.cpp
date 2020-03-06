#include "BinRes.h"

/*!
 * @brief ResDesc struct affect operator
 *
 * @param a : ResDesc to affect
 * @return ResDesc reference
 */
ResDesc& ResDesc::operator=(ResDesc& a)
{
	begin = a.begin;
	end   = a.end;
	size  = a.size;

	return *this;
}

/*!
 * @brief ResDesc equality operator
 *
 * @param a : left ResDesc
 * @param b : right ResDesc
 * @return true if are equal, false else
 */
bool operator==(ResDesc& a, ResDesc& b)
{
	if(a.begin != b.begin) return false;
	if(a.end != b.end)     return false;
	if(a.size != b.size)   return false;

	return true;
}

/*!
 * @brief Constructor
 *
 * Constructor of class BinRes.
 */
BinRes::BinRes()
{
	Forward = 0;
}


/*!
 * @brief Add a ressource
 *
 * Method to add a ressource in store.
 *
 * @param desc : ResDesc to add
 * @return index of res
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
 * @brief Delete a ressource
 *
 * Method to delete a ressource in store.
 *
 * @param num : index of res
 * @return 1 if res not exist, 0 else
 */
int BinRes::DelRes(int num)
{
	if(Res.find(num) == Res.end()) return 1;

	Res.erase(num);

	return 0;
}


/*!
 * @brief Read a ressource
 *
 * Method to read a byte.
 *
 * @param[in] num    : index of res
 * @param[out] rd    : byte read reference
 * @param[in] cursor : read position
 * @return 0 if no error, 1 else
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
 * @brief Read a ressource
 *
 * Method read all in bytes.
 *
 * @param[in] num : index of res
 * @param[out] rd : Bytes read pointer (don't allocated)
 * @return 0 if no error
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
 * @brief Read a ressource
 *
 * Method to read all in string.
 *
 * @param[in] num : index of res
 * @param[out] rd : string read reference
 * @return 0 if no error, 1 else
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


