// Error.cpp: implementation of the Error class.
//
//////////////////////////////////////////////////////////////////////

#include "Error.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Error::Error()
{
	this->first = 0;
}

Error::~Error()
{
	while (this->first != 0)
	{
		Err* tmp = this->first;
		this->first = this->first->pnext;

		delete tmp;
	}
}

bool Error::PushError(int id, char* description)
{
	Err* newerr = new Err;

	newerr->id = id;
	newerr->errdescription = description;

	newerr->pnext = this->first;
	this->first = newerr;

	return false;
}

bool Error::PushErrors(Err* errors)
{
	if (errors != 0)
	{
		if (this->first != 0)
		{
			Err* tmp = this->first;
			
			while (tmp->pnext != 0)
				tmp = tmp->pnext;

			tmp->pnext = errors;
		}
		else
		{
			this->first = errors;
		}
		return false;
	}
	
	return true;
}

bool Error::PopError(Err &err)
{
	if (this->first != 0)
	{
		err = *this->first;

		Err* tmp = this->first;
		this->first = this->first->pnext;

		delete tmp;

		return true;
	}
	return false;
}

Err* Error::PopErrors()
{
	Err* tmp = this->first;

	this->first = 0;

	return tmp;
}

bool Error::HasErrors()
{
	return this->first != 0;
}