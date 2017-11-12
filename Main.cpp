// Main.cpp: implementation of the Main class.
//
//////////////////////////////////////////////////////////////////////

#include "Main.h"

//////////////////////////////////////////////////////////////////////
// WinMain
//////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main main;

	if (main.Create(hInstance) == TRUE)
	{
		return main.RunToClose();
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Main::Main()
{
	this->strWindowTitle = ".res Exporter";
	this->uCreationHeight = 500;
	this->uCreationWidth = 350;
	this->hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON));
	this->hFont = CreateFont(12,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,NULL,"Verdana"); 

	this->resources = 0;
	this->strFilename[0] = '\0';
}

Main::~Main()
{
	if (this->resources != 0)
		delete this->resources;
}

LRESULT Main::MessageProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			OnCreate();
			break;
		}

	case WM_SIZE:
		{
			OnSize(wParam, lParam);
			break;
		}

	case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDADD:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnAddButtonClicked();
							break;
						}
					}
					break;
				}

			case IDREM:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnRemButtonClicked();
							break;
						}
					}
					break;
				}

			case IDSAVE:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnSaveButtonClicked();
							break;
						}
					}
					break;
				}

			case IDOPEN:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnOpenButtonClicked();
							break;
						}
					}
					
					break;
				}

			case IDEXPORT:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnExportButtonClicked();
							break;
						}
					}
					break;
				}
			
			case IDEXPORTTO:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnExportToButtonClicked();
							break;
						}
					}
					break;
				}

			case IDBATCH:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnBatchButtonClicked();
							break;
						}
					}
					break;
				}

			case IDHELPBUTTON:
				{
					switch (HIWORD(wParam))
					{
					case BN_CLICKED:
						{
							OnHelpButtonClicked();
							break;
						}
					}
					break;
				}

			case IDNAME:
				{
					switch (HIWORD(wParam))
					{
					case EN_CHANGE:
					case EN_UPDATE:
						{
							OnNameEditBoxChanged();
							break;
						}
					}
					break;
				}

			case IDRESOURCES:
				{
					switch (HIWORD(wParam))
					{
					case LBN_SELCHANGE:
						{
							OnResourcesListSelectionChanged();
							break;
						}
					}
					break;
				}
			}
			break;
		}

	case WM_CLOSE:
		{
			OnClose();
			break;
		}
	}
	return Window::MessageProc(uMsg, wParam, lParam);
}

void Main::UpdateButonStates()
{
	this->exportTo.Disable();
	this->rem.Disable();
	this->add.Disable();
	this->export.Disable();
	this->saveName.Disable();

	if (this->resources != 0)
	{
		this->export.Enable();
		this->exportTo.Enable();
		
		if (this->resourcesList.GetSelectedIndex() != -1)
			this->rem.Enable();

		if (strlen(this->resourceName.GetTitle()) > 0)
		{
			this->saveName.Enable();
			this->add.Enable();
		}
	}
}

void Main::ShowError(int iError)
{
	CHAR strError[256] = {0};
	
	if (iError != 0)
	{
		switch (iError)
		{
		case ERROR_ID_NO_MEMORY_AVAILABLE:
			{
				LoadString(GetModuleHandle(NULL), IDS_NO_MEMORY, strError, 256);
				break;
			}
		case ERROR_ID_CANT_OPEN_FILE:
			{
				LoadString(GetModuleHandle(NULL), IDS_CANT_OPEN, strError, 256);
				break;
			}

		case ERROR_ID_WRONG_EXTENSION:
			{
				LoadString(GetModuleHandle(NULL), IDS_WRONG_EXTENSION, strError, 256);
				break;
			}

		case ERROR_ID_NO_ENTITIES_FOUND:
			{
				LoadString(GetModuleHandle(NULL), IDS_NO_ENTITIES, strError, 256);
				break;
			}

		case ERROR_ID_WRONG_BSP_VERSION:
			{
				LoadString(GetModuleHandle(NULL), IDS_WRONG_BSP_VERSION, strError, 256);
				break;
			}

		case ERROR_ID_LIST_BUILD_FAILED:
			{
				LoadString(GetModuleHandle(NULL), IDS_LIST_BUILD_FAILED, strError, 256);
				break;
			}
		}
		::MessageBox(this->hWnd, strError, "Open file", MB_OK | MB_ICONWARNING);
	}
}

void Main::ListResource()
{
	this->resourcesList.Clear();

	if (this->resources != 0)
	{
		for (int i = 0; i < this->resources->GetResourceCount(); i++)
		{
			this->resourcesList.AddItem(this->resources->GetResourceByIndex(i), 0, 0);
		}
	}
}
	
const char* Main::GetExtension(const char* filename)
{
	int len = strlen(filename);

	for (int i = len; i > 0; i--)
	{
		if (filename[i] == '.')
		{
			return filename + i;
		}
	}
	return filename;
}