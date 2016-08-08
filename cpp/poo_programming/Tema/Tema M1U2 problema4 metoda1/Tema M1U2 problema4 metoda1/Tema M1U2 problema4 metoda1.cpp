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
}*cap;

typedef struct stiva stiva;



int introduce(char c)
{
	struct stiva *p;
	p=new stiva();
	p->info=c;
	p->urm=cap;
	cap=p;

	return 1;
}



int scoate()
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
		delete p;
		cout<<"Am scos din stiva "<<c;
	}
return 1;
}


void afisare()
{
	stiva *p;

	if(cap==NULL)
		cout<<"Stiva este goala!";
	else
	{
		cout<<"Stiva contine elementele: ";
		p=cap;
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->urm;
		}
	}
}



void golirestiva()
{
	stiva *p;

		while(cap!=NULL)
		{
			p=cap;
			cap=cap->urm;
			delete p;
		}
}



int _tmain(int argc, _TCHAR* argv[])
{
	char c,inf,optiune;
	cap=NULL;
	
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
			introduce(c);
			cout<<endl<<"Ati introdus in stiva "<<c;
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case '2':
			spati();
			scoate();
			spati();
			cout<<"Apasati o tasta pentru a continua.";
			spati();
			break;

		case '3':
			spati();
			afisare();
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
			golirestiva();
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
	golirestiva();

	return 0;
}

