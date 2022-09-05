#if !defined(AFX_SETTINGDLG_H__51D892EF_A2F0_49EB_8C31_CA4DD0CA2322__INCLUDED_)
#define AFX_SETTINGDLG_H__51D892EF_A2F0_49EB_8C31_CA4DD0CA2322__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog
class CSettingDlg : public CDialog
{
// Construction
public:
	CString GetBanner() const;
	CString GetTitle() const;
	CString GetText() const;
	DWORD GetFlags() const;
	CSettingDlg(DWORD dwFlags, LPCTSTR lpText, LPCTSTR lpDlgTitle, LPCTSTR lpDlgBanner, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_SETTINGDLG };
	BOOL	m_bBrowseForFolder;
	CString	m_sBtnText;
	BOOL	m_bFlat;
	BOOL	m_bLeft;
	int		m_nIcon;
	BOOL	m_bAllowEdit;
	CString	m_sDlgTitle;
	CString	m_sDlgBanner;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	DWORD m_dwFlags;

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	afx_msg void OnIcon();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBrowseforfolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__51D892EF_A2F0_49EB_8C31_CA4DD0CA2322__INCLUDED_)
