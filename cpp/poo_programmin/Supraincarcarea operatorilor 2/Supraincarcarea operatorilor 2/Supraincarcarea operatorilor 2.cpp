#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Multime
{
	int n,e[1000];
};

void interclasare(int m, int *a, int n, int *b, int *c)
{
	int i=0,j=0,k=0,l;

	while(i<m && j<n)
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];
	for(l=i;l<m;l++)
		c[k++]=a[l];
	for(l=j;l<m;l++)
		c[k++]=b[l];
}

void sortInterclas(int s, int d, int *a, int *b)
{
	if(s==d)
	{
		b[0]=a[s];
		return;
	}
	int m=(s+d)/2,*a1,*a2;

	a1=new int[m-s+1];
	a2=new int[d-m];
	sortInterclas(s,m,a,a1);
	sortInterclas(m+1,d,a,a2);
	interclasare(m-s+1,a1,d-m,a2,b);
	delete [] a1;
	delete [] a2;
}

int cautareBinara(int x,int s,int d,int *a)
{
	if(s==d)
	{
		if(a[s]==x)
			return 1;
		else 
			return 0;
	}
	int m=(s+d)/2;
	if(a[m]==x)
		return 1;
	if(x<a[m])
		return cautareBinara(x,s,m,a);
	return cautareBinara(x,m+1,d,a);
}

Multime operator +(Multime a,Multime b)
{
	int i;
	Multime c;

	if(a.n<b.n)
	{
		if(a.n)
			sortInterclas(0,a.n-1,a.e,c.e);
		c.n=a.n;
		for(i=0;i<b.n;i++)
			if(!cautareBinara(b.e[i],0,a.n-1,c.e))
				c.e[c.n++]=b.e[i];
	}
	else
	{
		if(b.n)
			sortInterclas(0,b.n-1,b.e,c.e);
		c.n=b.n;
		for(i=0;i<a.n;i++)
			if(!cautareBinara(a.e[i],0,b.n-1,c.e))
				c.e[c.n++]=a.e[i];
	}
	return c;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Multime n,m,a,b,c;
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
	getch();

	return 0;
}

