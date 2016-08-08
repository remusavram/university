#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;



struct arbore
{
	int key;
	struct arbore *ls,*ld,*p;
};

typedef struct arbore arbore;



void inordine(arbore *T)
{
	if(T)
	{		
		inordine(T->ls);
		cout<<T->key<<" ";
		inordine(T->ld);
	}
}



void preordine(arbore *T)
{
	if(T)
	{
		cout<<T->key<<" ";
		preordine(T->ls);
		preordine(T->ld);
	}
}



void postordine(arbore *T)
{
	if(T)
	{
		postordine(T->ls);
		postordine(T->ld);
		cout<<T->key<<" ";
		
	}
}



void insereaza_stanga(arbore *q)
{
	struct arbore *y;
	int nrs;

	cout<<"Introduceti stanga lui "<<q->key<<" : ";
	cin>>nrs;

	if(nrs!=0)
	{
		y=new arbore();
		y->p=q;
		q->ls=y;
		y->key=nrs;
		y->ls=NULL;
		y->ld=NULL;

		insereaza_stanga(q->ls);
		insereaza_dreapta(q->ls);
	}
	

}



void insereaza_dreapta(arbore *q)
{
	struct arbore *z;
	int nrd;

	cout<<"Introduceti dreapta lui "<<q->key<<" : ";
	cin>>nrd;

	if(nrd!=0)
	{
		z=new arbore();
		z->p=q;
		q->ld=z;
		z->key=nrd;
		z->ld=NULL;
		z->ls=NULL;
		
		insereaza_stanga(q->ld);
		insereaza_dreapta(q->ld);		
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	struct arbore *rad=NULL;
	arbore *q;

	cout<<"Introduceti un arbore binar de la tastatura. Se afiseza pe ecran parcurgerile (RSD, SRD, SDR)."<<endl<<endl;
	rad=new arbore();

	cout<<"Introduceti radacina: ";
	cin>>rad->key;

	if(rad->key==0)
		cout<<"Nu avem arbore!";
	else
	{
		rad->ls=NULL;
		rad->ld=NULL;
		rad->p=NULL;
		q=rad;
		insereaza_stanga(q);
		insereaza_dreapta(q);

	cout<<endl<<"Preordine (RSD): ";
	preordine(rad);

	cout<<endl<<"Inordine (SRD): ";
	inordine(rad);

	cout<<endl<<"Postordine (SDR): ";
	postordine(rad);
	}

	getch();
	return 0;
}

