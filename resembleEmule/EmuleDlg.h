
// EmuleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "BkDialogST.h"
#include "IconStatic.h"
#include "./Button/BtnST.h"
// CEmuleDlg �Ի���
class CEmuleDlg : public CBkDialogST
{
// ����
public:
	CEmuleDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESEMBLEEMULE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CButtonST m_ctrlMyInfoFrm;

	CButtonST m_btn_set;
};
