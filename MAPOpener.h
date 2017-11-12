// MAPOpener.h: interface for the MAPOpener class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAPOPENER_H
#define MAPOPENER_H

#include "MAPParser.h"
#include "MAPReader.h"
#include "EntityManager.h"
#include "ResourceManager.h"

#include "Error.h"

class MAPOpener : public Error
{
public:
	MAPOpener();
	virtual ~MAPOpener();

	ResourceManager* Open(const char* filename);


};

#endif
