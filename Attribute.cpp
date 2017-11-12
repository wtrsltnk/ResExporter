// Attribute.cpp: implementation of the Attribute class.
//
//////////////////////////////////////////////////////////////////////

#include "Attribute.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Attribute::Attribute()
{
	this->name = 0;
	this->value = 0;
}

Attribute::~Attribute()
{
}

void Attribute::SetName(const char* name)
{
	if (this->name != 0)
		delete this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

char* Attribute::GetName()
{
	return this->name;
}

void Attribute::SetValue(const char* value)
{
	if (this->value != 0)
		delete this->value;
	this->value = new char[strlen(value)+1];
	strcpy(this->value, value);
}

char* Attribute::GetValue()
{
	return this->value;
}
