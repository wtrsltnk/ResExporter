// BatchDlg.h: interface for the BatchDlg class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BATCHDLG_H
#define BATCHDLG_H

#include "CustomDialog.h"
#include "Button.h"
#include "EditBox.h"
#include "ListBox.h"
#include "OpenDialog.h"
#include "SaveDialog.h"

class BatchDlg : public CustomDialog  
{
private:
	ListBox files;

private:
	VOID DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	BatchDlg();
	virtual ~BatchDlg();

};

#endif
