// NewToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "..\CommonCtrls.h"
#include "NewToolBar.h"
#include <afxpriv.h>// for WM_IDLEUPDATECMDUI
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewToolBar

CNewToolBar::CNewToolBar()
{
}

CNewToolBar::~CNewToolBar()
{
}


BEGIN_MESSAGE_MAP(CNewToolBar, CToolBar)
	//{{AFX_MSG_MAP(CNewToolBar)
	ON_MESSAGE(WM_KICKIDLE,OnKickIdle)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewToolBar message handlers


LRESULT CNewToolBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM)
{
	if (IsWindowVisible())
	{
		CFrameWnd *pParent = (CFrameWnd *)GetParent();
		if (pParent)
			OnUpdateCmdUI(pParent, (BOOL)wParam);
	}
	return 0L;
}


LRESULT CNewToolBar::OnKickIdle(WPARAM w, LPARAM l)
{
	AfxGetApp()->OnIdle(-1);
	OnIdleUpdateCmdUI(w,l);
	return 0L;
}
