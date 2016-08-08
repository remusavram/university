// Laborator 1 tema 2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Laborator 1 tema 2.h"
#include "Laborator 1 tema 2Dlg.h"
#include <fstream>
#include<ctime>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLaborator1tema2Dlg dialog




CLaborator1tema2Dlg::CLaborator1tema2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborator1tema2Dlg::IDD, pParent)
	, date(NULL)
	, nr_date(0)
	, maxim(0)
	, culori(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator1tema2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLaborator1tema2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CLaborator1tema2Dlg message handlers

BOOL CLaborator1tema2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	ifstream input;
	input.open("date.txt");
	
	input>>nr_date;
	/*
	CString sir;
	sir.Format("nr_date=%d", nr_date);
	MessageBoxA(sir,NULL,NULL);
	*/

	date= new int[nr_date];
	srand(time(NULL));
	culori=new COLORREF[nr_date];
	for (int i=0;i<nr_date;i++)
	{
		input>>date[i];
		culori[i]=RGB(rand()%256,rand()%256,rand()%256);
	}
	maxim=date[0];

		for (int i=1;i<nr_date;i++)
			if(maxim<date[i])
				maxim=date[i];

	

	

	input.close();
	return TRUE;  // return TRUE  unless you set the focus to a control
}	


void CLaborator1tema2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLaborator1tema2Dlg::OnPaint()
{
		CBrush *br;

		CPaintDC dc(this); // device context for painting
		CRect rect;
		GetClientRect(&rect);
		int H=rect.Height();
		int W=rect.Width();
		
	/*	CString sir;
		sir.Format("nr_date=%d", rect.Height());
		MessageBoxA(sir,NULL,NULL);*/
		
		dc.Rectangle(10,10,W-10,H-10);

		ifstream input;
		input.open("date.txt");
		input>>nr_date;






		int v=2*(W-20)/(nr_date*3);

		int proportia=H/maxim;
		int x1[100],x2[100],y1[100],y2[100];
		

		for(int i=0;i<nr_date;i++)
		{
			x1[i]=i*v+(i+1)*v/2;
			y1[i]=H-date[i]*proportia;
			x2[i]=x1[i]+v;
			y2[i]=H-10;
			dc.Rectangle(x1[i],y1[i],x2[i],y2[i]);
			br=new CBrush(culori[i]);
			dc.SelectObject(br);
			dc.Rectangle(x1[i],y1[i],x2[i],y2[i]);
			DeleteObject(br);
		}



}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaborator1tema2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

