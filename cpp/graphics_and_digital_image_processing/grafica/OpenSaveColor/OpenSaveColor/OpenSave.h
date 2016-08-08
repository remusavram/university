#ifndef __DIBFILE_H_
#define __DIBFILE_H_

BOOL DibFileOpenDlg(HWND hwnd, PSTR pstrFileName, PSTR pstrTitleName);
BOOL DibFileSaveDlg(HWND hwnd, PSTR pstrFileName, PSTR pstrTitleName);
BITMAPFILEHEADER * DibLoadImage(PSTR FileName);

//BOOL SaveBitmap(HWND hwnd, PSTR pstrFileName,int left, int top, int right, int bottom);

//BOOL SaveBitmap(HWND hwnd, PSTR pstrFileName,BYTE *buffer,int height, int width);

BOOL SaveDIB(PSTR pstrFileName,COLORREF *buffer, int width, int height);
#endif __DIBFILE_H_