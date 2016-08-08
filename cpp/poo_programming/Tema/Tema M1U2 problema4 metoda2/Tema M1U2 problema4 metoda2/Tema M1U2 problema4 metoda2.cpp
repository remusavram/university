#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl;
}



struct stiva
{
	char info;
	struct stiva *urm;
};

typedef struct stiva stiva;



int introduce(stiva *&cap, char c)
{
	struct stiva *p;
	p=new stiva();
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



stiva* scoate(stiva *cap)
{
	struct stiva *p;
	char c;

	if(cap==NULL)
	{
		cout<<"Stiva este goala!";
		return 0;
	}
	else
	{
		p=cap;
		cap=cap->urm;
		c=p->info;
		cout<<"Am scos din stiva: "<<c;
	}
return cap;
}


void afisare(stiva *cap)
{
	stiva *p;

	if(cap==NULL)
		cout<<"Stiva este goala!";
	else
	{
		cout<<"Stiva contine caracterele: ";
		p=cap;
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->urm;
		}
	}
}



stiva* golirestiva(stiva *cap)
{
	stiva *p;

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
	stiva *cap=NULL;
	
	do
	{
		cout<<"1.Introduceti un element in stiva."<<endl;
		cout<<"2.Scoateti un element din stiva."<<endl;
		cout<<"3.Afisati continutul stivei."<<endl;
		cout<<"4.Goliti stiva."<<endl;
		cout<<"Esc - iesire din program."<<endl;

		optiune=getch();

		switch(optiune)
		{

		case '1':
			spati();
			cout<<"Tastati caracterul ce doriti sa il introduceti in stiva: ";
			cin>>c;
			introduce(cap,c);
			cout<<endl<<"Ati introdus in stiva: "<<c;
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
				cout<<"Stiva este goala!";
			else
			{
			cap=golirestiva(cap);
			cout<<"Ati golit stiva!";
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
	golirestiva(cap);

	return 0;
}

