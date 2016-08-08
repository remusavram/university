#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>

using namespace std;

class complex
{
private:
	float re,im;
public:
	complex(float x=0, float y=0)
	{
		re=x;
		im=y;
	}

	complex operator +(complex z2)
	{
		complex z;
		z.re=re+z2.re;
		z.im=im+z2.im;
		return z;
	}

	complex operator +(float r)
	{
		complex z;
		z.re=re+r;
		z.im=im;
		return z;
	}

	friend complex operator +(float r, complex z2)
	{
		complex z;
		z.re=r+z2.re;
		z.im=z2.im;
		return z;
	}

	friend complex operator -(complex z1, complex z2)
	{
		complex z;
		z.re=z1.re-z2.re;
		z.im=z1.im-z2.im;
		return z;
	}
	
	friend istream& operator >>(istream &in, complex &z);
	friend ostream& operator <<(ostream &out, complex &z);
};

istream& operator >>(istream &in, complex &z)
{
	in>>z.re>>z.im;
	return in;
}

ostream& operator <<(ostream &out, complex &z)
{
	if(z.im>=0)
		out<<z.re<<"+"<<z.im<<"i";
	else
		out<<z.re<<z.im<<"i";
	return out;
}


void main(void)
{
	complex z,z1(1),z2(2,5);

	cout<<"Suma este:      "<<(z1+z2)<<endl;
	cout<<"Diferenta este: "<<(z1-z2)<<endl;
	cout<<"Complex + real: "<<(z1+7)<<endl;
	cout<<"Real + complex: "<<(8.2+z2)<<endl;
}

