#pragma once


// CReviewListWnd 对话框
#include "BkDialogST.h"
#include "BtnST.h"
class CReviewListWnd : public CBkDialogST
{
	//DECLARE_DYNAMIC(CReviewListWnd)

public:
	CReviewListWnd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CReviewListWnd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REVIEWLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnReturnHome();

	CButtonST m_btnHome;
	virtual BOOL OnInitDialog();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
