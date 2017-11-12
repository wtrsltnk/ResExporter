// WadFiles.cpp: implementation of the WadFiles class.
//
//////////////////////////////////////////////////////////////////////

#include "WadFiles.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WadFiles::WadFiles()
{
	this->wadResourceCount = 0;
	this->firstWadResource = 0;
}

WadFiles::~WadFiles()
{
	//ClearStringList(this->firstWadResource);
}

void WadFiles::ClearStringList(StringItem* first)
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

char* WadFiles::RemoveFilePath(char* filepath)
{
	if (filepath != 0)
	{
		int len = strlen(filepath);

		for (int i = len; i > 0; i--)
		{
			if (filepath[i] == '\\' || filepath[i] == '/')
			{
				char* tmp = new char[(len - i) + 1];
				memset(tmp, 0, (len - i) + 1);
				strcpy(tmp, filepath + i + 1);
				return tmp;
			}
		}
	}
	return 0;
}

void WadFiles::SetUp(Entity* worldspawn)
{
	Attribute* attribute = worldspawn->GetAttributeByName("wad");
	if (attribute != 0)
	{
		const char* wad = attribute->GetValue();

		if (wad != 0)
		{
			int len = strlen(wad);
			int offset = 0;

			char* tmp = new char[len+1];
			strcpy(tmp, wad);

			while (offset < len)
			{
				int res = FindNextChar(tmp, offset, ';');

				if (res > 0)
				{
					char* n = new char[res - offset + 1];
					memset(n, 0, res - offset + 1);
					strncpy(n, tmp+offset, res - offset);
					
					StringItem* strItem = new StringItem;
					strItem->pstring = RemoveFilePath(n);

					delete n;

					strItem->pnext = this->firstWadResource;
					this->firstWadResource = strItem;

					this->wadResourceCount++;
					offset = res + 1;	
				}
			}

			delete tmp;
		}
	}
}

StringItem* WadFiles::GetWadResourceList()
{
	return this->firstWadResource;
}

int WadFiles::FindNextChar(char* str, int offset, char c)
{
	int len = strlen(str);

	if (offset > len)
		return 0;

	for (int i = offset; i < len; i++)
	{
		if (str[i] == c || str[i] == '\0')
		{
			return i;
		}
	}
    return len;
}

void WadFiles::SetWadItem(char* wadfile, int index)
{
	if (index >= 0 && index < this->wadResourceCount)
	{
		StringItem* tmp = this->firstWadResource;

		for (int i = 0; i < index; i++)
		{
			tmp = tmp->pnext;
		}

		char* n = new char[strlen(wadfile) + 1];
		memset(n, 0, strlen(wadfile) + 1);
		strcpy(n, wadfile);

		delete tmp->pstring;
		tmp->pstring = n;
	}
}
