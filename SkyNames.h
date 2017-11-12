// SkyNames.h: interface for the SkyNames class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SKYNAMES_H
#define SKYNAMES_H

#include "Entity.h"

#ifndef STRING_ITEM
#define STRING_ITEM
struct StringItem
{
	char* pstring;
	StringItem* pnext;
};
#endif

class SkyNames  
{
private:
	int skyResourceCount;
	StringItem* firstSkyResource;

	void ClearStringList(StringItem* first);
	
public:
	SkyNames();
	virtual ~SkyNames();

	void SetUp(Entity* worldspawn, char* extension);
	StringItem* GetSkyResourceList();
	void SetSkyItem(char* skyname, int index);
};

#endif
