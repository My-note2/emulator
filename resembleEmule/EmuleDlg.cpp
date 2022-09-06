
// EmuleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "resembleEmule.h"
#include "EmuleDlg.h"
#include "afxdialogex.h"

#include "HomeWnd.h"
#include "ReviewListWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEmuleDlg 对话框



CEmuleDlg::CEmuleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RESEMBLEEMULE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_homewnd = new CHomeWnd();
	m_reviewlistwnd = new CReviewListWnd();
}

CEmuleDlg::~CEmuleDlg()
{
	delete m_homewnd;
	delete m_reviewlistwnd;
}
void CEmuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYINFO, m_ctrlMyInfoFrm);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_set);
}

BEGIN_MESSAGE_MAP(CEmuleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()

	ON_MESSAGE(WM_WINDOW_CHANGES, OnChangeWindow)
END_MESSAGE_MAP()


// CEmuleDlg 消息处理程序

BOOL CEmuleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//CBitmap bmp;
	//BITMAP bitmap;
	//bmp.LoadBitmap(IDB_HOME);
	//bmp.GetBitmap(&bitmap);
	//MoveWindow(0, 0, bitmap.bmWidth, bitmap.bmHeight);
	//SetBackgroundImage(IDB_HOME);
	//m_ctrlMyInfoFrm.SetIcon(_T("INFO"));
	//SetBitmap(IDB_HOME);

	m_homewnd->Create(IDD_HOME);
	m_reviewlistwnd->Create(IDD_REVIEWLIST);
	//SetActiveDialog(m_home);
	m_homewnd->SetParent(this);
	m_homewnd->ShowWindow(SW_SHOW);
	m_homewnd->UpdateWindow();
	m_ctrlMyInfoFrm.DrawTransparent();
	m_btn_set.DrawTransparent();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEmuleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEmuleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEmuleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEmuleDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_homewnd->m_hWnd)
		m_homewnd->MoveWindow(0, 0, cx, cy);
	if (m_reviewlistwnd->m_hWnd)
		m_reviewlistwnd->MoveWindow(0, 0, cx, cy);
}

LRESULT CEmuleDlg::OnChangeWindow(WPARAM wParam, LPARAM lParam)
{
	int nWnd = (int)wParam;
	if (nWnd == 1)
	{
		m_reviewlistwnd->ShowWindow(SW_HIDE);
		m_homewnd->ShowWindow(SW_SHOW);
		m_homewnd->UpdateData();
	}
	else
	{
		m_homewnd->ShowWindow(SW_HIDE);
		m_reviewlistwnd->ShowWindow(SW_SHOW);
		m_reviewlistwnd->UpdateData();
	}

	return TRUE;
}