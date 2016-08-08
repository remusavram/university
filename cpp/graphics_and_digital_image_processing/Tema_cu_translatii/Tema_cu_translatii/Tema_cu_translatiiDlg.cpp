// Tema_cu_translatiiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tema_cu_translatii.h"
#include "Tema_cu_translatiiDlg.h"
#include <math.h>

#define PI  3.14159265
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


// CTema_cu_translatiiDlg dialog




CTema_cu_translatiiDlg::CTema_cu_translatiiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTema_cu_translatiiDlg::IDD, pParent)
	, puncte(NULL)
	, nrpuncte(0)
	, press(false)
	, nrpunctevechi(0)
	, pressreset(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTema_cu_translatiiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTema_cu_translatiiDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CTema_cu_translatiiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTema_cu_translatiiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTema_cu_translatiiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTema_cu_translatiiDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CTema_cu_translatiiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CTema_cu_translatiiDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTema_cu_translatiiDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTema_cu_translatiiDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CTema_cu_translatiiDlg message handlers

BOOL CTema_cu_translatiiDlg::OnInitDialog()
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

    nrpuncte=0;
	puncte = new CPoint[20];
	press=false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTema_cu_translatiiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTema_cu_translatiiDlg::OnPaint()
{
	
		CPaintDC dc(this); // device context for painting
		CBrush *br1;
		if(pressreset)
		{
			br1=new CBrush(RGB(128,64,0));
            dc.Polygon(puncte,nrpunctevechi);
			DeleteObject(br1);
		}

		if(nrpuncte>0)
		{
		for(int i=0;i<nrpuncte;i++)
		{
			dc.Ellipse(puncte[i].x-2,puncte[i].y-2,puncte[i].x+2,puncte[i].y+2);
		}
		}
		if(press){dc.Polygon(puncte,nrpuncte);}

		
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTema_cu_translatiiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTema_cu_translatiiDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if(nrpuncte<20 && press==false)
	{
      puncte[nrpuncte]=point;
	  nrpuncte++;
	  Invalidate();
	}

	CDialog::OnMButtonDown(nFlags, point);
}

void CTema_cu_translatiiDlg::OnBnClickedButton1()
{
	press=TRUE;
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTema_cu_translatiiDlg::OnBnClickedButton3()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(-dx,0);
	Invalidate();

}

void CTema_cu_translatiiDlg::OnBnClickedButton4()
{
    nrpunctevechi=nrpuncte;
	nrpuncte=0;
	press=false;
	pressreset=true;
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTema_cu_translatiiDlg::OnBnClickedButton5()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(0,dx);
	Invalidate();
}

void CTema_cu_translatiiDlg::OnBnClickedButton2()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(0,-dx);
	Invalidate();
}

void CTema_cu_translatiiDlg::OnBnClickedButton6()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(dx,0);
	Invalidate();
}

void CTema_cu_translatiiDlg::Translatie(int dx, int dy)
{
	for(int i=0;i<nrpuncte;i++)
	{
		puncte[i].x+=dx;
		puncte[i].y+=dy;
	}
}

void CTema_cu_translatiiDlg::Rotatie(int unghi)
{
	for(int i=0;i<nrpuncte;i++)
	{
		int x=(int)(cos(unghi*PI/180)*puncte[i].x-sin(unghi*PI/180)*puncte[i].y+0.5);
		int y=(int)(sin(unghi*PI/180)*puncte[i].x+cos(unghi*PI/180)*puncte[i].y+0.5);
		puncte[i].x=x;
		puncte[i].y=y;
	}
}

void CTema_cu_translatiiDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	int cx=0,cy=0;
	for(int i=0; i<nrpuncte;i++)
	{
		cx+=puncte[i].x;
		cy+=puncte[i].y;
	}
	cx=cx/nrpuncte;
	cy=cy/nrpuncte;
	Translatie(-cx,-cy);
	Rotatie(GetDlgItemInt(IDC_Rotatie));
	Translatie(cx,cy);
	Invalidate();

}

void CTema_cu_translatiiDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	double ax, ay;
	CString s;
	GetDlgItemText(IDC_AX,s);
	ax=atof(s);
}
