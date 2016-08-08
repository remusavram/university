// Laborator2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Laborator2.h"
#include "Laborator2Dlg.h"
#include <fstream>
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace std;

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


// CLaborator2Dlg dialog




CLaborator2Dlg::CLaborator2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaborator2Dlg::IDD, pParent)
	, vect(0)
	, nrvar(0)
	, maxim(0)
	, culori(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaborator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLaborator2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CLaborator2Dlg message handlers

BOOL CLaborator2Dlg::OnInitDialog()
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
	input.open("datevect.txt");	
	input>>nrvar;
	vect=new int[nrvar];
	srand(time(NULL));
	culori = new COLORREF[nrvar];
	for(int i=0;i<nrvar;i++)
	{
		input>>vect[i];
		culori[i]=RGB(rand()%256,rand()%256,rand()%256);
	}
	input.close();
	maxim=vect[0];
	for(int i=0;i<nrvar;i++)
	if(maxim<vect[i]) maxim=vect[i];
	/*CString sir;
	sir.Format("nr max=%d",maxim);
	MessageBoxA(sir,NULL,NULL);*/


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLaborator2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLaborator2Dlg::OnPaint()
{
	
		CPaintDC dc(this); // device context for painting
        CRect rect;
		GetClientRect(&rect);
		int y1=10;
        int x1=10;
		int y2=rect.Height()-10;
		int x2=rect.Width()-10;
		dc.Rectangle(x1,y1,x2,y2);
		int space=(rect.Width()-20)/(3*nrvar);
		int xb1=space,yb1,xb2;
		CBrush *br1;

		
		for(int i=0;i<nrvar;i++)
		{
			br1=new CBrush(culori[i]);
			int hbara=(rect.Height()-30)*vect[i]/maxim;
		yb1=y2-hbara;
		xb2=xb1+2*space;
		dc.SelectObject(br1);
		dc.Rectangle(xb1,yb1,xb2,y2);
		DeleteObject(br1);
		xb1=xb1+3*space;
		}


}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaborator2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

