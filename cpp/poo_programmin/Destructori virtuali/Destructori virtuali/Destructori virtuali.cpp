#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

class B
{
public:
	B()
	{
		cout<<"Constructor clasa de baza"<<endl;
	}

	~B()
	{
		cout<<"Destructor clasa de baza"<<endl;
	}
};

class D:public B
{
public:
	int x;
	D()
	{
		cout<<"Constructorul clasa derivata"<<endl;
	}

	~D()
	{
		cout<<"Destructor clasa derivata"<<endl;
	}
};

void main()
{
	B *p=new D;
	delete p;

	getch();
}

