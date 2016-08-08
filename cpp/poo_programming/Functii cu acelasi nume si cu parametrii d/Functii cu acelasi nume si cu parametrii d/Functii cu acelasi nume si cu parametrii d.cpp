#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int x,y;

int max(int, int y)
	{
		if(x>y)
			return x;
		return y;
	}


int max(int x,int y, int z)
{
	if(x>y)
	{
		if(x>z)
			return x;
		return z;
	}
	if(y>z)
		return y;
	return z;
}


double max(double x, double y)
{
	if(x>y)
		return x;
	return y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a=1,b=2,c=0,max1,max2;
	float A=5.52f,B=7.1f,max3;
	double A2=2,B2=1.1,max4;

	max1=max(a,b);
	max2=max(a,b,c);
	max3=(float)max(A,B);
	max4=max(A2,B2);
	cout<<max1<<", "<<max2<<", ";
	cout<<max3<<", "<<max4<<endl;


	getch();
	return 0;
}

