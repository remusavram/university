#include<stdafx.h>
#include<windows.h>
#include<commdlg.h>
#include <stdio.h>


#include <fstream>
#include"OpenSave.h"

#include <fstream>
#include <iostream>
#include <string>


using namespace std;


static OPENFILENAME ofn;
BOOL SaveDIB(PSTR pstrFileName,HWND hwnd, HBITMAP hBitmap, int Height);

BOOL DibFileOpenDlg(HWND hwnd, PSTR pstrFileName, PSTR pstrTitleName)
{
	static TCHAR szFilter[]=TEXT("Bitmapfiles (*.BMP)\0*.bmp\0")\
		TEXT("All files(*.*)\0*.*\0\0");

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.hInstance = NULL;
	ofn.lpstrFilter = szFilter;
//	ofn.lpsCustomFilter = NULL;
	ofn.nMaxCustFilter = 0;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = pstrFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = pstrTitleName;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrInitialDir =NULL;
	ofn.lpstrTitle = NULL;
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY;
	ofn.nFileOffset =0;
	ofn.nFileExtension = 0;
	ofn.lpstrDefExt =TEXT("bmp");
	ofn.lCustData = 0;
	ofn.lpfnHook = NULL;
	ofn.lpTemplateName = NULL;
	
	return GetOpenFileName(&ofn);
}

BOOL DibFileSaveDlg(HWND hwnd, PSTR pstrFileName, PSTR pstrTitleName)
{
	static TCHAR szFilter[]=TEXT("Bitmapfiles (*.BMP)\0*.bmp\0")\
		TEXT("All files(*.*)\0*.*\0\0");

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.hInstance = NULL;
	ofn.lpstrFilter = szFilter;
//	ofn.lpsCustomFilter = NULL;
	ofn.nMaxCustFilter = 0;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = pstrFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = pstrTitleName;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrInitialDir =NULL;
	ofn.lpstrTitle = NULL;
	ofn.Flags = OFN_OVERWRITEPROMPT;
	ofn.nFileOffset =0;
	ofn.nFileExtension = 0;
	ofn.lpstrDefExt =TEXT("bmp");
	ofn.lCustData = 0;
	ofn.lpfnHook = NULL;
	ofn.lpTemplateName = NULL;

	return GetSaveFileName(&ofn);
}

BITMAPFILEHEADER * DibLoadImage(PSTR pstrFileName)
{
	
	BOOL bSuccess;
	DWORD dwFileSize, dwHighSize, dwBytesRead;
	HANDLE hFile;
	BITMAPFILEHEADER *pbmfh;

	hFile = CreateFile(/*(LPWSTR)*/(LPSTR)pstrFileName, GENERIC_READ, FILE_SHARE_READ, 
					  NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if(hFile ==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,"Eroare o1",NULL,0);
		return NULL;
	}

	dwFileSize = GetFileSize(hFile, &dwHighSize);

	if(dwHighSize)
    {
		MessageBox(NULL,"Eroare o2",NULL,0);
		CloseHandle(hFile);
		return NULL;
	}

	pbmfh = (BITMAPFILEHEADER*)malloc(dwFileSize);

	if(!pbmfh)
	{
		MessageBox(NULL,"Eroare o3",NULL,0);
		CloseHandle(hFile);
		return NULL;
	}

	bSuccess = ReadFile(hFile,pbmfh,dwFileSize,&dwBytesRead,NULL);
	CloseHandle(hFile);
	


	if(!bSuccess || (dwBytesRead!=dwFileSize) || (pbmfh->bfType!=*(WORD *)"BM"))//|| (pbmfh->bfSize!=dwFileSize))
	{
		MessageBox(NULL,"Eroare o4",NULL,0);
		free(pbmfh);
		return NULL;
	}

	return pbmfh;
}



BOOL SaveDIB(PSTR pstrFileName,COLORREF *buffer, int width, int height)
{
	DWORD dwBytesWritten;

	LPBITMAPINFO lpbi;
	BYTE *lpvBits;
	HANDLE hFile;
	BITMAPFILEHEADER bmfh;
	BOOL bSuccess;
	
	if ((lpbi = (LPBITMAPINFO)(new char[sizeof(BITMAPINFOHEADER) +
        256 * sizeof(RGBQUAD)])) == NULL) 
	{
		MessageBox(NULL,"Eroare 4",NULL,0);
		bSuccess=0;
	}

	//determina dimansiunea vectorului pentru salvare
	int padding=0;
		
	int scanlinebytes=3*width;
	while((scanlinebytes+padding)%4!=0)
			padding++;
	
	int pws = scanlinebytes+padding;
	int newpos;
	
	///////umple cu 0 lpbi->bmiHeader
	ZeroMemory(&lpbi->bmiHeader, sizeof(BITMAPINFOHEADER));
	lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 

	//scrie header-ul
	lpbi->bmiHeader.biWidth			= width; 
    lpbi->bmiHeader.biHeight		= height; 
    lpbi->bmiHeader.biPlanes		= 1; 
    lpbi->bmiHeader.biBitCount		= 24; 
    lpbi->bmiHeader.biCompression	= BI_RGB; 
    lpbi->bmiHeader.biSizeImage		= pws*height; 
    lpbi->bmiHeader.biXPelsPerMeter	= 0; 
    lpbi->bmiHeader.biYPelsPerMeter	= 0;
    lpbi->bmiHeader.biClrUsed		= 0; 
    lpbi->bmiHeader.biClrImportant	= 0; 


	//aloc mem pt. vectorul de biti
	 if ((lpvBits = new BYTE[lpbi->bmiHeader.biSizeImage]) == NULL)
    {
		MessageBox(NULL,"Eroare 6",NULL,0);
		bSuccess=0;
	}

	 
	//completez vectorul de biti
	for(int y=0;y<height;y++)
	for(int x=0, xx=0;x<3*width;x+=3,xx++)
	{
			newpos=(height-y-1)*pws+x;
			COLORREF val=(buffer[y*width+xx]);
			lpvBits[newpos]=GetBValue(val); 
			lpvBits[newpos+1]=GetGValue(val); 
			lpvBits[newpos+2]=GetRValue(val);
	}
	
	if((hFile = CreateFile((LPSTR)pstrFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE) 
	{
		MessageBox(NULL,"Eroare 8",NULL,0);
		bSuccess=0;
	}

	bmfh.bfType = ((WORD) ('M' << 8) | 'B');//19778; // always the same, 'BM' (tip Bitmap)
	// bmfh.bfSize = ??? // we'll write that later
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0; // must be zero
	// bmfh.bfOffBits = ??? // we'll write that later

	//scriu Header-ul in fisier
	WriteFile(hFile, &bmfh, sizeof(bmfh), &dwBytesWritten, NULL);
	if (dwBytesWritten < sizeof(bmfh)) 
			{
		MessageBox(NULL,"Eroare 9",NULL,0);
		bSuccess=0;
	}

	WriteFile(hFile, &lpbi->bmiHeader, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL); 

//////////////////paleta de culori
	int PalEntries;
    // 16-bit or 32-bit bitmaps require bit masks:
    if (lpbi->bmiHeader.biCompression == BI_BITFIELDS) PalEntries = 3;
    else
        // bitmap is palettized?
        PalEntries = (lpbi->bmiHeader.biBitCount <= 8) ?
            // 2^biBitCount palette entries max.:
            (int)(1 << lpbi->bmiHeader.biBitCount)
        // bitmap is TrueColor -> no palette:
        : 0;
    // If biClrUsed use only biClrUsed palette entries:
    if (lpbi->bmiHeader.biClrUsed) PalEntries = lpbi->bmiHeader.biClrUsed;

    // Write palette to the file:
    if (PalEntries)
    {
        if (!WriteFile(hFile, lpbi->bmiColors, PalEntries * sizeof(RGBQUAD),
            &dwBytesWritten, NULL)) 
				{
		MessageBox(NULL,"Eroare 12",NULL,0);
		bSuccess=0;
	}
 
	if (dwBytesWritten < PalEntries * sizeof(RGBQUAD)) 
				{
		MessageBox(NULL,"Eroare 11",NULL,0);
		bSuccess=0;
	}
    }
/*	char szBuf1[30];
	sprintf(szBuf1,"palEntries: %d",PalEntries);//(int)pbmfh->bfSize);
	MessageBox(NULL,szBuf1,NULL,0);*/
	////////////////
//nr de biti de la inceputul Header-ului pana la bitii imaginii
	bmfh.bfOffBits =// (DWORD)sizeof(BITMAPINFOHEADER)+
					(DWORD)sizeof(bmfh)+
					 +(DWORD)sizeof(BITMAPINFOHEADER)//lpbi->bmiHeader.biSizeImage
					 +PalEntries * sizeof(RGBQUAD);
	/*PLONG p;
	SetFilePointer(hFile,0,p,FILE_CURRENT); */
	//char szBuf[5];
//	sprintf(szBuf,"lungime1: %ld",p);
//	MessageBox(hwnd,szBuf,NULL,0);
	//bmfh.bfOffBits =(DWORD)p;

//scriu sirul de biti ai imaginii in fisier
	if (!WriteFile(hFile, lpvBits, lpbi->bmiHeader.biSizeImage,&dwBytesWritten, NULL))
	{
		MessageBox(NULL,"Eroare 12",NULL,0);
		bSuccess=0;
	}
//verific daca am scris corect: vereic nr de biti scrisi	
	if (dwBytesWritten < lpbi->bmiHeader.biSizeImage) 
			{
		MessageBox(NULL,"Eroare 13",NULL,0);
		bSuccess=0;
	}
	
//calculez dimensiunea fisierului	
	bmfh.bfSize=lpbi->bmiHeader.biSizeImage+sizeof(BITMAPINFOHEADER);//(DWORD)p;
	
	SetFilePointer(hFile, 0, 0, FILE_BEGIN);
	bSuccess=WriteFile(hFile, &bmfh, sizeof(bmfh), &dwBytesWritten, NULL); 
	
	CloseHandle(hFile);
	//ReleaseDC(hwnd,hdc);
	
	if(!bSuccess)// ||(dwBytesWritten!=bmfh->bfSize))
	{
		DeleteFile(/*(LPWSTR)*/(LPSTR)pstrFileName);
		MessageBox(NULL,"Error in writing file",NULL,NULL);
		return FALSE;
	}
	return TRUE;
}


	
