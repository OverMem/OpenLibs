#ifndef BINRES_H
#define BINRES_H

#include <string>
#include <map>

typedef struct ResDesc ResDesc;

struct ResDesc
{
	char *begin;
	char *end;
	char *size;

    ResDesc& operator=(ResDesc& a);
};

bool operator==(ResDesc& a, ResDesc& b);

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

