#ifndef __MYGIMAGE_H_
#define __MYGIMAGE_H_

class MyImage
{
	protected:
		int height;
		int width;
		COLORREF *pixelBuffer;
		
	public:
		MyImage()
		{
			pixelBuffer=NULL;
		}
		MyImage(int width, int height)
		{
			this->width=width;
			this->height=height;
			pixelBuffer=new COLORREF[width*height];
		}
	
		MyImage(MyImage &im)
		{
			height=im.height;
			width=im.width;
			pixelBuffer=new COLORREF[height*width];
			for(int i=0;i<height*width;i++)
				pixelBuffer[i]=im.pixelBuffer[i];
		
				
		}
		void SetImageFromRGB(BYTE *pBits, int nrBytesPerPixel, int im_width, int im_height);
		
//		void SaveImage(NULL);//HWND hwnd);
		void setBuffer(COLORREF *buffer);
		
		void setPixel(int x, int y, COLORREF color);
		void setPixel(int x, COLORREF color);
		//void CreateImageFromBytes(BYTE *buffer, int widthIm, int heightIm);
		void drawImageInWindow(CWnd *hwnd);		

		COLORREF *getPixelBuffer();
		
		COLORREF getPixel(int x, int y);
		COLORREF getPixel(int i);
		
		void InitImage(int width, int height);
		int getHeight();
		int getWidth();
		int getNrPixels();
		
			
		~MyImage()
		{
			if(pixelBuffer!=NULL)
				delete[] pixelBuffer;
		
			pixelBuffer=NULL;
	
		}
};

#endif __MYGIMAGE_H_