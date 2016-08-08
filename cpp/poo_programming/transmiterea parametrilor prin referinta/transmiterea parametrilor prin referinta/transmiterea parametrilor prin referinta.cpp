#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


void transformare(int n,int *&a,int &m,int &p,int *&v1,int *&v2)
{
	int k1=0,k2=0;
	m=0;
	p=0;

	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
			p++;
		else
			m++;
	}
	v1=new int[m];
	v2=new int[p];

	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			v1[k1]=a[i];
			k1=k1+1;
		}
		else
		{
			v2[k2]=a[i];
			k2=k2+1;
		}
	}
	delete [] a;	
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n,*v1,*v2,n1,n2,*a;
	cout<<"Dati nr. de elemente al vectorului: ";
	cin>>n;

	a=new int[n];

	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]= ";
		cin>>a[i];
	}


	transformare(n,a,n1,n2,v1,v2);
	cout<<"Sirul de elemente negative este: ";
	for(int i=0;i<n2;i++)
		cout<<v2[i]<<" ";
	cout<<endl<<"Sirul de elemente pozitive este: ";
	for(int i=0;i<n1;i++)
		cout<<v1[i]<<" ";

	delete [] v1;
	delete [] v2;

	getch();
	return 0;
}

