#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
}



struct coada
{
	char info;
	struct coada *urm;
};

typedef struct coada coada;



int introduce(coada *&cap, char c)
{
	struct coada *p;
	p=new coada();
	p->info=c;
	if(cap==NULL)
		cap=p;
	else
	{
		p->urm=cap;
		cap=p;
	}

	return 1;
}



coada* scoate(coada *cap)
{
	struct coada *p;
	char c;
	p=cap;

	if(cap==NULL)
		cout<<"Coada este goala!";
	
	else
		if(p->urm==NULL)
		{
			c=p->info;
			cout<<"Am scos din coada: "<<c;
			cap=NULL;
		}
		else
		{
			while(p->urm->urm!=NULL)
			{
				p=p->urm;
			}
			c=p->urm->info;
			cout<<"Am scos din coada: "<<c;
			p->urm=NULL;
		}
return cap;
}


void afisare(coada *cap)
{
	coada *p;

	if(cap==NULL)
		cout<<"Coada este goala!";
	else
	{
		cout<<"Coada contine caracterele: ";
		p=cap;
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->urm;
		}
	}
}



coada* golire(coada *cap)
{
	coada *p;

		while(cap!=NULL)
		{
			p=cap;
			cap=cap->urm;
			delete p;
		}
	return cap;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char c,inf,optiune;
	coada *cap=NULL;
	
	do
	{
		cout<<"1.Introduceti un element in coada."<<endl;
		cout<<"2.Scoateti un element din coada."<<endl;
		cout<<"3.Afisati continutul scoadei."<<endl;
		cout<<"4.Goliti coada."<<endl;
		cout<<"Esc - iesire din program."<<endl;

		optiune=getch();

		switch(optiune)
		{

		case '1':
			spati();
			cout<<"Tastati caracterul ce doriti sa il introduceti in coada: ";
			cin>>c;
			introduce(cap,c);
			cout<<endl<<"Ati introdus in coada: "<<c;
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case '2':
			spati();
			cap=scoate(cap);
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case '3':
			spati();
			afisare(cap);
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case '4':
			spati();
			if(cap==NULL)
				cout<<"Coada este goala!";
			else
			{
			cap=golire(cap);
			cout<<"Ati golit coada!";
			}
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case 27:
			spati();
			cout<<"Apasati o tasta pentru a iesi din program!";
			spati();
			break;

		default:
			spati();
			cout<<"Apasati 1,2,3,4 sau Esc!";
			spati();
		}
		getch();
	}
	while(optiune!=27);
	golire(cap);

	return 0;
}

