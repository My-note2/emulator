
// resembleEmule.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#include "UIMsg.h"
// EmuleApp: 
// 有关此类的实现，请参阅 resembleEmule.cpp
//

class EmuleApp : public CWinApp
{
public:
	EmuleApp();


	//HICON		LoadIcon(LPCTSTR lpszResourceName, int cx = 16, int cy = 16, UINT uFlags = LR_DEFAULTCOLOR) const;
	HICON		LoadIcon(UINT nIDResource) const;
// 重写
public:
	virtual BOOL InitInstance();

// 实现

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