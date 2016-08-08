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

int _tmain(int argc, _TCHAR* argv[])
{
	Multime a,b,c;
	int q=99;

	cout<<"Dati nr. elementelor multimii a: ";
	cin>>a.n;
	cout<<endl<<"Introduceti elementele multimii a"<<endl<<endl;
	for(int i=0;i<a.n;i++)
	{
		cout<<"a["<<i+1<<"]= ";
		cin>>a.e[i];
	}
	cout<<endl<<endl<<"Dati nr. elementelor multimii b: ";
	cin>>b.n;
	cout<<endl<<"Introduceti elementele multimii b"<<endl<<endl;
	for(int i=0;i<b.n;i++)
	{
		cout<<"b["<<i+1<<"]= ";
		cin>>b.e[i];
	}
	c=a+b;					// am folosit operatorul spraincarcat "+" pt. reuniunea multimilor
	cout<<endl<<"Elementele celor doua multimi reunite sunt: ";
	for(int i=0;i<c.n;i++)
		cout<<c.e[i]<<" ";

	a=a+q;					// adaug elementul q la multimea a
	cout<<endl<<endl<<"Dupa introducerea elementului q, noua multime a are elementele: ";
	for(int i=0;i<a.n;i++)
		cout<<a.e[i]<<" ";
	getch();
	return 0;
}

