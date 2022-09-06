#if !defined(AFX_MYRICHEDITCTRL_H__DEFD107A_0DA6_46D9_A0F0_0683B7E1091F__INCLUDED_)
#define AFX_MYRICHEDITCTRL_H__DEFD107A_0DA6_46D9_A0F0_0683B7E1091F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomRichEditCtr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomRichEditCtrl window

class CCustomRichEditCtrl : public CRichEditCtrl
{
// Construction
// @access Public Member Functions and Variables
public:
	// @cmember
	// constructor
	CCustomRichEditCtrl();

// Attributes
public:

	BOOL bold;
	BOOL italic;
	BOOL underlined;


	CHARFORMAT cf;
	PARAFORMAT pf;

// Operations
public:

    // Calling this will insert the file content. 
    void SetRtf(CFile* pInputFile );
    // set the selection bold
	void SetSelectionBold();
    // set the selection italic
	void SetSelectionItalic();
    // set the selection underlined
	void SetSelectionUnderline();
    // displays a color selection dialog box and sets the selection 
	// to the chosen color (if OK is pressed).  
	void SetColour();
	// this is for CFontDialog color box
	void SetColor(COLORREF clr);
    // sets the current paragraph to be left justified
	void SetParagraphLeft();

    // sets the current paragraph to be right justified
	void SetParagraphRight();

    // sets the current paragraph to be centered
	void SetParagraphCenter();

    // sets the current paragraph to be bulleted
	void SetParagraphBulleted();

    // sets the font name
	void SetFontName(CString sFontName);

    // sets the font size
	void SetFontSize(int nFontSize);

    // print the rich edit control content
	void Print(BOOL bShowPrintDialog = TRUE);

	BOOL SelectionIsBold();
	BOOL SelectionIsItalic();
	BOOL SelectionIsUnderlined();
	BOOL ParagraphIsCentered();
	BOOL ParagraphIsLeft();
	BOOL ParagraphIsBulleted();
	BOOL ParagraphIsRight();
	BOOL m_bClick;
	BOOL m_bTab;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomRichEditCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	// destructor
	virtual ~CCustomRichEditCtrl();
private:
	// My callback procedure that writes the file content to the
	// rich edit control
	// function from VC help(MSDN)
	static DWORD CALLBACK StreamInCallback(DWORD dwCookie,LPBYTE pbBuff, 
		                              LONG cb, LONG *pcb);

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomRichEditCtrl)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYRICHEDITCTRL_H__DEFD107A_0DA6_46D9_A0F0_0683B7E1091F__INCLUDED_)
