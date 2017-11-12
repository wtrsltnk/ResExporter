// WadFiles.h: interface for the WadFiles class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WADFILES_H
#define WADFILES_H

#include "Entity.h"

#ifndef STRING_ITEM
#define STRING_ITEM
struct StringItem
{
	char* pstring;
	StringItem* pnext;
};
#endif

class WadFiles  
{
private:
	int wadResourceCount;
	StringItem* firstWadResource;

	int FindNextChar(char* str, int offset, char c);
	int GetWadFile(char* wads);
	void ClearStringList(StringItem* first);
	char* RemoveFilePath(char* filepath);

public:
	WadFiles();
	virtual ~WadFiles();

	void SetUp(Entity* worldspawn);

	StringItem* GetWadResourceList();

	void SetWadItem(char* wadfile, int index);
};

#endif
