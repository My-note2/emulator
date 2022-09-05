#pragma once


// CIconStatic

class CIconStatic : public CStatic
{
	DECLARE_DYNAMIC(CIconStatic)

public:
	CIconStatic();
	virtual ~CIconStatic();

//Operations
	void SetIcon(LPCTSTR pszIconID);
	void CIconStatic::SetWindowText(LPCTSTR pszString);
protected:
	CString m_strIconID;
	CString m_strText;
	CBitmap m_MemBMP;

	DECLARE_MESSAGE_MAP()
};


