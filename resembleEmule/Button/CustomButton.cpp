// CustomButton.cpp : implementation file
//

#include "stdafx.h"
#include "..\CommonCtrls.h"
#include "CustomButton.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomButton dialog

#define WM_BROWSECTRL_NOTIFY	WM_APP + 100
CCustomButton::CCustomButton(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomButton::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomButton)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCustomButton::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomButton)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_CTRL, m_wndCtrl);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_SETTINGS, m_btnSettings);
	DDX_Control(pDX, IDC_RESULTS, m_btnResults);

}



BEGIN_MESSAGE_MAP(CCustomButton, CDialog)
	//{{AFX_MSG_MAP(CCustomButton)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SETTINGS, OnSettings)
	ON_BN_CLICKED(IDC_RESULTS, OnResults)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomButton message handlers

BOOL CCustomButton::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
	
	// TODO: Add extra initialization here
	m_wndCtrl.SetNotifyMessageID(WM_BROWSECTRL_NOTIFY);	
	m_wndCtrl.SetTooltipText(_T("单击这里浏览！"));

	short	shBtnColor = 60;
	// Settings button
	m_btnSettings.SetIcon(IDI_TOOLS4);
	m_btnSettings.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnSettings.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 128, 0));
	m_btnSettings.SetAlign(CButtonST::ST_ALIGN_HORIZ_RIGHT);
#ifdef	BTNST_USE_SOUND
	m_btnSettings.SetSound(MAKEINTRESOURCE(IDR_WAVHOVER), ::GetModuleHandle(NULL));
#endif

	// Results button
	m_btnResults.SetIcon(IDI_HELP2);
	m_btnResults.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnResults.SetColor(CButtonST::BTNST_COLOR_FG_IN, RGB(0, 128, 0));
	m_btnResults.SetAlign(CButtonST::ST_ALIGN_HORIZ_RIGHT);
#ifdef	BTNST_USE_SOUND
	m_btnResults.SetSound(MAKEINTRESOURCE(IDR_WAVHOVER), ::GetModuleHandle(NULL));
#endif

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CCustomButton::OnSettings() 
{
	// TODO: Add your control notification handler code here
	CSettingDlg dlg(m_wndCtrl.GetButtonStyle(), m_wndCtrl.GetButtonText(), m_wndCtrl.GetDialogTitle(), m_wndCtrl.GetDialogBanner());
	if (dlg.DoModal() == IDOK)
	{
		m_wndCtrl.SetButtonStyle(dlg.GetFlags());
		m_wndCtrl.SetButtonText(dlg.GetText());
		m_wndCtrl.SetDialogTitle(dlg.GetTitle());
		m_wndCtrl.SetDialogBanner(dlg.GetBanner());
	}
}

void CCustomButton::OnResults() 
{
	// TODO: Add your control notification handler code here
	CString str(_T("选择的目标：\n\n"));
	POSITION pos = m_wndCtrl.GetStartPosition();
	while (pos != NULL)
		str += m_wndCtrl.GetNextPathName(pos) + _T("\n");
	
	MessageBox(str, _T("浏览结果"));
}

LRESULT CCustomButton::OnFileCtrlNotify(WPARAM wParam, LPARAM lParam)
{
	// The user just activated and closed the file dialog.
	CBrowseCtrl* pCtrl = (CBrowseCtrl*)lParam; // pointer to the CBrowseCtrl object.
	ASSERT(pCtrl == &m_wndCtrl);
	
	if ((int)wParam == IDOK)
	{
		// ***** The file dialog was closed by the "OK" button *****
		// TODO: Add your control notification handler code here
	}
	else
	{
		// ***** The file dialog was closed by the "Cancel" button *****		
		// TODO: Add your control notification handler code here
		
	}
	
	pCtrl = NULL; // Appeases VC6 warning level 4.
	return (LRESULT)0;
}