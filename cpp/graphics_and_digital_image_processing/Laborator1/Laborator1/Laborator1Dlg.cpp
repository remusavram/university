// Laborator1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Laborator1.h"
#include "Laborator1Dlg.h"

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


// CLaborator1Dlg dialog




CLaborator1Dlg::CLaborator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborator1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLaborator1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CLaborator1Dlg message handlers

BOOL CLaborator1Dlg::OnInitDialog()
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

void CLaborator1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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



void CLaborator1Dlg::OnPaint()
{
		CBrush *br;

		
	
		CPaintDC dc(this); // device context for painting
		dc.Rectangle(200,290,440,470);
		dc.Rectangle(290,370,350,470);
		dc.Rectangle(220,370,260,410);
		dc.Rectangle(380,370,420,410);
		
		CPoint*triunghi=new CPoint[3];
		triunghi[0].x=180;
		triunghi[0].y=290;
		triunghi[1].x=320;
		triunghi[1].y=130;
		triunghi[2].x=460;
		triunghi[2].y=290;
		dc.Polygon(triunghi,3);

		dc.Ellipse(1100,20,1200,120);

//corp casa
		br=new CBrush(RGB(247,238,128));
		dc.SelectObject(br);
		dc.Rectangle(200,290,440,470);
		delete br;

//usa
		br=new CBrush(RGB(100,100,50));
		dc.SelectObject(br);
		dc.Rectangle(290,370,350,470);
		delete br;

//geam
		br=new CBrush(RGB(70,200,200));
		dc.SelectObject(br);
		dc.Rectangle(220,370,260,410);
		delete br;

//geam2
		br=new CBrush(RGB(70,200,200));
		dc.SelectObject(br);
		dc.Rectangle(380,370,420,410);
		delete br;

//acoperis
		br=new CBrush(RGB(100,100,50));
		dc.SelectObject(br);
		dc.Polygon(triunghi,3);
		delete br;

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaborator1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

