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



int insert(arbore *&T, arbore *x)
{
	struct arbore *z,*y;
	y=NULL;
	z=T;

	while(z!=NULL)
	{
		y=z;
		if(z->key>x->key)
			z=z->ls;
		else
			z=z->ld;
	}
	x->p=y;

	if(!y)
		T=x;
	else
		if(y->key>x->key)
			y->ls=x;
		else 
			y->ld=x;

	return 0;
}



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



int _tmain(int argc, _TCHAR* argv[])
{
	arbore *rad=NULL;
	arbore *nod;
	arbore *x;

	int i,n,*v;

	cout<<"Se introduce un arbore binar de cautare de la tastatura. Afiseaza pe ecran cele trei functi de parcurgere (RSD, SRD, SDR)."<<endl<<endl;

	cout<<"Dati numarul de noduri: ";
	cin>>n;

	v=new int[n];

	for(i=0;i<n;i++)
	{
		cout<<"v["<<i+1<<"]= ";
		cin>>v[i];
		nod=new arbore();
		nod->key=v[i];
		nod->ls=NULL;
		nod->ld=NULL;
		nod->p=NULL;
		insert(rad,nod);
	}

	cout<<endl<<"Preordine (RSD): ";
	preordine(rad);

	cout<<endl<<"Inordine (SRD): ";
	inordine(rad);

	cout<<endl<<"Postordine (SDR): ";
	postordine(rad);

	getch();

	return 0;
}

