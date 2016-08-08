#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;



void spati()
{
	cout<<endl<<endl<<endl<<endl;
}



struct stiva
{
	int info;
	struct stiva *leg;

}*cap;

typedef struct stiva stiva;

int adaugare(int n)
{
	struct stiva *p;
	p = new stiva();
	if(p==NULL)
		cout<<"Memorie insuficienta";
	else 
	{
		p->info=n;
		p->leg=cap;
		cap=p;
		cout<<"Am introdus: "<<n;
	}
	return 1;
}



void extragere()
{
	struct stiva *p;
	
	if(cap==NULL)
		cout<<"Stiva este goala!";
	else
	{
		p=cap;
		cap=cap->leg;
		cout<<"Am scos din stiva: "<<p->info<<endl;
		free(p);
	}
}



void afisare()
{
	struct stiva *p;
	int k=0;

	if(cap==NULL)
		cout<<"Stiva este goala!"<<endl;
	else
	{
		p=cap;

		while(p!=NULL)
		{
			p=p->leg;
			k=k+1;
		}
		if(k==1)
			cout<<"Stiva contine: "<<k<<" element"<<endl;
		else
			cout<<"Stiva contine: "<<k<<" elemente"<<endl;

		p=cap;
		if(k==1)
			cout<<"Elementul stivei este: ";
		else
			cout<<"Elementele stivei sunt: ";
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->leg;
		}
	}
}



void inserare()
{
	struct stiva *p,*q,*t;
	int x,y,k=0;

	cout<<"Introduceti elementul ce doriti sa il inserati: ";
	cin>>x;
	cout<<endl;
	cout<<"Introduceti elementul dupa care facem inserarea: ";
	cin>>y;
	cout<<endl;
	cout<<"Stiva inaintea inserarii: "<<endl;
	afisare();

	p = new stiva();
	if(p==NULL)
		cout<<"Memorie insuficineta!"<<endl;
	else
	{
		p->info=x;

		t=cap;
		while(t!=NULL)
		{
			if(t->info==y)
			{
				k=1;
				break;
			}
			t=t->leg;
		}
		if(k==0)
		{
			p->leg=cap;
			cap=p;
		}
		else
		{
			q=cap;
			while(q->leg->info!=y)
				q=q->leg;
			p->leg=q->leg;
			q->leg=p;
		}

	}
	cout<<endl<<endl<<"Stiva dupa inserare: "<<endl;
	afisare();
}



void extragere2()
{
	struct stiva *p,*q;
	int x,k=0;

	cout<<"Introduceti elementul ce doriti sa il extrageti: ";
	cin>>x;

	p=cap;
	while(p!=NULL)
	{
		if(p->info==x)
		{
			k=1;
			break;
		}
		p=p->leg;
	}

	if(k==0)
		cout<<endl<<"Elementul "<<x<<" nu exista in stiva!"<<endl;
	else
		if(cap->leg==NULL)
			extragere();
		else
		{
			q=cap;
			while(q->leg->info!=x)
				q=q->leg;
			p=q->leg;
			q->leg=p->leg;
			free(p);
			cout<<endl<<"Am scos din stiva "<<x<<endl;
		}	
	
}



void golirestiva()
{
	struct stiva *p;

	while(cap!=NULL)
	{
		p=cap;
		cap=cap->leg;
		free(p);
	}
	cout<<"Am golit stiva!";
}



int main()
{
	char c;
	int n,inf;
	cap=NULL;
	
	do
	{
		cout<<"1. Adaugarea unui element in stiva."<<endl;
		cout<<"2. Extragerea primului element din stiva."<<endl;
		cout<<"3. Afisarea elementelor din stiva (cate si care)."<<endl;
		cout<<"4. Inserarea unui element cu informatia x care se afla dupa elementul cu informatia y. Daca nu exista nici un element cu informatia y atunci elementul nou se plaseaza in varful stivei."<<endl;
		cout<<"5. Extragerea unui element din stiva daca el exista."<<endl;
		cout<<"6. Golire stiva."<<endl;
		cout<<"Esc - Parasirea programului!"<<endl;

		spati();

		c=getch();

		switch(c)
		{
		case'1':
			cout<<"Introduceti un numar: ";
			cin>>inf;
			adaugare(inf);
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case'2':
			extragere();
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case'3':
			afisare();
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case'4':
			inserare();
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case'5':
			extragere2();
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case'6':
			golirestiva();
			spati();
			cout<<"Apasati orice tasta..."<<endl<<endl<<endl;
			break;
		case 27:
			cout<<"Apasati orice tasta pentru a iesi din program!";
			spati();
			break;
		default:
			cout<<"Apasati 1, 2, 3 sau Esc!";
			spati();
		}
		getch();
	}
	while(c!=27);
	golirestiva();
	return 0;
}
