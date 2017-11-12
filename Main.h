// Main.h: interface for the Main class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MAIN_H
#define MAIN_H

#include "Window.h"
#include "Button.h"
#include "EditBox.h"
#include "ListBox.h"
#include "OpenDialog.h"
#include "SaveDialog.h"
#include "HelpDlg.h"

#include "MAPOpener.h"
#include "BSPOpener.h"

#include "resource.h"

#define IDOPEN 342
#define IDNAME 343
#define IDSAVE 344
#define IDRESOURCES 345
#define IDEXPORT 346
#define IDADD 347
#define IDREM 348
#define IDEXPORTTO 349
#define IDBATCH 350
#define IDHELPBUTTON 351

#define ERROR_ID_WRONG_EXTENSION 87569

class Main : public Window  
{
private:
	HFONT hFont;
	EditBox resourceName;
	ListBox resourcesList;

	Button add;
	Button rem;
	Button saveName;

	Button openfile;
    Button _export;
	Button exportTo;
	Button batch;
	Button help;

	ResourceManager* resources;

	char strFilename[256];

private:
	LRESULT MessageProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void UpdateButonStates();

	void ShowError(int iError);

	void ListResource();
	const char* GetExtension(const char* filename);

	void OnAddButtonClicked();
	void OnRemButtonClicked();
	void OnSaveButtonClicked();

	void OnOpenButtonClicked();
	void OnExportButtonClicked();
	void OnExportToButtonClicked();
	void OnBatchButtonClicked();
	void OnHelpButtonClicked();

	void OnNameEditBoxChanged();
	void OnResourcesListSelectionChanged();

	void OnCreate();
	void OnSize(WPARAM wParam, LPARAM lParam);
	void OnClose();



public:
	Main();
	virtual ~Main();

};

#endif
