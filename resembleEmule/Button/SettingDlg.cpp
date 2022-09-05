// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\CommonCtrls.h"
#include "SettingDlg.h"
#include "BrowseCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog

CSettingDlg::CSettingDlg(DWORD dwFlags, LPCTSTR lpText, LPCTSTR lpDlgTitle, LPCTSTR lpDlgBanner, CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
	m_bBrowseForFolder = FALSE;
	m_sBtnText = _T("");
	m_bFlat = FALSE;
	m_bLeft = FALSE;
	m_nIcon = -1;
	m_bAllowEdit = FALSE;
	m_sDlgTitle = lpDlgTitle;
	m_sDlgBanner = lpDlgBanner;
	//}}AFX_DATA_INIT
	m_dwFlags = dwFlags;
	m_sBtnText = lpText;
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_Check(pDX, IDC_BROWSEFORFOLDER, m_bBrowseForFolder);
	DDX_Text(pDX, IDC_BTNTEXT, m_sBtnText);
	DDX_Check(pDX, IDC_FLAT, m_bFlat);
	DDX_Check(pDX, IDC_LEFT, m_bLeft);
	DDX_Radio(pDX, IDC_ICONS, m_nIcon);
	DDX_Check(pDX, IDC_ALLOWEDIT, m_bAllowEdit);
	DDX_Text(pDX, IDC_DLGTITLE, m_sDlgTitle);
	DDX_Text(pDX, IDC_DLGBANNER, m_sDlgBanner);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_BN_CLICKED(IDC_ICONS, OnIcon)
	ON_BN_CLICKED(IDC_RADIO2, OnIcon)
	ON_BN_CLICKED(IDC_RADIO3, OnIcon)
	ON_BN_CLICKED(IDC_RADIO4, OnIcon)
	ON_BN_CLICKED(IDC_BROWSEFORFOLDER, OnBrowseforfolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers
BOOL CSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAllowEdit = (m_dwFlags & BC_CTL_ALLOWEDIT) != 0;
	m_bBrowseForFolder = (m_dwFlags & BC_CTL_FOLDERSONLY) != 0;

	if (m_dwFlags & BC_BTN_ICON)
	{
		if (m_dwFlags & BC_ICO_ARROWFOLDER)
			m_nIcon = 1;
		else if (m_dwFlags & BC_ICO_FOLDER)
			m_nIcon = 2;
		else if (m_dwFlags & BC_ICO_EXPLORER)
			m_nIcon = 3;
	}
	else
	{
		m_nIcon = 0;
	}
	m_bFlat = (m_dwFlags & BC_BTN_FLAT) != 0;
	m_bLeft = (m_dwFlags & BC_BTN_LEFT) != 0;
	UpdateData(FALSE);
	GetDlgItem(IDC_BTNTEXT)->EnableWindow(m_nIcon == 0);
	GetDlgItem(IDC_DLGBANNER)->EnableWindow(m_bBrowseForFolder);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDlg::OnIcon() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	
	GetDlgItem(IDC_BTNTEXT)->EnableWindow(m_nIcon == 0);
}

void CSettingDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	if (m_bAllowEdit)
		m_dwFlags |= BC_CTL_ALLOWEDIT;
	else
		m_dwFlags &= ~BC_CTL_ALLOWEDIT;

	if (m_bBrowseForFolder)
		m_dwFlags |= BC_CTL_FOLDERSONLY;
	else
		m_dwFlags &= ~BC_CTL_FOLDERSONLY;

	if (m_bFlat)
		m_dwFlags |= BC_BTN_FLAT;
	else
		m_dwFlags &= ~BC_BTN_FLAT;

	if (m_bLeft)
		m_dwFlags |= BC_BTN_LEFT;
	else
		m_dwFlags &= ~BC_BTN_LEFT;

	m_dwFlags &= ~BC_ICO_ARROWFOLDER;
	m_dwFlags &= ~BC_ICO_FOLDER;
	m_dwFlags &= ~BC_ICO_EXPLORER;	
	switch (m_nIcon)
	{
	case 0:
		m_dwFlags &= ~BC_BTN_ICON;
		break;

	case 1:
		m_dwFlags |= BC_BTN_ICON | BC_ICO_ARROWFOLDER;
		break;

	case 2:
		m_dwFlags |= BC_BTN_ICON | BC_ICO_FOLDER;
		break;

	case 3:
		m_dwFlags |= BC_BTN_ICON | BC_ICO_EXPLORER;
		break;

	default:
		break;
	}	

	EndDialog(IDOK);
}

DWORD CSettingDlg::GetFlags() const
{
	return m_dwFlags;
}

CString CSettingDlg::GetText() const
{
	return m_sBtnText;
}

void CSettingDlg::OnBrowseforfolder() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDlgItem(IDC_DLGBANNER)->EnableWindow(m_bBrowseForFolder);
}

CString CSettingDlg::GetTitle() const
{
	return m_sDlgTitle;
}

CString CSettingDlg::GetBanner() const
{
	return m_sDlgBanner;
}
