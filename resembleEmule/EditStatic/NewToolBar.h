#if !defined(AFX_NEWTOOLBAR_H__719D4150_F5A1_4283_A0B7_BC1F996108B5__INCLUDED_)
#define AFX_NEWTOOLBAR_H__719D4150_F5A1_4283_A0B7_BC1F996108B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNewToolBar window

class CNewToolBar : public CToolBar
{
// Construction
public:
	CNewToolBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNewToolBar)
	afx_msg LRESULT OnKickIdle(WPARAM wParam, LPARAM);
	afx_msg LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTOOLBAR_H__719D4150_F5A1_4283_A0B7_BC1F996108B5__INCLUDED_)
