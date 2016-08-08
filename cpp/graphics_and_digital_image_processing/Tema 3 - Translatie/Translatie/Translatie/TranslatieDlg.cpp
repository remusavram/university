// TranslatieDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Translatie.h"
#include "TranslatieDlg.h"
#include <math.h>
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


// CTranslatieDlg dialog




CTranslatieDlg::CTranslatieDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTranslatieDlg::IDD, pParent)
	, nr_puncte(0)
	, puncte(0)
	, presetpoly(false)
	, pcreatepoly(false)
	, punctevechi(0)
	, cg(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTranslatieDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTranslatieDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON5, &CTranslatieDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CTranslatieDlg::OnBnClickedButton1)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON2, &CTranslatieDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_BUTTON5, &CTranslatieDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON10, &CTranslatieDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON3, &CTranslatieDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTranslatieDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CTranslatieDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTranslatieDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CTranslatieDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON8, &CTranslatieDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CTranslatieDlg message handlers

BOOL CTranslatieDlg::OnInitDialog()
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
	nr_puncte=0;
	puncte=new CPoint[20];
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTranslatieDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTranslatieDlg::OnPaint()
{
		CPaintDC dc(this); // device context for painting
		if(nr_puncte>1)
        {
            for(int i=0;i<nr_puncte;i++)
                dc.Ellipse(puncte[i].x-2,puncte[i].y-2,puncte[i].x+2,puncte[i].y+2);
            if(pcreatepoly)
            {
                dc.Polygon(puncte,nr_puncte);
			}
		}
	}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTranslatieDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTranslatieDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
    if (nr_puncte<20 && pcreatepoly==false) 
	{
		puncte[nr_puncte++]=point;
		Invalidate();
		cg.x=0;
		cg.y=0;
		for (int i=0; i<nr_puncte; i++)
		{
			cg.x+=puncte[i].x;
			cg.y+=puncte[i].y;
		}
		cg.x/=nr_puncte;
		cg.y/=nr_puncte;
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CTranslatieDlg::OnBnClickedButton5()
{
	punctevechi=nr_puncte;
	nr_puncte=0;
	pcreatepoly=false;
	presetpoly=true;
	Invalidate();
	
	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::OnBnClickedButton1()
{
    int dy=GetDlgItemInt(IDC_TRANS);
	Translatie(0,-dy);
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnLButtonUp(nFlags, point);
}

void CTranslatieDlg::OnBnClickedButton2()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(-dx,0);
	Invalidate();


	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CTranslatieDlg::OnBnClickedButton10()
{
	pcreatepoly=TRUE;
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::OnBnClickedButton3()
{
	int dx=GetDlgItemInt(IDC_TRANS);
	Translatie(dx,0);
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::OnBnClickedButton4()
{
	int dy=GetDlgItemInt(IDC_TRANS);
	Translatie(0,dy);
	Invalidate();
	// TODO: Add your control notification handler code here
}

void CTranslatieDlg::Translatie(int dx, int dy)
{
	for(int i=0;i<nr_puncte;i++)
	{
		puncte[i].x+=dx;	
		puncte[i].y+=dy;
	}
}

void CTranslatieDlg::Rotatie(int unghi)
{
	int x,y;
	for(int i=0;i<nr_puncte;i++)
	{
		x=(int)(puncte[i].x*cos(unghi*PI/180)-puncte[i].y*sin(unghi*PI/180)+0.5);
		y=(int)(puncte[i].x*sin(unghi*PI/180)+puncte[i].y*cos(unghi*PI/180)+0.5);
		puncte[i].x=x;
		puncte[i].y=y;
	}
}

void CTranslatieDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	
	int u=GetDlgItemInt(IDC_UNGHI);
	Rotatie(u);
	Invalidate();
}

void CTranslatieDlg::OnBnClickedButton7()
{
int v=GetDlgItemInt(IDC_UNGHI2);
int px=GetDlgItemInt(IDC_PUNCTX);
int py=GetDlgItemInt(IDC_PUNCTY);
Translatie(-px,-py);
Rotatie(v);
Translatie(px,py);
	Invalidate();
}



void CTranslatieDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	int v=GetDlgItemInt(IDC_UNGHI3);
	
	Translatie(-cg.x,-cg.y);
	Rotatie(v);
	Translatie(cg.x,cg.y);
	Invalidate();
}

void CTranslatieDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CString s;
	GetDlgItemTextA(IDC_SX,s);
	double sx=atof(s);

	GetDlgItemTextA(IDC_SY,s);
	double sy=atof(s);
		
	Translatie(-cg.x,-cg.y);
	Scalare(sx,sy);
	Translatie(cg.x,cg.y);
	Invalidate();


}

void CTranslatieDlg::Scalare(double sx, double sy)
{
	for(int i=0;i<nr_puncte;i++)
	{
		puncte[i].x=(int)(puncte[i].x*sx+0.5);	
		puncte[i].y=(int)(puncte[i].y*sy+0.5);	
	}
}
