#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	unsigned int n,*a;
	int **v,*vpp,z,k=0,c=0;
	float x,y;

	cout<<"n= ";
	cin>>n;

	a=new unsigned int[n];

	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]= ";
		cin>>a[i];
	}

	v=new int*[n];
	for(int i=0;i<n;i++)
		v[i]=new int[a[i]];

	for(int i=0;i<n;i++)
		for(int j=0;j<a[i];j++)
		{
			cout<<"v["<<i+1<<"]["<<j+1<<"]= ";
			cin>>v[i][j];
		}

	for(int i=0;i<n;i++)
		for(int j=0;j<a[i];j++)
		{
			x=v[i][j];
			y=sqrt(x);
			z=y;
			if((z==y) && (z!=1) && (z!=0))
				k=k+1;
		}

	vpp=new int[k];
	for(int i=0;i<n;i++)
		for(int j=0;j<a[i];j++)
		{
			x=v[i][j];
			y=sqrt(x);
			z=y;
			if((z==y) && (z!=1) && (z!=0))
			{
				vpp[c]=x;
				c=c+1;
			}
		}

	cout<<endl<<endl<<"Elementele patrate perfecte ale celor "<<n<<" vectori sunt: ";

	for(int i=0;i<k;i++)
		cout<<vpp[i]<<" ";

	delete [] vpp;
	for(int i=0;i<n;i++)
		delete [] v[i];
	delete [] v;
	delete [] a;

	getch();
	return 0;
}

