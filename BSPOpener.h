// BSPOpener.h: interface for the BSPOpener class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BSPOPENER_H
#define BSPOPENER_H

#include "MAPParser.h"
#include "MAPReader.h"
#include "EntityManager.h"
#include "ResourceManager.h"

#include "Error.h"

#define VALID_BSP_SIZE 256  // ToDo Tweaken!!

#define	LUMP_ENTITIES	0
#define	LUMP_PLANES		1
#define	LUMP_TEXTURES	2
#define	LUMP_VERTEXES	3
#define	LUMP_VISIBILITY	4
#define	LUMP_NODES		5
#define	LUMP_TEXINFO	6
#define	LUMP_FACES		7
#define	LUMP_LIGHTING	8
#define	LUMP_CLIPNODES	9
#define	LUMP_LEAFS		10
#define	LUMP_MARKSURFACES 11
#define	LUMP_EDGES		12
#define	LUMP_SURFEDGES	13
#define	LUMP_MODELS		14

#define	HEADER_LUMPS	15

#define BSPVERSION	30

typedef struct
{
	int		fileofs, filelen;
} lump_t;

typedef struct
{
	int			version;	
	lump_t		lumps[HEADER_LUMPS];
} dheader_t;


#define ERROR_ID_NO_ENTITIES_FOUND 87570
#define ERROR_ID_WRONG_BSP_VERSION 87571
#define ERROR_ID_LIST_BUILD_FAILED 87572


class BSPOpener : public Error
{
private:
	FILE* pFileHandle;
	bool OpenFileForReading(const char* filename);
	bool ReadEntities(char** buffer);
	void CloseFile();

public:
	BSPOpener();
	virtual ~BSPOpener();

	ResourceManager* Open(const char* filename);

};

#endif
