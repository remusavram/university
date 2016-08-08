#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

void g(int &x, int y, int z=0, int w=0, int q=0)
{

	if(x<y)
		x=y;
	if(x<z)
		x=z;
	if(x<w)
		x=w;
	if(x<q)
		x=q;

}


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,c,d,e;

	cout<<"a= ";
	cin>>a;
	cout<<"b= ";
	cin>>b;
	cout<<"c= ";
	cin>>c;
	cout<<"d= ";
	cin>>d;
	cout<<"e= ";
	cin>>e;

	g(a,b);
	cout<<"Maximul dintre numere este: "<<a;

	getch();
	return 0;
}

