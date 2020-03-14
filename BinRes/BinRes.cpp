#include "BinRes.h"

ResDesc& ResDesc::operator=(ResDesc& a)
{
	begin = a.begin;
	end   = a.end;
	size  = a.size;

	return *this;
}

bool operator==(ResDesc& a, ResDesc& b)
{
	if(a.begin != b.begin) return false;
	if(a.end != b.end)     return false;
	if(a.size != b.size)   return false;

	return true;
}

BinRes::BinRes()
{
	Forward = 0;
}


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

int BinRes::DelRes(int num)
{
	if(Res.find(num) == Res.end()) return 1;

	Res.erase(num);

	return 0;
}


int BinRes::Read(int num, char& rd, int cursor)
{
	char *cur;

	if(Res.find(num) == Res.end()) return 1;

	cur = (cursor > (long int)Res[num].size) ? Res[num].size - 1 : Res[num].begin + cursor;

	rd = *cur;

	return 0;
}

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


