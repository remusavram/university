#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Multime
{
	int n,e[1000];
};

int cautsecv(int x, int n, int *a)
{
	for(int i=0;i<n;i++)
		if(x==a[i])
			return 1;
	return 0;
}

Multime operator +(Multime a, Multime b)
{
	Multime c;
	for(int i=0;i<a.n;i++)
		c.e[i]=a.e[i];
	c.n=a.n;
	for(int i=0;i<b.n;i++)
		if(!cautsecv(b.e[i],a.n,a.e))
			c.e[c.n++]=b.e[i];
	return c;
}

Multime operator +(Multime a,int x)
{
	Multime b;

	for(int i=0;i<a.n;i++)
		b.e[i]=a.e[i];
	b.n=a.n;
	if(!cautsecv(x,b.n,b.e))
		b.e[b.n++]=x;
	return b;
}

ostream& operator <<(ostream& f1,Multime& a)
{
	for(int i=0;i<a.n;i++)
		f1<<a.e[i]<<" ";
	return f1;
}

istream& operator >>(istream& f1,Multime& a)
{
	f1>>a.n;
	for(int i=0;i<a.n;i++)
		f1>>a.e[i];
	return f1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Multime n,m,a,b,c;
	int x;

	cout<<"Dati prima multime: "<<endl;
	cin>>a;
	cout<<"Dati a doua multime: "<<endl;
	cin>>b;
	cout<<"Dati un nr. intreg: ";
	cin>>x;
	c=a+b+x;
	cout<<"Reuniunea este: "<<c<<endl;
	getch();
	return 0;
}

