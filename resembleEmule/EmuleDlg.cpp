
// EmuleDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CEmuleDlg �Ի���



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


// CEmuleDlg ��Ϣ�������

BOOL CEmuleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEmuleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CEmuleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEmuleDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
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