#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

//=======================================================

void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
}

//=======================================================

struct Multime
{
	int n,e[1000];
};

//=======================================================

int cautare_secventiala(int n, int *b, int x)
{
	for(int i=0;i<n;i++)
		if(b[i]==x)						
			return 1;
	return 0;
}

//=======================================================

ostream& operator <<(ostream& f1,Multime& a)
{
	for(int i=0;i<a.n;i++)
		f1<<a.e[i]<<" ";
	return f1;
}

//=======================================================

istream& operator >>(istream& f1, Multime& a)
{
	f1>>a.n;
	cout<<endl<<"Introduceti elementele multimii: "<<endl;
	for(int i=0;i<a.n;i++)
	{
		cout<<"m["<<i+1<<"]= ";
		f1>>a.e[i];
	}
	return f1;
}

//=======================================================

Multime operator -(Multime a, Multime b)
{
	Multime c;
	
	c.n=0;
	for(int i=0;i<a.n;i++)
		if(!cautare_secventiala(b.n,b.e,a.e[i]))
			c.e[c.n++]=a.e[i];
	return c;
}

//=======================================================

Multime operator *(Multime a, Multime b)
{
	Multime c;

	c.n=0;
	for(int i=0;i<a.n;i++)
		if((cautare_secventiala(b.n,b.e,a.e[i])) && !(cautare_secventiala(c.n,c.e,a.e[i])))				//cautam elementul in multimea b si verificam sa nu existe deja in multimea c
			c.e[c.n++]=a.e[i];
	return c;
}

//=======================================================

Multime operator +=(Multime& a,Multime b)
{
    for(int i=0;i<b.n;i++)
        if(!cautare_secventiala(a.n,a.e,b.e[i]))
            a.e[a.n++]=b.e[i];
    return a;
}

//=======================================================

Multime operator -(Multime a, int x)  // cautam in multimea a valoarea x
{
	Multime c;
	int k=0;

	for(int i=0;i<a.n;i++)
		if(a.e[i]!=x)
			c.e[k++]=a.e[i];
	c.n=k;
	return c;
}

//=======================================================

Multime operator -=(Multime& a, Multime b)
{
	Multime c;

	c.n=0;
	for(int i=0;i<a.n;i++)
		if(!cautare_secventiala(b.n,b.e,a.e[i]))
			c.e[c.n++]=a.e[i];
	a.n=c.n;
	for(int i=0;i<a.n;i++)
		a.e[i]=c.e[i];
	return a;
}

//=======================================================

Multime operator *=(Multime& a, Multime b)
{
	Multime c;

	c.n=0;
	for(int i=0;i<a.n;i++)
		if(cautare_secventiala(b.n,b.e,a.e[i]))
			c.e[c.n++]=a.e[i];
	a.n=c.n;
	for(int i=0;i<c.n;i++)
		a.e[i]=c.e[i];
	return a;
}

//=======================================================

void citire_multime(Multime &a, Multime &b)
{
	cout<<"Introduceti nr. de elemente a primei multimi: ";
	cin>>a;
	cout<<endl<<"Introduceti nr. de elemente pentru a doua multime: ";
	cin>>b;
}

//=======================================================

int _tmain(int argc, _TCHAR* argv[])
{
	Multime a,b,c,d;
	char optiune;

	citire_multime(a,b);

	do
	{
		spati();
		cout<<"1.Operatorul '-' pentru diferenta dintre prima multime si a doua multime."<<endl;
		cout<<"2.Operatorul '-' pentru scoaterea unui element dintr-o multime."<<endl;
		cout<<"3.Operatorul '*' pentru intersectia a doua multimi."<<endl;
		cout<<"4.Operatorul '+=' pentru adunarea a doua multimi si trecerea rezultatului in prima multime."<<endl;
		cout<<"5.Operatorul '-=' pentru diferenta dintre prima multime si a doua multime si trecerea rezultatului in prima multime."<<endl;
		cout<<"6.Operatorul '*=' petru intersectia a doua multimi si trecerea rezultatului in prima multime."<<endl;
		cout<<"Esc - parasire program!"<<endl;

		optiune=getch();
		spati();
		switch(optiune)
		{
			case '1':
				c=a-b;
				cout<<endl<<"Diferenta dintre prima multime si a doua multime este: ";
				if(!c.n)
					cout<<"multimea vida";
				else
					cout<<c;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '2':
				int x;

				if(!a.n)
					cout<<"Multimea nu mai contine nici un element!";
				else
				{
					cout<<"Introduceti elementul ce doriti sa il scoateti din prima multime: ";
					cin>>x;
					a=a-x;
					if(a.n==0)
						cout<<"Multimea nu mai contine nici un element!";
					else
					{
						cout<<endl<<"Dupa extragerea elementului "<<x<<" multimea contine elementele: ";
						cout<<a;
					}
				}
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '3':
				d=a*b;
				cout<<endl<<"Intersectia dintre cele doua multimi este: ";
				if(!d.n)
					cout<<"multimea vida";
				else
					cout<<d;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '4':
				a+=b;
				cout<<endl<<"Adunarea dintre cele doua multimi folosind '+=' este: ";
				if(!a.n)
					cout<<"multimea vida";
				else
					cout<<a;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '5':
				a-=b;
				cout<<endl<<"Diferenta dintre prima multime si a doua folosind '-=' este: ";
				if(!a.n)
					cout<<"multimea vida";
				else
					cout<<a;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '6':
				a*=b;
				cout<<"Intersectia dintre prima multime si a doua folosind '*=' este: ";
				if(!a.n)
					cout<<"multimea vida";
				else
					cout<<a;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case 27:
				cout<<"Apasati orice tasta pentru a parasi programul!";
				break;
			default:
				cout<<"Apasati 1,2,3,4,5,6 sau Esc!!!";
		}
		getch();
	}
	while(optiune!=27);

	return 0;
}

