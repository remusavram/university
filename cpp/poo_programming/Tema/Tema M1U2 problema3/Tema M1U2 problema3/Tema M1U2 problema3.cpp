#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int ***a,i,j,k;
	unsigned int p,m,n;

	cout<<"Introduceti dimensiunile matricii tridimensionale: "<<endl<<endl;
	cout<<"m= ";
	cin>>m;
	cout<<"n= ";
	cin>>n;
	cout<<"p= ";
	cin>>p;

	a=new int**[m];

	for(i=0;i<m;i++)
		a[i]=new int*[n];

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			a[i][j]=new int[p];

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<p;k++)
			{
				cout<<"a["<<i+1<<"]["<<j+1<<"]["<<k+1<<"]= ";
				cin>>a[i][j][k];
			}


	getch();
	return 0;
}

