// BatchDlg.cpp: implementation of the BatchDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "BatchDlg.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BatchDlg::BatchDlg()
{
}

BatchDlg::~BatchDlg()
{
}

VOID BatchDlg::DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			break;
		}

	case WM_SIZE:
		{
			break;
		}
	}
	CustomDialog::DlgProc(uMsg, wParam, lParam);
}
