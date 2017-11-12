// MAPReader.h: interface for the MAPReader class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAPREADER_H
#define MAPREADER_H

#include "Error.h"
#include "MAPParser.h"
#include "EntityManager.h"

class MAPReader : public Error
{
private:
	bool ReadEntity(Entity* entity, MAPParser* mapParser);
	bool ReadAttribute(Attribute* attribute, MAPParser* mapParser);
	bool SkipBrush(MAPParser* mapParser);

public:
	MAPReader();
	virtual ~MAPReader();

	bool Read(EntityManager* entitieManager, MAPParser* mapParser);

};

#endif
