#if !defined(AFX_CUSTOMBUTTON_H__CB911107_87CF_400E_B1B3_EF330B5B2389__INCLUDED_)
#define AFX_CUSTOMBUTTON_H__CB911107_87CF_400E_B1B3_EF330B5B2389__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomButton dialog
#include "BrowseCtrl.h"
#include "BtnST.h"
class CCustomButton : public CDialog
{
// Construction
public:
	CCustomButton(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomButton)
	enum { IDD = IDD_BROWSECTRLDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	CBrowseCtrl	m_wndCtrl;
	//}}AFX_DATA
public:
	CButtonST	m_btnSettings;
	CButtonST	m_btnResults;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomButton)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCustomButton)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	virtual BOOL OnInitDialog();
	afx_msg void OnSettings();
	afx_msg void OnResults();
	afx_msg LRESULT OnFileCtrlNotify(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMBUTTON_H__CB911107_87CF_400E_B1B3_EF330B5B2389__INCLUDED_)
