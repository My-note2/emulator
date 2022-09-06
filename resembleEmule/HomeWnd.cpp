// HomeWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "resembleEmule.h"
#include "HomeWnd.h"
#include "afxdialogex.h"


// CHomeWnd 对话框

//IMPLEMENT_DYNAMIC(CHomeWnd, CBkDialogST)

CHomeWnd::CHomeWnd(CWnd* pParent /*=NULL*/)
	: CBkDialogST(IDD_HOME, pParent)
{

}

CHomeWnd::~CHomeWnd()
{
}

void CHomeWnd::DoDataExchange(CDataExchange* pDX)
{
	CBkDialogST::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_menu);
	DDX_Control(pDX, IDC_STT_TIME, m_sttime);
}


BEGIN_MESSAGE_MAP(CHomeWnd, CBkDialogST)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, &CHomeWnd::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHomeWnd 消息处理程序


BOOL CHomeWnd::OnInitDialog()
{
	CBkDialogST::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetBitmap(IDB_HOME);

	//m_btn_menu.SetIcon(IDI_MENU);
	//m_btn_menu.DrawBorder(FALSE);
	m_btn_menu.SetBitmaps(IDB_MENU, RGB(0, 255, 0));
	m_btn_menu.DrawTransparent();

	m_sttime.SetFont(GetFont());
	m_sttime.SetWindowText(_T("A/B/C"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CHomeWnd::OnSize(UINT nType, int cx, int cy)
{
	CBkDialogST::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	MoveWindow(0, 0, cx, cy);
}


void CHomeWnd::OnBnClickedButton1()
{
	//通过mainfram调用menu界面
	AfxGetMainWnd()->SendMessage(WM_WINDOW_CHANGES, (WPARAM)0, NULL);
}
