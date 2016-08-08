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
		float get_x1()
		{
			return x1;
		}
		float arie()
		{
			return fabs((x2-x1)*(y2-y1));
		}
		float perimetru();
};

float dreptunghi::perimetru()
{
	return 2*(fabs(x2-x1)+fabs(y2-y1));
}


void main(void)
{
	dreptunghi d(20,10,70,50);
	cout<<"Aria dreptunghiului:		  "<<d.arie()<<endl;
	cout<<"Perimetrul dreptunghiului: "<<d.perimetru()<<endl;
	cout<<"Dreptunghiul are ordonata: "<<d.get_x1()<<endl;
	//cout<<"Dreptunghiul are ordonata: "<<d.x1;
	getch();
}

