
// resembleEmule.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "UIMsg.h"
// EmuleApp: 
// �йش����ʵ�֣������ resembleEmule.cpp
//

class EmuleApp : public CWinApp
{
public:
	EmuleApp();


	//HICON		LoadIcon(LPCTSTR lpszResourceName, int cx = 16, int cy = 16, UINT uFlags = LR_DEFAULTCOLOR) const;
	HICON		LoadIcon(UINT nIDResource) const;
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern EmuleApp theApp;

class CTempIconLoader {
public:
	CTempIconLoader(LPCTSTR pszResourceID, int cx=16, int cy=16, UINT uFlags = LR_DEFAULTCOLOR);
	CTempIconLoader(UINT uResourceID, int cx=16, int cy=16, UINT uFlags = LR_DEFAULTCOLOR);
	~CTempIconLoader();

	operator HICON() const {
		return this == NULL ? NULL : m_hIcon;
	}

protected:
	HICON m_hIcon;
};