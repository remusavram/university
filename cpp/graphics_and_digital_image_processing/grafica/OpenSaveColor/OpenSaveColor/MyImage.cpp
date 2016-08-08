#include<stdafx.h>
#include<windows.h>
#include "OpenSave.h"
#include "MyImage.h"


void MyImage::InitImage(int width, int height)
{
	this->width=width;
	this->height=height;
	if(pixelBuffer!=NULL) delete []pixelBuffer;
	pixelBuffer=new COLORREF[width*height];
}
//Incarca imaginea din fisier 

void MyImage::SetImageFromRGB(BYTE *pBits, int nrBytesPerPixel, int im_width, int im_height)
{
		width=im_width;
		height=im_height;
		
		if(pixelBuffer) delete []pixelBuffer; 
		pixelBuffer=new COLORREF[width*height];
		//pixelBuffer
		
		int padding=0;
		
		int scanlinebytes=width*nrBytesPerPixel;
		
		while((scanlinebytes+padding)%4!=0)
			padding++;
	
		int pws = scanlinebytes+padding;
		int newpos;
	
		for(int y=0;y<height;y++)
		for(int x=0, xx=0;x<nrBytesPerPixel*width;x+=nrBytesPerPixel,xx++)
		{
			newpos=(height-y-1)*pws+x;
			pixelBuffer[y*width+xx]=RGB(pBits[newpos],pBits[newpos+1],pBits[newpos+2]);
		}
		
}

//seteaza buffer-ul de pixeli

void MyImage::setBuffer(COLORREF *buffer)
{
	for(int i=0;i<width*height;i++)
		pixelBuffer[i]=buffer[i];
}


void MyImage::setPixel(int x, int y, COLORREF color)
{
	if(x>=0 && x<width && y>=0 && y<height)
	pixelBuffer[y*width+x]=color;
}

//seteaza un pixel dat de coordonata x in buffer
void MyImage::setPixel(int x, COLORREF color)
{
	if(x>=0 && x<width*height)
		pixelBuffer[x]=color;
}

//returneaza bufferul de pixeli
COLORREF *MyImage::getPixelBuffer()
{
	return pixelBuffer;
}

//returneaza culoarea pixelului
COLORREF MyImage::getPixel(int x, int y)
{
	if(x>=0 && x<width && y>=0 && y<height)
		return pixelBuffer[y*width+x];
	else return 0;
}
COLORREF MyImage::getPixel(int x)
{
	if(x>=0 && x<width*height)
		return pixelBuffer[x];
	else return 0;
}
int MyImage::getHeight()
{
	return height;
}
int MyImage::getWidth()
{
	return width;
}
int MyImage::getNrPixels()
{
	return width*height;
}
//deseneaza imaginea intr-o fereastra
void MyImage::drawImageInWindow(CWnd *hwnd)
{
	//CDC	*dc = GetDC;
/*	CDC *dc=hwnd->GetDC();
	BYTE *bts;

	int padding=0;
	int scanlinebytes=width*3;
	while((scanlinebytes+padding)%4!=0)
		padding++;
	int pws = scanlinebytes+padding;
	int newpos;

	bts= new BYTE[height*pws];

	for(int y=0;y<height;y++)
	for(int x=0, xx=0;x<3*width;x+=3,xx++)
	{
		newpos=(height-y-1)*pws+x;
		bts[newpos+2]=pixelBuffer[y*width+xx]; //red value
		bts[newpos+1]=pixelBuffer[y*width+xx];//green value
		bts[newpos]=pixelBuffer[y*width+xx];//blue value
			
	}

	HBITMAP			 hbm;
	HBITMAP			 hbmOld;
	HDC				 hdcBits;
	BITMAPINFOHEADER pbmih;
	pbmih.biSize			= sizeof(pbmih); 
    pbmih.biWidth			= width; 
    pbmih.biHeight			= height; 
    pbmih.biPlanes			= 1; 
    pbmih.biBitCount		= 24; 
    pbmih.biCompression		= BI_RGB; 
    pbmih.biSizeImage		= 0; 
    pbmih.biXPelsPerMeter	= width; 
    pbmih.biYPelsPerMeter	= height;
    pbmih.biClrUsed			= 0; 
    pbmih.biClrImportant	= 0; 
	
	hbm = (HBITMAP)CreateDIBitmap(dc, &pbmih, CBM_INIT, bts, (PBITMAPINFO)&pbmih, DIB_RGB_COLORS); 
	hdcBits = CreateCompatibleDC(dc);
	hbmOld = (HBITMAP)SelectObject(hdcBits,hbm);
	
	BitBlt(dc,0,0,pbmih.biWidth, pbmih.biHeight,hdcBits,0,0,SRCCOPY);
	
	(HBITMAP)SelectObject(hdcBits,hbmOld);
	DeleteObject(hbm);
	DeleteDC(hdcBits); 
	
	delete [] bts;
	DeleteObject(hbm);
	bts=NULL;
	*/
}