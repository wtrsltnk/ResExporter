// EntityManager.h: interface for the EntityManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <string>
using namespace std;

#include "Entity.h"

struct EntityItem
{
	Entity* pentity;
	EntityItem* pnext;
};

class EntityManager  
{
private:
	int entityCount;
	EntityItem* firstEntity;

	void ClearList(EntityItem* first);

public:
	EntityManager();
	virtual ~EntityManager();
	
	Entity *AddEntity();

	int GetEntityCount();
	Entity *GetEntityByIndex(int index);
	Entity *GetEntityByName(string name);
};

#endif
