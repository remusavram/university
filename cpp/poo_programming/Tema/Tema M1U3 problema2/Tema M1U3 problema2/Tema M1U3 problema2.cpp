#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;


void functie(int n, int m, int **a,int *&v)
{
	int i,j,k=0;

	v=new int[n*m];
	for(i=0;i<n;i++)
		if((i%2)==0)
			for(j=0;j<m;j++)
				v[k++]=a[i][j];
		else
			for(j=m-1;j>=0;j--)
				v[k++]=a[i][j];
	for(i=0;i<n;i++)
		delete [] a[i];
	delete [] a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m,**a,*v,i,j;
	cout<<"n= ";
	cin>>n;
	cout<<"m= ";
	cin>>m;
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cout<<"a["<<i+1<<","<<j+1<<"]= ";
			cin>>a[i][j];
		}

	cout<<endl<<"Ati introdus matricea: "<<endl<<endl;
	cout<<setiosflags(ios::left);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<setw(7)<<a[i][j];
		cout<<endl;
	}

	functie(n,m,a,v);
	cout<<endl<<"Vectorul format cu elementele matricii luate in spirala este: ";
	for(i=0;i<n*m;i++)
		cout<<v[i]<<" ";


	getch();
	return 0;
}

