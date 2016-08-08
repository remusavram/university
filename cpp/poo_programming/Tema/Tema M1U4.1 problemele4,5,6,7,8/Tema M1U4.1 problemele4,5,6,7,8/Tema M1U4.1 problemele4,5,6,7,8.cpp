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

int operator !(Multime a)
{
	return a.n;
}

//=======================================================

int operator <=(Multime a, Multime b)
{
	for(int i=0;i<a.n;i++)
		if(!cautare_secventiala(b.n,b.e,a.e[i]))
			return 0;
	return 1;
}

//=======================================================

int operator <(Multime a, Multime b)
{
	if(b.n<=a.n)
		return 0;
	if(a<=b)
		return 1;
	else 
		return 0;
}

//=======================================================

int operator >=(Multime a, Multime b)
{
	for(int i=0;i<b.n;i++)
		if(!cautare_secventiala(a.n,a.e,b.e[i]))
			return 0;
	return 1;
}

//=======================================================

int operator >(Multime a, Multime b)
{
	if(a.n<=b.n)
		return 0;
	if(a>=b)
		return 1;
	else
		return 0;
}

//=======================================================

int operator <(Multime a, int x)
{
	for(int i=0;i<a.n;i++)
		if(x==a.e[i])
			return 1;
	return 0;
}

//=======================================================

int operator ==(Multime a, Multime b)
{
	if(a.n!=b.n)
		return 0;
	for(int i=0;i<a.n;i++)
		for(int j=0;j<a.n;j++)
		{
			if(a.e[i]>a.e[j])
			{
				int aux=a.e[i];
				a.e[i]=a.e[j];
				a.e[j]=aux;
			}
			if(b.e[i]>b.e[j])
			{
				int aux=b.e[i];
				b.e[i]=b.e[j];
				b.e[j]=aux;
			}
		}
	for(int i=0;i<a.n;i++)
		if(a.e[i]!=b.e[i])
			return 0;
	return 1;
}

//=======================================================

int operator !=(Multime a, Multime b)
{
	if(a.n!=b.n)
		return 1;
	for(int i=0;i<a.n;i++)
		for(int j=0;j<a.n;j++)
		{
			if(a.e[i]>a.e[j])
			{
				int aux=a.e[i];
				a.e[i]=a.e[j];
				a.e[j]=aux;
			}
			if(b.e[i]>b.e[j])
			{
				int aux=b.e[i];
				b.e[i]=b.e[j];
				b.e[j]=aux;
			}
		}
	for(int i=0;i<a.n;i++)
		if(a.e[i]!=b.e[i])
			return 1;
	return 0;
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
		cout<<"1.Operatorul '!' returneaza nr. de elemente al primei multimi."<<endl;
		cout<<"2.Operatorul '<=' pt. a verifica daca prima multime este inclusa in a doua multime."<<endl;
		cout<<"3.Operatorul '<' pt. a verifica daca prima multime este strict inclusa in a doua multime."<<endl;
		cout<<"4.Operatorul '>=' pt. a verifica daca prima multime o contine pe a doua multime."<<endl; 
		cout<<"5.Operatorul '>' pt. a verifica daca prima multime o contine strict pe a doua multime."<<endl;
		cout<<"6.Operatorul '<' pt. a verifica daca un element apartine primei multimi."<<endl;
		cout<<"7.Operatorul '==' pt a verifica daca cele doua multimi coincid ca si continut."<<endl;
		cout<<"8.Operatorul '!=' pt a verifica daca cele doua multimi sunt diferite ca si continut."<<endl; 
		cout<<"Esc - parasire program!"<<endl;

		optiune=getch();
		spati();
		switch(optiune)
		{
			case '1':
				cout<<"Nr. de elemente al primei multimi este: "<<!a;
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '2':
				if(a<=b)
					cout<<"Prima multime este inclusa in a doua multime.";
				else
					cout<<"Prima multime nu este inclusa in a doua multime.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '3':
				if(a<b)
					cout<<"Prima multime este strict inclusa in a doua multime.";
				else 
					cout<<"Prima multime nu este strict inclusa in a doua multime.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '4':
				if(a>=b)
					cout<<"Prima multime o contine pe a doua multime.";
				else
					cout<<"Prima multime nu o contine pe a doua multime.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '5':
				if(a>b)
					cout<<"Prima multime o contine scrict pe a doua multime.";
				else
					cout<<"Prima multime nu o contine strict pe a doua multime.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '6':
				int x;
				
				cout<<"Introduceti un element ce doriti sa aflati daca exista in prima multime: ";
				cin>>x;
				if(a<x)
					cout<<endl<<"Elementul apartine primei multimi.";
				else
					cout<<endl<<"Elementul nu apartine primei multimi.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '7':
				if(a==b)
					cout<<"Cele doua multimi coincid ca si continut.";
				else
					cout<<"Cele doua multimi nu coincid ca si continut.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case '8':
				if(a!=b)
					cout<<"Cele doua multimi nu coincid ca si continut.";
				else
					cout<<"Cele doua multimi coincid ca si continut.";
				spati();
				cout<<"Apasati orice tasta...";
				break;
			case 27:
				cout<<"Apasati orice tasta pentru a parasi programul!";
				break;
			default:
				cout<<"Apasati 1,2,3,4,5,6,7,8 sau Esc!!!";
		}
		getch();
	}
	while(optiune!=27);

	return 0;
}