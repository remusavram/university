#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
T maxim(T x,T y)
{
	T m;
	if(x>y)
		m=x;
	else m=y;
	return m;
}

template <class T>
void intersch(T &x,T &y)
{
	T aux=x;
	x=y;
	y=aux;
}

template <class T1,class T2>
void inc(T1 &x,T2 y)
{
	x+=y;
}

template <class T>
T ma(int n,T *a)
{
	T s=0;
	for(int i=0;i<n;i++)
		s+=a[i];
	return s/n;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int i=2,j=0,k;
	double m,a[4]={1.5,5,8,0},x=2,y=5.2;
	char *s1="Un string", *s2="Alt string", *s;
	cout<<i<<" "<<j<<endl;
	cout<<x<<" "<<y<<endl;

	k=maxim(i,j);
	m=maxim(x,y);
	inc(x,i);
	intersch(i,j);
	intersch(x,y);

	m=ma(4,a);
	s=maxim(s1,s2);

	cout<<i<<" "<<j<<endl;
	cout<<x<<" "<<y<<endl;
	cout<<m<<endl;
	cout<<k<<endl;
	cout<<s<<endl;
	getch();
	return 0;
}

