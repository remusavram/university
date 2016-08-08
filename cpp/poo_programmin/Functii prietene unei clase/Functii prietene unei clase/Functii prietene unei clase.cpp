#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

class dreptunghi
{
	private:
		float x1,y1,x2,y2;
	public:
		dreptunghi(float X1, float Y1, float X2, float Y2)
		{
			x1=X1;
			x2=X2;
			y1=Y1;
			y2=Y2;
		}
		friend float get_x1(dreptunghi d)
		{
			return d.x1;
		}
		friend void set_x1(dreptunghi,float);
		friend float arie(dreptunghi d)
		{
			return fabs((d.x2-d.x1)*(d.y2-d.y1));
		}
		friend float perimetru(dreptunghi);							
};

void set_x1(dreptunghi d, float X1)
{
	 d.x1=X1;
}

float perimetru(dreptunghi d)
{
	return 2*(fabs(d.x2-d.x1)+fabs(d.y2-d.y1));
}


void main(void)
{
	dreptunghi d(20,10,70,50);
	cout<<"Aria dreptunghiului:		  "<<arie(d)<<endl;
	cout<<"Perimetrul dreptunghiului: "<<perimetru(d)<<endl;
	cout<<"Dreptunghiul are ordonata: "<<get_x1(d)<<endl;
	getch();
}

