// Laborator 3 project 6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Laborator 3 project 6.h"
#include "Laborator 3 project 6Dlg.h"
#include <math.h>
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14159265
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


// CLaborator3project6Dlg dialog




CLaborator3project6Dlg::CLaborator3project6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborator3project6Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator3project6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLaborator3project6Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CLaborator3project6Dlg message handlers

BOOL CLaborator3project6Dlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLaborator3project6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLaborator3project6Dlg::OnPaint()
{
	
		CPaintDC dc(this); // device context for painting

		CRect rect;

		GetClientRect(&rect);
		CPoint center(rect.Width()/2,rect.Height()/2);
		CPen *oldPen, *pen1;
		//creez penita rosie pentru desenarea curbei
		pen1=new CPen(PS_SOLID,1,RGB(255,0,0));
		//desenare axe de coordonate
		dc.MoveTo(20,center.y);
		dc.LineTo(rect.Width()-20,center.y);
		dc.MoveTo(center.x,20);
		dc.LineTo(center.x,rect.Height()-20);
		//desenare cerc
		//selectez penita pentru desenare
		oldPen=(CPen*)dc.SelectObject(pen1);
		int raza=0;
	
		dc.MoveTo(center.x,center.y);
		for(double i=0;i<=100*PI;i+=PI/180)
		{
			int x=(int)(rect.Height()/10*sin(i)*(exp(cos(i))-2*cos(4*(i))-pow(sin(i/12),5))+0.5);
			int y=(int)(rect.Height()/10*cos(i)*(exp(cos(i))-2*cos(4*(i))-pow(sin(i/12),5))+0.5);
			dc.LineTo(center.x+x,center.y-y);
		}
		//selectez penita initiala
		dc.SelectObject(oldPen);
		//eliberez memoria pentru penita creata mai sus
		delete pen1;
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaborator3project6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

