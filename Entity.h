// Entity.h: interface for the Entity class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
using namespace std;

#include "Attribute.h"

class Entity  
{
private:
	vector <Attribute> attributes;
	char* name;

public:
	Entity();
	virtual ~Entity();

	int AddAttribute(Attribute attribute);
	Attribute *AddAttribute();

	int GetAttributeCount();
	Attribute *GetAttributeByIndex(int index);
	Attribute *GetAttributeByName(const char* name);

	void SetName(const char* name);
	char* GetName();
};

#endif
