#pragma once


// CReviewListWnd �Ի���
#include "BkDialogST.h"
#include "BtnST.h"
class CReviewListWnd : public CBkDialogST
{
	//DECLARE_DYNAMIC(CReviewListWnd)

public:
	CReviewListWnd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReviewListWnd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REVIEWLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnReturnHome();

	CButtonST m_btnHome;
	virtual BOOL OnInitDialog();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
