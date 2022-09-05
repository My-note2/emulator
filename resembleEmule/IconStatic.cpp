// IconStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "resembleEmule.h"
#include "IconStatic.h"


// CIconStatic

IMPLEMENT_DYNAMIC(CIconStatic, CStatic)

CIconStatic::CIconStatic()
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CIconStatic::~CIconStatic()
{
	m_MemBMP.DeleteObject();
}


BEGIN_MESSAGE_MAP(CIconStatic, CStatic)
	//ON_WM_SYSCOLORCHANGE()
END_MESSAGE_MAP()



// CIconStatic 消息处理程序
void CIconStatic::SetWindowText(LPCTSTR pszString)
{
	m_strText = pszString;
	SetIcon(m_strIconID);
}

void CIconStatic::SetIcon(LPCTSTR pszIconID)
{
	m_strIconID = pszIconID;

	CString strText;
	CStatic::GetWindowText(strText);
	CStatic::SetWindowText(_T(""));
	if (!strText.IsEmpty() && m_strText.IsEmpty())
		m_strText = strText;

	CRect rRect;
	GetClientRect(rRect);

	CDC* pDC = GetDC();
	CDC  MemDC;
	CBitmap* pOldBMP;

	VERIFY(MemDC.CreateCompatibleDC(pDC));

	CFont* pOldFont = MemDC.SelectObject(GetFont());

	CRect rCapture(0, 0, 0, 0);
	MemDC.DrawText(m_strText, rCapture, DT_CALCRECT);
	ASSERT(rCapture.Width() >= 0);
	ASSERT(rCapture.Height() >= 0);
	if (rCapture.Height() < 16)
		rCapture.bottom = rCapture.top + 16;
	rCapture.right += 25;
	if (rCapture.Width() >= 16 && rCapture.Width() > rCapture.Width() - 16)
		rCapture.right = rCapture.left + rRect.Width() - 16;

	if (m_MemBMP.m_hObject)
		VERIFY(m_MemBMP.DeleteObject());
	VERIFY(m_MemBMP.CreateCompatibleBitmap(pDC, rCapture.Width(), rCapture.Height()));
	pOldBMP = MemDC.SelectObject(&m_MemBMP);

	MemDC.FillSolidRect(rCapture, GetSysColor(COLOR_BTNFACE));

	if (!m_strIconID.IsEmpty())
		VERIFY(DrawState(MemDC.m_hDC, NULL, NULL, (LPARAM)(HICON)CTempIconLoader(m_strIconID, 16, 16), NULL, 3, 0, 16, 16, DST_ICON | DSS_NORMAL));
}
