
// EmuleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "IconStatic.h"
// CEmuleDlg 对话框
class CEmuleDlg : public CDialogEx
{
// 构造
public:
	CEmuleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESEMBLEEMULE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CIconStatic m_ctrlMyInfoFrm;
};
