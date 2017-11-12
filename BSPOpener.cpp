// BSPOpener.cpp: implementation of the BSPOpener class.
//
//////////////////////////////////////////////////////////////////////

#include "BSPOpener.h"
#include <sys/stat.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BSPOpener::BSPOpener()
{
	this->pFileHandle = 0;
}

BSPOpener::~BSPOpener()
{
}


ResourceManager* BSPOpener::Open(const char* filename)
{
	EntityManager entities;

	if (OpenFileForReading(filename))
	{
		ResourceManager* resources = new ResourceManager();
		char* buffer = 0;
		MAPParser parser;
		MAPReader reader;
		
		if (ReadEntities(&buffer))
		{
			if (!parser.SetMAPBuffer(buffer))
			{
				PushErrors(parser.PopErrors());
				return 0;
			}
			
			reader.Read(&entities, &parser);
			resources->AddResourceType("env_sprite", "model");
			resources->AddResourceType("cycler_sprite", "model");
			resources->AddResourceType("ambient_generic", "message");
			if (!resources->BuildResourceList(&entities))
			{
				CloseFile();
				PushError(ERROR_ID_LIST_BUILD_FAILED);
				return 0;
			}
		}
		else
		{
			CloseFile();
			return 0;
		}
		
		CloseFile();
		return resources;
	}
	return 0;
}

bool BSPOpener::OpenFileForReading(const char* filename)
{
	struct _stat status;

	if (_stat(filename, &status) == 0)
	{
		if (status.st_size > VALID_BSP_SIZE)
		{
			this->pFileHandle = fopen(filename, "rt");
			if (this->pFileHandle)
			{
				return true;
			}
		}
		
	}
	return false;
}

bool BSPOpener::ReadEntities(char** buffer)
{
	dheader_t hdr;
	::fread(&hdr, sizeof(dheader_t), 1, this->pFileHandle);

	if (hdr.version == BSPVERSION)
	{
		lump_t lump;
		lump = hdr.lumps[LUMP_ENTITIES];

		*buffer = new char[lump.filelen];

		fseek(this->pFileHandle, lump.fileofs, SEEK_SET);
		if (fread(*buffer, lump.filelen, 1, this->pFileHandle) > 0)
			return true;
		else
			return PushError(ERROR_ID_NO_ENTITIES_FOUND);
	}
	else
	{
		return PushError(ERROR_ID_WRONG_BSP_VERSION);
	}
}

void BSPOpener::CloseFile()
{
	::fclose(pFileHandle);
}