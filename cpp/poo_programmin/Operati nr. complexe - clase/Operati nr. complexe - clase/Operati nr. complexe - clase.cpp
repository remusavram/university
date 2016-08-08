#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>

using namespace std;

class complex
{
private:
	double re,im;

public:
	complex(double re=0, double im=0)
	{
		this->re=re;
		this->im=im;
	}

	double GetRe()
	{
		return re;
	}

	void SetRe(double r)
	{
		re=r;
	}

	double GetIm()
	{
		return im;
	}

	void SetIm(double im)
	{
		this->im=im;
	}

//	double Modul();
	friend complex operator +(complex c1, complex c2);
	friend ostream& operator <<(ostream& out, complex c);
	friend double operator !(complex c);
	friend complex operator *(complex c1, complex c2);
	friend complex operator -(complex c1, complex c2);
};

/*
double complex::Modul()						// nu mai aven nevoie de functia Modul deoarece am supraincarcat operatorul ! ca si modul
{
	return sqrt((re*re)+(im*im));
}
*/

complex operator +(complex c1, complex c2)
{
	complex rez(c1.re+c2.re,c1.im+c2.GetIm());
	return rez;
}

ostream& operator <<(ostream& out, complex c)
{
		if(c.im==0)
		out<<c.re;
	else
		if(c.im<0)
			out<<c.re<<c.im<<"*i";
		else
			out<<c.re<<"+"<<c.im<<"*i";
	return out;
}

double operator !(complex c)
{
	return sqrt(c.re*c.re+c.im*c.im);
}

int operator >(complex c1, complex c2)
{
	if(!c1>!c2)
		return 1;
	return 0;
}

int operator <(complex c1, complex c2)
{
	return !c1<!c2;
}

int operator ==(complex c1, complex c2)
{
	return c1==c2;
}

complex operator *(complex c1, complex c2)
{
	complex produs;

	produs.re=(c1.re*c2.re)-(c1.im*c2.im);
	produs.im=(c1.re*c2.im)+(c2.re*c1.im);
	return produs;
}

complex operator *=(complex &c1, complex &c2)
{
	c1=c1*c2;
	return c1;
}

void sortare (complex *c, int n)
{
	int ok=0;

	while(ok==0)
	{
		ok=1;
		for(int i=0;i<n-1;i++)
			if(c[i]>c[i+1])
			{
				ok=0;
				complex aux=c[i];
				c[i]=c[i+1];
				c[i+1]=aux;
			}
	}	
}

complex nr_max_complex(complex *c, int n)
{
	complex max=c[0];

	for(int i=1;i<n;i++)
		if(!max<!c[i])
			max=c[i];
	return max;
}

complex nr_min_complex(complex *c, int n)
{
	complex min=c[0];

	for(int i=1;i<n;i++)
		if(!min>!c[i])
			min=c[i];
	return min;
}

void afisare_vector(complex *c,int n)
{
	for(int i=0;i<n-1;i++)
		cout<<c[i]<<", ";
	cout<<c[n-1]<<".";
}

complex operator -(complex c1, complex c2)
{
	complex rezultat;

	rezultat.re=c1.re-c2.re;
	rezultat.im=c1.im-c2.im;
	return rezultat;
}

complex operator +=(complex &c1, complex c2)
{
	return c1=c1+c2;
}

void main()
{
	complex *c, suma, produs, max, min;
	int n;

	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Introduceti numarul de numere complexe: ";
	cin>>n;
	c=new complex[n];
	cout<<endl<<"Introduceti sirul de nr. complexe: "<<endl;
	for(int i=0;i<n;i++)
	{
		double x,y;
		cout<<"c["<<i+1<<"].re= ";
		cin>>x;
		cout<<"c["<<i+1<<"].im= ";
		cin>>y;
		c[i].SetRe(x);
		c[i].SetIm(y);
	}
	cout<<endl<<"Ati introdus nr. complexe: ";
	afisare_vector(c,n);

	for(int i=0;i<n;i++)
		suma+=c[i];
	cout<<endl<<"Suma numerelor complexe introduse este: ";
	cout<<suma<<endl;
	cout<<"Modulul sumei numerelor complexe este: "<<!suma;

	produs.SetRe(1);
	produs.SetIm(1);
	for(int i=0;i<n;i++)
		if(c[i].GetRe()>c[i].GetIm())
			produs*=c[i];
	cout<<endl<<"Produsul nr. complexe care au partea re > ca partea im este: "<<produs;	

	sortare(c,n);
	cout<<endl<<"Sirul nr. complexe ordonat crescator in functie de modulul nr. este: ";
	afisare_vector(c,n);

	max=nr_max_complex(c,n);
	min=nr_min_complex(c,n);
	cout<<endl<<"Diferenta dintre cel mai mare nr. com in modul si cel mai mic nr. com in modul este: "<<max-min;

	getch();
}

