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

	virtual void functie()
	{
		cout<<"Functie clasa de baza"<<endl;
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

	void functie()
	{
		cout<<"Functie clasa derivata"<<endl;
	}
};

void main()
{
	B *p=new D;
	p->functie();

	getch();
}

