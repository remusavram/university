#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;


void prime(int n, int *v1, int &m, int *&v2)
{
	int i,j,*v3,k=0,ok;
	double x;

	m=0;
	v3=new int[n];
	for(i=0;i<n;i++)
		v3[i]=0;
	for(i=0;i<n;i++)
	{
		ok=0;
		if((v1[i]%2)!=0)
		{
			for(j=2;j<=(v1[i]/2);j++)
			{	
				x=v1[i]%j;
				if(x==0)
				{
					ok=1;
					break;
				}
			}
			if(ok==0)
			{
				m++;
				v3[i]=v3[i]+1;
			}
		}
	}
	v2=new int[m];
	for(i=0;i<n;i++)
		if(v3[i]==1)
		{
			v2[k]=v1[i];
			k++;
		}
	delete [] v3;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,*v1,m,*v2;

	cout<<"n= ";
	cin>>n;
	v1=new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"v1["<<i+1<<"]= ";
		cin>>v1[i];
	}


	prime(n,v1,m,v2);
	cout<<endl<<"Elementele prime ale sirului sunt: ";
		for(i=0;i<m;i++)
			cout<<v2[i]<<" ";

		delete [] v2;
		delete [] v1;
	getch();
	return 0;
}

