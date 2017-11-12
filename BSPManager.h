// BSPManager.h: interface for the BSPManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BSPMANAGER_H
#define BSPMANAGER_H

#include <windows.h>
#include <vector>
#include <string>
using namespace std;

class BSPManager  
{
public:
	BSPManager();
	virtual ~BSPManager();

	BOOL OpenFile(LPTSTR strFileName);
	int GetResources();
};

#endif
