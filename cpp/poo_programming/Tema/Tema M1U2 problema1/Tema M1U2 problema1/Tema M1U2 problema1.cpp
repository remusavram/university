#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int i,n,j;
	double **v,*vmedi,ma;

	cout<<"n= ";
	cin>>n;

	v=new double*[n];

	for(i=0;i<n;i++)
		v[i]=new double[i+1];

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			cout<<"v["<<i+1<<"]["<<j+1<<"]= ";
			cin>>v[i][j];
		}

	vmedi=new double[n];

	for(i=0;i<n;i++)
	{
		ma=0;
		for(j=0;j<=i;j++)
			ma=ma+v[i][j];
		vmedi[i]=ma/(i+1);	
	}

	cout<<endl<<endl<<"Vectorul format cu mediile aritmetice ale celor "<<n<<" vectori este: ";

	cout<<setiosflags(ios::fixed);
	for(i=0;i<n;i++)
		cout<<setprecision(2)<<vmedi[i]<<" ";

	for(i=0;i<n;i++)
		delete [] v[i];
	delete [] v;
	delete [] vmedi;

	getch();
	return 0;
}

