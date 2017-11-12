// BSPFileLoader.h: interface for the BSPFileLoader class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BSPFILELOADER_H
#define BSPFILELOADER_H

#include <windows.h>

class BSPFileLoader  
{
public:
	BSPFileLoader();
	virtual ~BSPFileLoader();

	BOOL OpenFile(LPTSTR strFileName);
	LPTSTR GetEntities();
};

#endif
