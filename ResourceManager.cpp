// ResourceManager.cpp: implementation of the ResourceManager class.
//
//////////////////////////////////////////////////////////////////////

#include "ResourceManager.h"
#include <stdio.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ResourceManager::ResourceManager()
{
	this->resourceCount = 0;
	this->firstResource = 0;
	this->resourceTypeCount = 0;
	this->firstResourceType = 0;
}

ResourceManager::~ResourceManager()
{
	ClearStringList(this->firstResource);
	ClearResourceList(this->firstResourceType);
}

void ResourceManager::ClearStringList(StringItem* first)
{
	StringItem *str = 0;

	while (first)
	{
		str = first;
		first = first->pnext;
		delete str->pstring;
		delete str;
	}
}

void ResourceManager::ClearResourceList(ResourceItem* first)
{
	ResourceItem *res = 0;

	while (first)
	{
		res = first;
		first = first->pnext;
		delete res->pentity;
		delete res->pkey;
		delete res;
	}
}

int ResourceManager::AddResource(char* str)
{
	StringItem* item;
	char* s;

	s = new char[strlen(str)+1];
	strcpy(s, str);
	
	item = new StringItem;
	item->pstring = s;
	item->pnext = this->firstResource;

	this->firstResource = item;
	this->resourceCount++;

	return this->resourceCount;
}

int ResourceManager::AddResources(StringItem* resources)
{
	if (resources != 0)
	{
		StringItem* tmp = resources;
		this->resourceCount++;
		
		while (tmp->pnext != 0)
		{
			tmp = tmp->pnext;
			this->resourceCount++;
		}

		tmp->pnext = this->firstResource;
		this->firstResource = resources;
	}
	return this->resourceCount;
}

bool ResourceManager::RemoveResource(int index)
{
	if (index >= 0 && index < this->resourceCount)
	{
		StringItem* tmp = this->firstResource;
		int i = 0;

		while (tmp != 0)
		{
			if ((i+1) == index)
			{
				StringItem* del = tmp->pnext;

				tmp->pnext = del->pnext;

				delete del->pstring;
				delete del;

				this->resourceCount--;
				return true;
			}
				
			tmp = tmp->pnext;
			i++;
		}
	}
	return false;
}

int ResourceManager::GetResourceCount()
{
	return this->resourceCount;
}

char* ResourceManager::GetResourceByIndex(int index)
{
	if (index >= 0 && index < this->resourceCount)
	{
		StringItem* tmp = this->firstResource;
		int i = 0;

		while (tmp != 0)
		{
			if (i == index)
				return tmp->pstring;
				
			tmp = tmp->pnext;
			i++;
		}
	}
	return 0;
}

bool ResourceManager::WriteToFile(const char* filename)
{
	bool res = true;
	FILE *file;

	file = fopen(filename, "wt");
	if (file)
	{
		fwrite("// Resource file created by .res Exporter\n", sizeof(char), 42, file);
		fwrite("// .res Exporter is there for you to generate\n", sizeof(char), 46, file);
		fwrite("// a resoruce file from a bsp or map file\n", sizeof(char), 42, file);

		StringItem* tmp = this->firstResource;
		while (tmp != 0)
		{
			fwrite(tmp->pstring, sizeof(char), strlen(tmp->pstring), file);
			fwrite("\n", sizeof(char), 1, file);
				
			tmp = tmp->pnext;
		}
		fclose(file);
		return true;
	}
	else
	{
		return PushError(ERROR_ID_CANT_OPEN_FILE);
	}

	return false;
}

bool ResourceManager::BuildResourceList(EntityManager* manager)
{
	if (manager != 0)
	{
		for (int i = 0; i < manager->GetEntityCount(); i++)
		{
			Entity* entity = manager->GetEntityByIndex(i);

			if (IsResource(entity))
			{
				char* res = GetResourceValue(entity);

				if (res != 0)
				{
					if (!DoesExcist(res))
						AddResource(res);
				}
			}
		}

		Entity* worldspawn = manager->GetEntityByName("worldspawn");
		if (worldspawn != 0)
		{
			if (worldspawn->GetAttributeByName("skyname") != 0)
			{
				skynames.SetUp(worldspawn, ".tga");
				AddResources(skynames.GetSkyResourceList());	
			}
			if (worldspawn->GetAttributeByName("wad") != 0)
			{
				wadfiles.SetUp(worldspawn);
				AddResources(wadfiles.GetWadResourceList());
			}
		}
		return true;
	}
	
	return false;
}

int ResourceManager::AddResourceType(char* entity, char* key)
{
	ResourceItem* item;
	char* e, *k;

	e = new char[strlen(entity)+1];
	k = new char[strlen(key)+1];
	strcpy(e, entity);
	strcpy(k, key);
	
	item = new ResourceItem;
	item->pentity = e;
	item->pkey = k;
	item->pnext = this->firstResourceType;

	this->firstResourceType = item;
	this->resourceTypeCount++;

	return this->resourceTypeCount;
}

int ResourceManager::GetResourceTypeCount()
{
	return this->resourceTypeCount;
}

char* ResourceManager::GetResourceTypeByIndex(int index)
{
	if (index >= 0 && index < this->resourceTypeCount)
	{
		ResourceItem* res = this->firstResourceType;
		int i = 0;

		while (res != 0)
		{
			if (i == index)
				return res->pentity;
				
			res = res->pnext;
			i++;
		}
	}
	return 0;
}

bool ResourceManager::IsResource(Entity* entity)
{
	if (entity != 0)
	{
		ResourceItem* res = this->firstResourceType;
		while (res != 0)
		{
			if (strcmp(entity->GetName(), res->pentity) == 0)
				return true;
			res = res->pnext;
		}
	}
	return false;
}

bool ResourceManager::DoesExcist(char* resource)
{
	if (resource != 0)
	{
		StringItem* res = this->firstResource;
		while (res != 0)
		{
			if (strcmp(resource, res->pstring) == 0)
				return true;
			res = res->pnext;
		}
	}
	return false;
}

char* ResourceManager::GetResourceValue(Entity* entity)
{
	if (entity != 0)
	{
		ResourceItem* res = this->firstResourceType;
		int i = 0;

		while (res != 0)
		{
			if (strcmp(entity->GetName(), res->pentity) == 0)
			{
				return entity->GetAttributeByName(res->pkey)->GetValue();
			}
				
			res = res->pnext;
			i++;
		}
	}
	return 0;
}

void ResourceManager::SetResourceItem(char* resourceItem, int index)
{
	if (index >= 0 && index < this->resourceCount)
	{
		StringItem* tmp = this->firstResource;

		for (int i = 0; i < index; i++)
		{
			tmp = tmp->pnext;
		}

		int len = strlen(resourceItem);
		char* n = new char[len + 1];
		memset(n, 0, len + 1);
		strcpy(n, resourceItem);

		delete tmp->pstring;
		tmp->pstring = n;
	}
}
