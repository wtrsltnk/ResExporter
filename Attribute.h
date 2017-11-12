// Attribute.h: interface for the Attribute class.
//
//////////////////////////////////////////////////////////////////////

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include <vector>
using namespace std;

class Attribute  
{
private:
	char* name;
	char* value;

public:
	Attribute();
	virtual ~Attribute();

	void SetName(const char* name);
	char* GetName();

	void SetValue(const char* value);
	char* GetValue();
};

#endif
