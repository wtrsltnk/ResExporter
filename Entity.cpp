// Entity.cpp: implementation of the Entity class.
//
//////////////////////////////////////////////////////////////////////

#include "Entity.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Entity::Entity()
{
	this->name = new char[2];
	this->name[0] = '\0';
	this->name[1] = '\0';
}

Entity::~Entity()
{
}

int Entity::AddAttribute(Attribute attribute)
{
	this->attributes.push_back(attribute);

	return this->attributes.size() - 1;
}

Attribute *Entity::AddAttribute()
{
	Attribute attribute;

	this->attributes.push_back(attribute);

	return &this->attributes[this->attributes.size() - 1];
}

int Entity::GetAttributeCount()
{
	return this->attributes.size();
}

Attribute *Entity::GetAttributeByIndex(int index)
{
	if (index > 0 && index < this->attributes.size())
	{
		return &this->attributes[index];
	}
	return 0;
}

Attribute *Entity::GetAttributeByName(const char* name)
{
	for (int i = 0; i < this->attributes.size(); i++)
	{
		if (strcmp(this->attributes[i].GetName(), name) == 0)
			return &this->attributes[i];
	}
	return 0;
}

void Entity::SetName(const char* name)
{
	if (this->name != 0)
		delete this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

char* Entity::GetName()
{
	return this->name;
}