// MAPOpener.cpp: implementation of the MAPOpener class.
//
//////////////////////////////////////////////////////////////////////

#include "MAPOpener.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MAPOpener::MAPOpener()
{
}

MAPOpener::~MAPOpener()
{
}

ResourceManager* MAPOpener::Open(const char* filename)
{
	if (filename != 0)
	{
		EntityManager entities;
		ResourceManager* resources = new ResourceManager();
		MAPParser parser;
		MAPReader reader;

		if (!parser.SetMAPFile(filename))
		{
			PushErrors(parser.PopErrors());
			return 0;
		}

		reader.Read(&entities, &parser);
		resources->AddResourceType("env_sprite", "model");
		resources->AddResourceType("cycler_sprite", "model");
		resources->AddResourceType("ambient_generic", "message");
		if (resources->BuildResourceList(&entities))
		{
			return resources;
		}
	}
	return 0;
}
