#pragma once


// CHomeWnd �Ի���
#include "BkDialogST.h"
#include "afxwin.h"
#include "BtnST.h"
#include "StaticTrans.h"
class CHomeWnd : public CBkDialogST
{
	//DECLARE_DYNAMIC(CHomeWnd)

public:
	CHomeWnd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHomeWnd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButtonST m_btn_menu;
	CStaticTrans m_sttime;
	afx_msg void OnBnClickedButton1();
};
