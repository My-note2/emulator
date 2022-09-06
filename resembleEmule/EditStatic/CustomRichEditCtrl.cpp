// CustomRichEditCtrl.cpp : implementation file
//
// Filename:      CustomRichEditCtrl.cpp

#include "stdafx.h"
#include "..\CommonCtrls.h"
#include "CustomRichEditCtrl.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomRichEditCtrl

CCustomRichEditCtrl::CCustomRichEditCtrl()
{
	bold = TRUE;
	italic = TRUE;
	underlined = TRUE;
	m_bClick=FALSE;
	m_bTab=FALSE;
}



CCustomRichEditCtrl::~CCustomRichEditCtrl()
{
}


BEGIN_MESSAGE_MAP(CCustomRichEditCtrl, CRichEditCtrl)
	//{{AFX_MSG_MAP(CCustomRichEditCtrl)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomRichEditCtrl message handlers


DWORD CALLBACK CCustomRichEditCtrl ::StreamInCallback(DWORD dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb)
{
   CFile* pFile = (CFile*) dwCookie;
   ASSERT_KINDOF(CFile,pFile);
   *pcb = pFile->Read(pbBuff, cb);
   return 0;
}


void CCustomRichEditCtrl::SetRtf(CFile* pInputFile )
{
	//∂¡»ÎŒƒ±æ
	EDITSTREAM es;
	es.dwError = 0;
	es.pfnCallback = StreamInCallback;
	es.dwCookie = (DWORD)pInputFile;
	StreamIn(SF_RTF, es);
}

void CCustomRichEditCtrl::SetSelectionBold()
{
	cf.cbSize = sizeof(CHARFORMAT);
	GetSelectionCharFormat(cf);
	
	if (cf.dwMask & CFM_BOLD)	// selection is all the same
	{
		cf.dwEffects ^= CFE_BOLD; 
	}
	else
	{
		cf.dwEffects |= CFE_BOLD;
	}
	
	cf.dwMask = CFM_BOLD;

	SetSelectionCharFormat(cf);
}


void CCustomRichEditCtrl::SetSelectionItalic()
{
	cf.dwMask = CFM_ITALIC;
	if ( italic == TRUE )	
		 cf.dwEffects |= CFE_ITALIC;
	else 
		 cf.dwEffects &= ~CFE_ITALIC;
	SetSelectionCharFormat(cf);
	italic = !italic;
}


void CCustomRichEditCtrl::SetSelectionUnderline()
{
	cf.dwMask = CFM_UNDERLINE;
	if ( underlined == TRUE )	
		 cf.dwEffects |= CFE_UNDERLINE;
	else 
		 cf.dwEffects &= ~CFE_UNDERLINE;
	SetSelectionCharFormat(cf);
	underlined = !underlined;
}

void CCustomRichEditCtrl::SetColour()
{
	CColorDialog dlg;
	
	if (cf.dwEffects & CFE_AUTOCOLOR) 
		cf.dwEffects -= CFE_AUTOCOLOR;
	
	// Get a color from the common color dialog box
	if ( dlg.DoModal() == IDOK )
	{
		cf.crTextColor = dlg.GetColor();
	}
	cf.dwMask = CFM_COLOR;	

	SetSelectionCharFormat(cf);
}


void CCustomRichEditCtrl::SetParagraphLeft()
{

	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask = PFM_ALIGNMENT;    
	pf.wAlignment = PFA_LEFT;
	
	SetParaFormat(pf);
}



void CCustomRichEditCtrl::SetParagraphRight()
{

	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask = PFM_ALIGNMENT;    
	pf.wAlignment = PFA_RIGHT;
	
	SetParaFormat(pf);
}


void CCustomRichEditCtrl::SetParagraphCenter()
{

	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask = PFM_ALIGNMENT;    
	pf.wAlignment = PFA_CENTER;
	
	SetParaFormat(pf);
}



void CCustomRichEditCtrl::SetParagraphBulleted()
{
	GetParaFormat(pf);

	if ( (pf.dwMask & PFM_NUMBERING) && (pf.wNumbering == PFN_BULLET) )
	{
		pf.wNumbering = 0;
		pf.dxOffset = 0;
		pf.dxStartIndent = 0;
		pf.dwMask = PFM_NUMBERING | PFM_STARTINDENT | PFM_OFFSET;
	}
	else
	{
		pf.wNumbering = PFN_BULLET;
		pf.dwMask = PFM_NUMBERING;
		if (pf.dxOffset == 0)
		{
			pf.dxOffset = 4;
			pf.dwMask = PFM_NUMBERING | PFM_STARTINDENT | PFM_OFFSET;
		}
	}

	SetParaFormat(pf);
}



void CCustomRichEditCtrl::SetFontName(CString sFontName)
{
    GetSelectionCharFormat(cf);

	// Set the font name.
	strcpy (cf.szFaceName, sFontName);
	cf.dwMask |=CFM_FACE;
	SetSelectionCharFormat(cf);
}



void CCustomRichEditCtrl::SetFontSize(int nFontSize)
{
	GetSelectionCharFormat(cf);
	nFontSize *= 2;	// convert from to twips
	cf.yHeight = nFontSize ;
	cf.dwMask = CFM_SIZE;

	SetSelectionCharFormat ( cf );
}


void CCustomRichEditCtrl::Print(BOOL bShowPrintDialog)
{
	CPrintDialog printDialog(FALSE);
	
	
	if (bShowPrintDialog)
	{
		int r = printDialog.DoModal();
		if (r == IDCANCEL)
			return; // User pressed cancel, don't print.
	}
	else
	{
		printDialog.GetDefaults();
	}

	HDC hPrinterDC = printDialog.GetPrinterDC();

	// This code basically taken from MS KB article Q129860 
	
	FORMATRANGE fr;
	  int	  nHorizRes = GetDeviceCaps(hPrinterDC, HORZRES);
	  int	  nVertRes = GetDeviceCaps(hPrinterDC, VERTRES);
      int     nLogPixelsX = GetDeviceCaps(hPrinterDC, LOGPIXELSX);
	  int     nLogPixelsY = GetDeviceCaps(hPrinterDC, LOGPIXELSY);
	  LONG	      lTextLength;   // Length of document.
	  LONG	      lTextPrinted;  // Amount of document printed.

	 // Ensure the printer DC is in MM_TEXT mode.
	  SetMapMode ( hPrinterDC, MM_TEXT );

	 // Rendering to the same DC we are measuring.
	  ZeroMemory(&fr, sizeof(fr));
	  fr.hdc = fr.hdcTarget = hPrinterDC;

	 // Set up the page.
	  fr.rcPage.left     = fr.rcPage.top = 0;
	  fr.rcPage.right    = (nHorizRes/nLogPixelsX) * 1440;
	  fr.rcPage.bottom   = (nVertRes/nLogPixelsY) * 1440;

	 // Set up 0" margins all around.
	  fr.rc.left   = fr.rcPage.left ;//+ 1440;  // 1440 TWIPS = 1 inch.
	  fr.rc.top    = fr.rcPage.top ;//+ 1440;
	  fr.rc.right  = fr.rcPage.right ;//- 1440;
	  fr.rc.bottom = fr.rcPage.bottom ;//- 1440;

	 // Default the range of text to print as the entire document.
	  fr.chrg.cpMin = 0;
	  fr.chrg.cpMax = -1;
      FormatRange(&fr,TRUE);      
	 // Set up the print job (standard printing stuff here).
		DOCINFO di;
	  ZeroMemory(&di, sizeof(di));
	  di.cbSize = sizeof(DOCINFO);

	  di.lpszDocName = "MyRtf";

	    // Do not print to file.
	     di.lpszOutput = NULL;
	     

	 // Start the document.
	  StartDoc(hPrinterDC, &di);

	 // Find out real size of document in characters.
	  lTextLength = GetTextLength();//SendMessage ( /*hRTFWnd,*/ WM_GETTEXTLENGTH, 0, 0 );
	
	 do
	     {
	     // Start the page.
	     StartPage(hPrinterDC);

	    // Print as much text as can fit on a page. The return value is
	     // the index of the first character on the next page. Using TRUE
	     // for the wParam parameter causes the text to be printed.

	    lTextPrinted =FormatRange(&fr,TRUE);
		
		DisplayBand(&fr.rc );
	    
	    // Print last page.
	     EndPage(hPrinterDC);

	    // If there is more text to print, adjust the range of characters
	     // to start printing at the first character of the next page.
		if (lTextPrinted < lTextLength)
		{
		fr.chrg.cpMin = lTextPrinted;
		fr.chrg.cpMax = -1;
		}
	     }
	  while (lTextPrinted < lTextLength);

	 // Tell the control to release cached information.
	  FormatRange(NULL,FALSE);
		  //SendMessage( EM_FORMATRANGE, 0, (LPARAM)NULL);

	 EndDoc (hPrinterDC);

	  ///////
	  
	DeleteDC(hPrinterDC);

}

void CCustomRichEditCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu mnu;
	ClientToScreen(&point);	
	mnu.LoadMenu(IDR_MENU2);
	mnu.GetSubMenu(0)->TrackPopupMenu(TPM_CENTERALIGN,point.x,point.y,
		AfxGetMainWnd());  
	CRichEditCtrl::OnRButtonDown(nFlags, point);
}



void CCustomRichEditCtrl::SetColor(COLORREF clr)
{
	if (cf.dwEffects & CFE_AUTOCOLOR) 
		cf.dwEffects -= CFE_AUTOCOLOR;
	
		cf.crTextColor = clr;

		cf.dwMask = CFM_COLOR;	

	SetSelectionCharFormat(cf);
}

BOOL CCustomRichEditCtrl::SelectionIsBold()
{
	 GetSelectionCharFormat(cf);	
	
	if (cf.dwEffects & CFM_BOLD)
		return TRUE;
	else
		return FALSE;
}

BOOL CCustomRichEditCtrl::SelectionIsItalic()
{
	 GetSelectionCharFormat(cf);	
	
	if (cf.dwEffects & CFM_ITALIC)
		return TRUE;
	else
		return FALSE;
}

BOOL CCustomRichEditCtrl::SelectionIsUnderlined()
{
	GetSelectionCharFormat(cf);	
	
	if (cf.dwEffects & CFM_UNDERLINE)
		return TRUE;
	else
		return FALSE;
}
BOOL CCustomRichEditCtrl::ParagraphIsCentered()
{
	 GetParaFormat(pf);

	if (pf.wAlignment == PFA_CENTER)
		return TRUE;
	else
		return FALSE;
}

BOOL CCustomRichEditCtrl::ParagraphIsLeft()
{
	GetParaFormat(pf);

	if (pf.wAlignment == PFA_LEFT)
		return TRUE;
	else
		return FALSE;
}

BOOL CCustomRichEditCtrl::ParagraphIsRight()
{
	GetParaFormat(pf);

	if (pf.wAlignment == PFA_RIGHT)
		return TRUE;
	else
		return FALSE;
}
BOOL CCustomRichEditCtrl::ParagraphIsBulleted()
{
	GetParaFormat(pf);

	if (pf.wNumbering == PFN_BULLET)
		return TRUE;
	else
		return FALSE;
}


