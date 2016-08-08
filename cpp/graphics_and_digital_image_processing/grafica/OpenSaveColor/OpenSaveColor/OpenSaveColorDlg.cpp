// OpenSaveColorDlg.cpp : implementation file
//

#include "stdafx.h"

#include "OpenSaveColor.h"
#include "OpenSaveColorDlg.h"
#include "OpenSave.h"
#include "MyImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

MyImage *mainImage,*prelImage;

COpenSaveColorDlg::COpenSaveColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenSaveColorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenSaveColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenSaveColorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_OPEN, &COpenSaveColorDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &COpenSaveColorDlg::OnBnClickedSave)
	ON_WM_CLOSE()
	ON_COMMAND(ID_FISIER_OPEN, &COpenSaveColorDlg::OnFisierOpen)
END_MESSAGE_MAP()

BOOL COpenSaveColorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	prelImage=new MyImage();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COpenSaveColorDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	AfisareImagine();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COpenSaveColorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenSaveColorDlg::OnBnClickedOpen()
{
	static TCHAR szFileName[MAX_PATH],szTitleName[MAX_PATH];

	static BITMAPFILEHEADER *pbmfh=NULL;
	static BITMAPINFOHEADER pbmih;
	static BITMAPINFO *pbmi;
	static BYTE *pBits;
	static int nrBytesPerPixel=3;
	static int im_width, im_height;

	if(DibFileOpenDlg(NULL,(PSTR)szFileName,(PSTR)szTitleName)) 
	{
		//daca exista deja un DIB, se elibereaza

		pbmfh=DibLoadImage((PSTR)szFileName);
		if(pbmfh==NULL)
		{	
			MessageBoxA(TEXT("2 Eroare de citire "),NULL,0);
		}

		//pointer catre info din Header si datele pixeli

		pbmi = (BITMAPINFO*)(pbmfh +1);
		pBits = (BYTE *)pbmfh+pbmfh->bfOffBits;

		//latime si inaltime a DIB

		if(pbmi->bmiHeader.biSize==sizeof(BITMAPCOREHEADER))
		{
			im_width=((BITMAPCOREHEADER*)pbmi)->bcWidth;
				im_height=((BITMAPCOREHEADER*)pbmi)->bcHeight;
		}
		else
		{
			im_width=pbmi->bmiHeader.biWidth;
			im_height=abs(pbmi->bmiHeader.biHeight);
		}
		nrBytesPerPixel=pbmi->bmiHeader.biBitCount/8;

		//creez noua imagine

		if(!mainImage)
			mainImage=new MyImage();

		//setez elementele in functie de buffer-ul RGB
		mainImage->SetImageFromRGB(pBits, nrBytesPerPixel, im_width, im_height);
	}
	AfisareImagine();
}

void COpenSaveColorDlg::OnBnClickedSave()
{
	static TCHAR szFileName[MAX_PATH],szTitleName[MAX_PATH];
	prelImage->InitImage(mainImage->getWidth(),mainImage->getHeight());

	COLORREF c,val;
	unsigned char* p=(unsigned char*)(&c);
	unsigned char &r=p[2];
	unsigned char &g=p[1];
	unsigned char &b=p[0];

	for(int y=0;y<mainImage->getHeight();y++)
		for(int x=0;x<mainImage->getWidth();x++)
		{
			c=mainImage->getPixel(x,y);
			val=RGB(255-r,255-g,255-b);
			prelImage->setPixel(x,y,val);
		}

	if(DibFileSaveDlg(NULL,(PSTR)szFileName,(PSTR)szTitleName))
		if(!SaveDIB((PSTR)szFileName,prelImage->getPixelBuffer(), prelImage->getWidth(), prelImage->getHeight()))
		{
			MessageBoxA(TEXT("Error in saving"), NULL,0);			
		}
//	delete prelImage;
}

void COpenSaveColorDlg::OnClose()
{
	if(mainImage==NULL)
		delete mainImage;
	delete prelImage;
	CDialog::OnClose();
}

void COpenSaveColorDlg::AfisareImagine(void)
{
	CDC *pdc=GetDlgItem(IDC_PICTURE)->GetDC();
	CRect r1;
	GetDlgItem(IDC_PICTURE)->GetWindowRect(&r1);
	if(mainImage)
	{
		CBitmap bmp;
		bmp.CreateBitmap(mainImage->getWidth(),mainImage->getHeight(),4,8,mainImage->getPixelBuffer());
		CBrush *b=new CBrush(&bmp);
		int w,h;
		if (mainImage->getWidth()<r1.Width()) w=mainImage->getWidth();
		else w=r1.Width();
		if (mainImage->getHeight()<r1.Height()) h=mainImage->getHeight();
		else h=r1.Height();
		CRect r(0,0,w-1,h-1);
		pdc->FillRect(r,b);
	}
}

void COpenSaveColorDlg::OnFisierOpen()
{
	MessageBox("Open");
}

int COpenSaveColorDlg::Prel(void)
{
	return 0;
}
