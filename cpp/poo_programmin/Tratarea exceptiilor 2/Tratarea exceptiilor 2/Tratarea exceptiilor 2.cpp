#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

double fct(double x, double v)
{
	return x*x-v;
}

double radical(double v, double precizie)
{
	if(precizie<=0)
		throw precizie;
	if(v<0)
		throw "Radical din nr. negativ.";
	if(!v || v==1)
		return v;
	double s,d,m,fs,fd,fm;

	if(v>1)
	{
		s=1;
		d=v;
	}
	else
	{
		s=v;
		d=1;
	}
	fs=fct(s,v);
	fd=fct(d,v);
	while(d-s>precizie)
	{
		m=(s+d)/2;
		fm=fct(m,v);
		if(!fm)
			return m;
		if(fs*fm<0)
		{
			d=m;
			fd=fm;
		}
		else
		{
			s=m;
			fs=fm;
		}
	}
	return m;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double x,p;

	cout<<"Dati un nr real: ";
	cin>>x;
	cout<<"Precizia calcularii radacinii patrate: ";
	cin>>p;
	try
	{
		double r=radical(x,p);
		cout<<"radical din "<<x<<" este "<<r<<endl;
	}
	catch(char *mesajEroare)
	{
		cerr<<mesajEroare<<endl;
	}
	catch(double prec)
	{
		cerr<<"Precizia nu poate fi: ";
		cerr<<prec<<endl;
	}

	getch();
	return 0;
}

