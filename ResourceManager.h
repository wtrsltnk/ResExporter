// ResourceManager.h: interface for the ResourceManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "EntityManager.h"
#include "SkyNames.h"
#include "WadFiles.h"

#include "Error.h"

#ifndef STRING_ITEM
#define STRING_ITEM
struct StringItem
{
	char* pstring;
	StringItem* pnext;
};
#endif

struct ResourceItem
{
	char* pentity;
	char* pkey;
	ResourceItem* pnext;
};

#define ERROR_ID_CANT_OPEN_FILE 87568

class ResourceManager : public Error
{
private:
	int resourceCount;
	StringItem* firstResource;
	int resourceTypeCount;
	ResourceItem* firstResourceType;

	SkyNames skynames;
	WadFiles wadfiles;

	void ClearStringList(StringItem* first);
	void ClearResourceList(ResourceItem* first);
	
public:
	ResourceManager();
	virtual ~ResourceManager();

	bool BuildResourceList(EntityManager* manager);
	bool WriteToFile(const char* filename);

	int AddResource(char* str);
	int AddResources(StringItem* resources);

	bool RemoveResource(int index);
	
	int GetResourceCount();
	char* GetResourceByIndex(int index);

	int AddResourceType(char* entity, char* key);
	
	int GetResourceTypeCount();
	char* GetResourceTypeByIndex(int index);

	bool IsResource(Entity* entity);
	bool DoesExcist(char* resource);
	char* GetResourceValue(Entity* entity);

	void SetResourceItem(char* resourceItem, int index);

};

#endif
