// EntityManager.cpp: implementation of the EntityManager class.
//
//////////////////////////////////////////////////////////////////////

#include "EntityManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

EntityManager::EntityManager()
{
	this->entityCount = 0;
	this->firstEntity = 0;
}

EntityManager::~EntityManager()
{
	ClearList(this->firstEntity);
}

void EntityManager::ClearList(EntityItem* first)
{
	EntityItem *ent = 0;

	while (first)
	{
		ent = first;
		first = first->pnext;
		delete ent->pentity;
		delete ent;
	}
}

Entity *EntityManager::AddEntity()
{
	EntityItem* item;
	
	item = new EntityItem;
	item->pentity = new Entity();
	item->pnext = this->firstEntity;

	this->firstEntity = item;
	this->entityCount++;

	return item->pentity;
}

int EntityManager::GetEntityCount()
{
	return this->entityCount;
}

Entity *EntityManager::GetEntityByIndex(int index)
{
	if (index >= 0 && index < this->entityCount)
	{
		EntityItem* tmp = this->firstEntity;
		int i = 0;

		while (tmp != 0)
		{
			if (i == index)
				return tmp->pentity;
				
			tmp = tmp->pnext;
			i++;
		}
	}
	return 0;
}

Entity *EntityManager::GetEntityByName(string name)
{
	EntityItem* tmp = this->firstEntity;
	while (tmp != 0)
	{
		if (tmp->pentity->GetName() == name)
			return tmp->pentity;

		tmp = tmp->pnext;
	}
	return 0;
}
