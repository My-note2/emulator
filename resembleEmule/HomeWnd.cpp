// HomeWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resembleEmule.h"
#include "HomeWnd.h"
#include "afxdialogex.h"


// CHomeWnd �Ի���

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


// CHomeWnd ��Ϣ�������


BOOL CHomeWnd::OnInitDialog()
{
	CBkDialogST::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetBitmap(IDB_HOME);

	//m_btn_menu.SetIcon(IDI_MENU);
	//m_btn_menu.DrawBorder(FALSE);
	m_btn_menu.SetBitmaps(IDB_MENU, RGB(0, 255, 0));
	m_btn_menu.DrawTransparent();

	m_sttime.SetFont(GetFont());
	m_sttime.SetWindowText(_T("A/B/C"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CHomeWnd::OnSize(UINT nType, int cx, int cy)
{
	CBkDialogST::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	MoveWindow(0, 0, cx, cy);
}


void CHomeWnd::OnBnClickedButton1()
{
	//ͨ��mainfram����menu����
	AfxGetMainWnd()->SendMessage(WM_WINDOW_CHANGES, (WPARAM)0, NULL);
}
