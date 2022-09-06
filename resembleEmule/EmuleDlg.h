
// EmuleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "IconStatic.h"
#include "BtnST.h"
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
// CEmuleDlg �Ի���
class CHomeWnd;
class CReviewListWnd;
class CEmuleDlg : public CDialogEx
{
// ����
public:
	CEmuleDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CEmuleDlg();
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
	afx_msg LRESULT OnChangeWindow(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:

	CButtonST m_ctrlMyInfoFrm;

	CButtonST m_btn_set;

private:
	CHomeWnd* m_homewnd;
	CReviewListWnd* m_reviewlistwnd;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
