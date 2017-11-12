// HelpDlg.h: interface for the HelpDlg class.
//
//////////////////////////////////////////////////////////////////////

#ifndef HELPDLG_H
#define HELPDLG_H

#include "CustomDialog.h"
#include "resource.h"

class HelpDlg : public CustomDialog  
{
private:
	VOID DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	HelpDlg();
	virtual ~HelpDlg();

};

#endif
