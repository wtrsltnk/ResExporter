// MainButtons.cpp: implementation of the Main class.
//
//////////////////////////////////////////////////////////////////////

#include "Main.h"

void Main::OnAddButtonClicked()
{
	if (this->resources != 0)
	{
		char* txt = this->resourceName.GetTitle();
		
		if (strlen(txt) > 0)
		{
			if (!this->resources->DoesExcist(txt))
				this->resources->AddResource(txt);
			
			ListResource();
			UpdateButonStates();
		}
	}
}

void Main::OnRemButtonClicked()
{
	int selection = this->resourcesList.GetSelectedIndex();

	if (selection > 0)
	{
		this->resources->RemoveResource(selection);
		
		ListResource();
		UpdateButonStates();
	}
}

void Main::OnSaveButtonClicked()
{
	if (this->resources != 0)
	{
		int selection = this->resourcesList.GetSelectedIndex();

		if (selection > 0)
		{
			char* txt = this->resourceName.GetTitle();

			if (strlen(txt) > 0)
			{
				this->resources->SetResourceItem(txt, selection);
				ListResource();
				UpdateButonStates();
			}
		}
	}
}

void Main::OnOpenButtonClicked()
{
	CHAR strFile[MAX_PATH] = {0};
	int iError = 0;
	INT filterIndex = 1;

	OpenDialog dlg;
	if (dlg.Show(this->hWnd, "BSP Files (*.bsp)\0*.bsp\0MAP Files (*.map)\0*.map\0", filterIndex, strFile))
	{
		strcpy(this->strFilename, strFile);
		const char* extension = GetExtension(strFile);

		if (strcmp(extension, ".map") == 0)
		{
			MAPOpener mapOpener;
			this->resources = mapOpener.Open(strFile);

			if (mapOpener.HasErrors())
			{
				Err err;
				mapOpener.PopError(err);
				iError = err.id;
			}
		}
		else if (strcmp(extension, ".bsp") == 0)
		{
			BSPOpener bspOpener;
			this->resources = bspOpener.Open(strFile);

			if (bspOpener.HasErrors())
			{
				Err err;
				bspOpener.PopError(err);
				iError = err.id;
			}
		}
		else
		{
			iError = ERROR_ID_WRONG_EXTENSION;
		}
		
		ShowError(iError);

		ListResource();
		UpdateButonStates();
	}
}

void Main::OnExportButtonClicked()
{
	if (this->resources != 0)
	{
		if (this->resourcesList.Count() > 0)
		{
			char filename[256] = {0};

			strcpy(filename, this->strFilename);

			int len = strlen(filename);

			filename[len-3] = 'r';
			filename[len-2] = 'e';
			filename[len-1] = 's';

			if (this->resources->WriteToFile(filename))
			{
				char strMsg[256] = {0};
				
				LoadString(GetModuleHandle(NULL), IDS_SUCCESFULL_EXPORT, strMsg, 256);
				MessageBox(this->hWnd, strMsg, "Succesfull", MB_OK);
			}
			else
			{
				Err err;
				this->resources->PopError(err);
				ShowError(err.id);
			}
		}
	}
}

void Main::OnExportToButtonClicked()
{
	if (this->resources != 0)
	{
		if (this->resourcesList.Count() > 0)
		{
			CHAR strFile[MAX_PATH] = {0};
			INT filterIndex = 1;
			SaveDialog saveDlg;

			if (saveDlg.Show(this->hWnd, "Resource file (*.res)\0*.res", filterIndex, strFile))
			{
				if (this->resources->WriteToFile(strFile))
				{
					char strMsg[256] = {0};
					
					LoadString(GetModuleHandle(NULL), IDS_SUCCESFULL_EXPORT, strMsg, 256);
					MessageBox(this->hWnd, strMsg, "Succesfull", MB_OK);
				}
				else
				{
				Err err;
				this->resources->PopError(err);
				ShowError(err.id);
				}
			}
		}
	}
}

void Main::OnBatchButtonClicked()
{
	::MessageBox(this->hWnd, "Not implemented yet...", "Srry guys:*(", MB_OK);
}

void Main::OnHelpButtonClicked()
{
	HelpDlg helpDlg;
	helpDlg.ShowModal(this->hInstance, this->hWnd);
}

void Main::OnNameEditBoxChanged()
{
	UpdateButonStates();
}

void Main::OnResourcesListSelectionChanged()
{
	if (this->resources != 0)
	{
		int selection = this->resourcesList.GetSelectedIndex();

		this->resourceName.SetTitle(this->resources->GetResourceByIndex(selection));
		
		UpdateButonStates();
	}
}

void Main::OnCreate()
{
	this->add.Create(this->hWnd, IDADD);
	this->add.Size(24, 24);
	this->add.SetTitle("+");
	this->add.SetFont(this->hFont);

	this->rem.Create(this->hWnd, IDREM);
	this->rem.Size(24, 24);
	this->rem.SetTitle("-");
	this->rem.SetFont(this->hFont);

	this->saveName.Create(this->hWnd, IDSAVE);
	this->saveName.Size(50, 24);
	this->saveName.SetTitle("Save");
	this->saveName.SetFont(this->hFont);

	this->openfile.Create(this->hWnd, IDOPEN);
	this->openfile.Size(50, 24);
	this->openfile.SetTitle("Open...");
	this->openfile.SetFont(this->hFont);

	this->export.Create(this->hWnd, IDEXPORT);
	this->export.Size(50, 24);
	this->export.SetTitle("Export");
	this->export.SetFont(this->hFont);

	this->exportTo.Create(this->hWnd, IDEXPORTTO);
	this->exportTo.Size(65, 24);
	this->exportTo.SetTitle("Export to...");
	this->exportTo.SetFont(this->hFont);

	this->batch.Create(this->hWnd, IDBATCH);
	this->batch.Size(50, 24);
	this->batch.SetTitle("Batch...");
	this->batch.SetFont(this->hFont);

	this->help.Create(this->hWnd, IDHELPBUTTON);
	this->help.Size(50, 24);
	this->help.SetTitle("Help!");
	this->help.SetFont(this->hFont);

	this->resourceName.Create(this->hWnd, IDNAME, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, WS_EX_STATICEDGE);
	this->resourceName.Move(10, 11);
	this->resourceName.SetTitle("");
	this->resourceName.SetFont(this->hFont);

	this->resourcesList.Create(this->hWnd, IDRESOURCES, WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY, WS_EX_STATICEDGE);
	this->resourcesList.Move(10, 40);
	this->resourcesList.SetFont(this->hFont);
	
	UpdateButonStates();

}

void Main::OnSize(WPARAM wParam, LPARAM lParam)
{
	this->add.Move(LOWORD(lParam) - 148, 10);
	this->rem.Move(LOWORD(lParam) - 114, 10);
	this->saveName.Move(LOWORD(lParam) - 10 - 70, 10);

	this->openfile.Move(10, HIWORD(lParam) - 34);
	this->export.Move(70, HIWORD(lParam) - 34);
	this->exportTo.Move(130, HIWORD(lParam) - 34);
	this->batch.Move(205, HIWORD(lParam) - 34);
	this->help.Move(265, HIWORD(lParam) - 34);

	this->resourceName.Size(LOWORD(lParam) - 30 - 70 - 24 -24 - 20, 22);
	this->resourcesList.Size(LOWORD(lParam) - 20, HIWORD(lParam) - 76);
}

void Main::OnClose()
{
	//if (::MessageBox(this->hWnd, "Weet je zeker dat je wil sluiten?", this->strWindowTitle, MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
	//	return FALSE;
	}
}