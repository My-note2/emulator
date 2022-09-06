/*===========================================================================
====                                                                     ====
====    File name           :  EditTrans.h                               ====
====    Creation date       :  7/10/2001                                 ====
====    Author(s)           :  Dany Cantin                               ====
====                                                                     ====
===========================================================================*/

#ifndef EDITTRANS_H
#define EDITTRANS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CEditTrans window

#define TRANS_BACK -1

class CEditTrans : public CEdit
{
// Construction
public:
	CEditTrans();

// Attributes
private:
    COLORREF m_TextColor;
    COLORREF m_BackColor;
    CBrush   m_Brush;

// Operations
public:
    void SetTextColor(COLORREF col) { m_TextColor = col;
                                      Invalidate();      }
    void SetBackColor(COLORREF col) { m_BackColor = col;
                                      Invalidate();     }
private:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditTrans)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditTrans();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditTrans)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


#endif // EDITTRANS_H
