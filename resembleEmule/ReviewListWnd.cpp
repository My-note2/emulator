// ReviewListWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "resembleEmule.h"
#include "ReviewListWnd.h"
#include "afxdialogex.h"


// CReviewListWnd 对话框

//IMPLEMENT_DYNAMIC(CReviewListWnd, CDialog)

CReviewListWnd::CReviewListWnd(CWnd* pParent /*=NULL*/)
	: CBkDialogST(IDD_REVIEWLIST, pParent)
{

}

CReviewListWnd::~CReviewListWnd()
{
}

void CReviewListWnd::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReviewListWnd, CBkDialogST)
	ON_WM_SIZE()
	ON_BN_CLICKED(5000, OnReturnHome)
END_MESSAGE_MAP()


// CReviewListWnd 消息处理程序


void CReviewListWnd::OnSize(UINT nType, int cx, int cy)
{
	CBkDialogST::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	MoveWindow(0, 0, cx, cy);
}


BOOL CReviewListWnd::OnInitDialog()
{
	CBkDialogST::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_btnHome.Create(_T(""), WS_CHILD | WS_VISIBLE, CRect(100, 100, 140, 140), this, 5000);
	m_btnHome.SetBitmaps(IDB_MENU, RGB(0, 255, 0));
	m_btnHome.DrawTransparent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


LRESULT CReviewListWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CBkDialogST::WindowProc(message, wParam, lParam);
}

 void CReviewListWnd::OnReturnHome()
{
	AfxGetMainWnd()->SendMessage(WM_WINDOW_CHANGES, (WPARAM)1, NULL);
}