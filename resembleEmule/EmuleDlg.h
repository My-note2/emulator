
// EmuleDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "IconStatic.h"
#include "BtnST.h"
//#include "nlohmann/json.hpp"
//using json = nlohmann::json;
// CEmuleDlg 对话框
class CHomeWnd;
class CReviewListWnd;
class CEmuleDlg : public CDialogEx
{
// 构造
public:
	CEmuleDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CEmuleDlg();
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
