#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;


void main()
{
	int n, *a;

	ifstream f("Numere.in");
		f>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		f>>a[i];
	f.close();

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}

	ofstream g("sir.out");
	for(int i=0;i<n;i++)
		g<<a[i]<<" ";
	g.close();
	delete [] a;

	getch();
}

