// SkyNames.cpp: implementation of the SkyNames class.
//
//////////////////////////////////////////////////////////////////////

#include "SkyNames.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SkyNames::SkyNames()
{
	this->skyResourceCount = 0;
	this->firstSkyResource = 0;
}

SkyNames::~SkyNames()
{
	//ClearStringList(this->firstSkyResource);
}

void SkyNames::ClearStringList(StringItem* first)
{
	StringItem *str = 0;

	while (first)
	{
		str = first;
		first = first->pnext;
		delete str->pstring;
		delete str;
	}
}

void SkyNames::SetUp(Entity* worldspawn, char* extension)
{
	char names[6][2] = {{'b','k'}, {'d', 'n'}, {'f', 't'}, {'l', 'f'}, {'r', 't'}, {'u', 'p'}};

	Attribute* attribute = worldspawn->GetAttributeByName("skyname");

	if (attribute != 0)
	{
		const char* sky = attribute->GetValue();

		for (int i = 0; i < 6; i++)
		{
			char tmp[64] = {0};

			sprintf(tmp, "%s%c%c%s", sky, names[i][0], names[i][1], extension);

			char* res = new char[strlen(tmp)+1];
			strcpy(res, tmp);

			StringItem* strItem = new StringItem;
			strItem->pstring = res;
			strItem->pnext = this->firstSkyResource;
			this->firstSkyResource = strItem;
			this->skyResourceCount++;
		}
	}
}

StringItem* SkyNames::GetSkyResourceList()
{
	return this->firstSkyResource;
}

void SkyNames::SetSkyItem(char* skyname, int index)
{
	if (index >= 0 && index < this->skyResourceCount)
	{
		StringItem* tmp = this->firstSkyResource;

		for (int i = 0; i < index; i++)
		{
			tmp = tmp->pnext;
		}

		int len = strlen(skyname);
		char* n = new char[len + 1];
		memset(n, 0, len + 1);
		strcpy(n, skyname);

		delete tmp->pstring;
		tmp->pstring = n;
	}
}