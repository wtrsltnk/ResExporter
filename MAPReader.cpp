// MAPReader.cpp: implementation of the MAPReader class.
//
//////////////////////////////////////////////////////////////////////

#include "MAPReader.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MAPReader::MAPReader()
{
}

MAPReader::~MAPReader()
{
}

bool MAPReader::Read(EntityManager* entitieManager, MAPParser* mapParser)
{
	if (entitieManager != 0 && mapParser != 0)
	{
		bool res = true;

		do
		{
			switch (mapParser->GetType())
			{
			case eNull:
				{
					continue;
				}

			case eComment:
				{
					continue;
				}

			case eStartBracket:
				{
					res = ReadEntity(entitieManager->AddEntity(), mapParser);
					break;
				}

			default:
				{
					return Error::PushError(1, "Dit type token wordt niet ondersteund door deze Reader. De Reader kan dit bestand dus niet lezen.");
				}
			}
		} while ((mapParser->GoToNextToken()) && (mapParser->GetType() != eEnd) && (res == true));

		return Error::PushErrors(mapParser->PopErrors());
	}
	return false;
}

bool MAPReader::ReadEntity(Entity* entity, MAPParser* mapParser)
{
	if (entity != 0 && mapParser != 0)
	{
		bool res = true;
		int i = 0;

		while ((mapParser->GoToNextToken()) && (mapParser->GetType() != eEndBracket) && (res == true))
		{
			switch (mapParser->GetType())
			{
			case eString:
				{
					Attribute* attribute = entity->AddAttribute();

					res = ReadAttribute(attribute, mapParser);

					if (strcmp(attribute->GetName(), "classname") == 0)
					{
						entity->SetName(attribute->GetValue());
					}
					break;
				}

			case eComment:
				{
					continue;
				}

			case eStartBracket:
				{
					res = SkipBrush(mapParser);
					break;
				}

			default:
				{
					return Error::PushError(2, "Deze token is niet verwacht op dit punt van het bestand.");
				}

			}
		}
		return res;
	}
	return false;
}

bool MAPReader::ReadAttribute(Attribute* attribute, MAPParser* mapParser)
{
	if (attribute != 0 && mapParser != 0)
	{
		attribute->SetName(mapParser->GetToken());
		if (mapParser->GoToNextToken())
		{
			attribute->SetValue(mapParser->GetToken());
			return true;
		}
	}
	return false;
}

bool MAPReader::SkipBrush(MAPParser* mapParser)
{
	bool res = true;

	if (mapParser->GoToNextToken())
	{
		while ((mapParser->GoToNextToken()) && (mapParser->GetType() != eEndBracket) && (res == true))
		{
		}
	}

	return res;
}
