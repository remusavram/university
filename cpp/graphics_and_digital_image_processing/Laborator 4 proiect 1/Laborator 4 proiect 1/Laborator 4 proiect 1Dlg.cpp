// Laborator 4 proiect 1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Laborator 4 proiect 1.h"
#include "Laborator 4 proiect 1Dlg.h"
#include <math.h>

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


// CLaborator4proiect1Dlg dialog




CLaborator4proiect1Dlg::CLaborator4proiect1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborator4proiect1Dlg::IDD, pParent)
	, nrpuncte(0)
	, puncte(NULL)
	, press(false)
	, pressreset(false)
	, nrpunctevechi(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator4proiect1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLaborator4proiect1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CLaborator4proiect1Dlg::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CLaborator4proiect1Dlg message handlers

BOOL CLaborator4proiect1Dlg::OnInitDialog()
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
	puncte=new CPoint[20];
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLaborator4proiect1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLaborator4proiect1Dlg::OnPaint()
{

		CPaintDC dc(this); // device context for painting
		CBrush *br1;
		double L[20];
		if(pressreset)
		{
			br1=new CBrush(RGB(128,64,0));
            dc.Polygon(puncte,nrpunctevechi);
			DeleteObject(br1);
		}

		if(nrpuncte>0)
		{
			for(int i=0;i<nrpuncte;i++)
				dc.Ellipse(puncte[i].x-2,puncte[i].y-2,puncte[i].x+2,puncte[i].y+2);
			dc.MoveTo(puncte[0].x,puncte[0].y);
			for(int j=0;j<nrpuncte;j++)
			{
				L[j]=1;
				for(int k=0;k<nrpuncte;k++)
					if(k!=j)
						L[j]=L[j]*(puncte[j].x-puncte[k].x);
			}

		
		for(int x=puncte[0].x;x<=puncte[nrpuncte-1].x;x++)
		{
			double y=0;
			for(int i=0;i<nrpuncte;i++)
			{
				double l=1;
				for(int k=0;k<nrpuncte;k++)
					if(k!=i)
						l=l*(x-puncte[k].x);
			
			y=y+puncte[i].y*l/L[i];
			}
			dc.LineTo(x,(int)(y+0.5));
		}
		//dc.LineTo(puncte[nrpuncte-1].x,puncte[nrpuncte-1].y);
		}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaborator4proiect1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLaborator4proiect1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if(nrpuncte<20 && press==false)
	{
    if(point.x>puncte[nrpuncte-1].x)
	{puncte[nrpuncte]=point;
	  nrpuncte++;
	  Invalidate();
	}
	}
	CDialog::OnLButtonDown(nFlags, point);
}


void CLaborator4proiect1Dlg::OnBnClickedButton1()
{
	press=TRUE;
	Invalidate();
	// TODO: Add your control notification handler code here
}


