#include "stdafx.h"
#include<iostream>
#include <conio.h>

using namespace std;



void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl;
}



struct arb{
	int key;
	struct arb *ls,*ld,*p;
};



void insert(arb *&T, arb *x)
{
	arb *y, *z;
	y=NULL;
	z=T;

	while (z!=NULL)
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
		else y->ld=x;

}



arb* cautbinar(arb *T,int k)
{
	arb *x;
	x=T;

	while (x && (x->key!=k))
		if (k<x->key)
			x=x->ls;
		else x=x->ld;

	return x;
}



arb* minim(arb *T)
{
	arb *x;
	x=T;

	while(x->ls!=NULL)
		x=x->ls;

	return x;
}



arb* succesor(arb *x)
{
	arb *y;

	if(x->ld!=NULL)
	{
		x=x->ld;
		y=minim(x);
		return y;
	}
	
	y=x->p;
	while(y!=NULL && x==y->ld)
	{
		x=y;
		y=y->p;
	}
	return y;

}



void inordine(arb *T)
{
	if(T)
	{		
		inordine(T->ls);
		cout<<T->key<<" ";
		inordine(T->ld);
	}
}



void preordine(arb *T)
{
	if(T)
	{
		cout<<T->key<<" ";
		preordine(T->ls);
		preordine(T->ld);
	}
}



void sterge_nod(arb *T,arb *z)
{
	arb *y,*x;

	if((z->ls==NULL) || (z->ld==NULL))
		y=z;
	else
		y=succesor(z);
	if(y->ls!=NULL)
		x=y->ls;
	else
		x=y->ld;
	if(x!=NULL)
		x->p=y->p;
	if(y->p==NULL)
		T=x;
	else
		if(y==y->p->ls)
			y->p->ls=x;
		else
			y->p->ld=x;
	if(z->key<y->key)
		z->key=y->key;
}



void rotatie_stanga(arb *T, arb *x)
{
	arb *y;

	y=x->ld;
	x->ld=y->ls;
	if(y->ls!=NULL)
		y->ls->p=x;
	y->ls=x;
	y->p=x->p;
	if(x->p==NULL)
		T=y;
	else
		if(x==x->p->ls)
			x->p->ls=y;
		else
			x->p->ld=y;
	x->p=y;
}



void rotatie_dreapta(arb *T, arb *x)
{
	arb *y;

	y=x->ls;
	x->ls=y->ld;
	if(y->ld!=NULL)
		y->ld->p=x;
	y->ld=x;
	y->p=x->p;
	if(x->p==NULL)
		T=y;
	else
		if(x==x->p->ls)
			x->p->ls=y;
		else
			x->p->ld=y;
	x->p=y;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,*v,k,c;

	arb *rad=NULL;
	arb *nod;
	arb *x;
	arb *y;

	cout<<"Introduceti numarul de noduri al arborelui: ";
	cin>>n;

	v=new int[n];

	for(i=0;i<n;i++)
	{
		cout<<"v["<<i+1<<"]=";
		cin>>v[i];
		nod = new arb();
		nod->key=v[i];
		nod->ls=NULL;
		nod->ld=NULL;
		nod->p=NULL;
		insert(rad,nod);
	}

	cout<<endl<<endl;

	do
	{
		cout<<"1. Cauta un numar in arborele binar de cautare."<<endl;
		cout<<"2. Cauta valoarea minima in arborele binar de cautare."<<endl;
		cout<<"3. Cauta succesorul unui numar in arborele binar de cautare."<<endl;
		cout<<"4. Insereaza un nod in arborele binar de cautare."<<endl;
		cout<<"5. Afisarea arborelui binar de cautare."<<endl;
		cout<<"6. Sortarea in ordine crescatoare a arborelui binar de cautare."<<endl;
		cout<<"7. Stergerea unui nod din arborele binar de cautare."<<endl;
		cout<<"8. Rotatie la stanga in jurul unui nod intr-un arbore binar de cautare."<<endl;
		cout<<"9. Rotatie la dreapta in jurul unui nod intr-un arbore binar de cautare."<<endl;
		cout<<"ESC - Parasire program!"<<endl;

		c=getch();

		switch(c)
		{
			case'1':
				spati();
				cout<<"Introduceti numarul ce il cautati: ";
				cin>>k;
				x=cautbinar(rad,k);
				if(x!=NULL)
					cout<<endl<<"Numarul "<<k<<" exista in arbore."<<endl;
				else
					cout<<endl<<"Numarul "<<k<<" nu exista in arbore."<<endl;
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'2':
				spati();
				if(rad!=NULL)
				{
					x=minim(rad);
					cout<<"Valoarea minima a arborelui este: "<<x->key<<endl;
				}
				else
					cout<<"Arborele nu contine nici un element!";
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'3':
				spati();
				cout<<"Introduceti numarul ce doriti sa ii aflati succesorul: ";
				cin>>k;
				x=cautbinar(rad,k);
				if(x==NULL)
					cout<<endl<<"Numarul ce doriti sa ii cautati succesorul nu exista in arbore!!!"<<endl;
				else
				{
					y=succesor(x);
					if(y==NULL)
						cout<<"Nu exista succesorul lui "<<x->key<<" in arbore!"<<endl;
					else
						cout<<"Succesorul lui "<<x->key<<" este "<<y->key<<endl;
				}
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'4':
				spati();
				cout<<"Introduceti numarul ce doriti sa il inserati in arbore: ";
				cin>>k;
				nod = new arb();
				nod->key=k;
				nod->ls=NULL;
				nod->ld=NULL;
				nod->p=NULL;
				insert(rad,nod);
				cout<<endl<<"Am introdus in arborele binar numarul: "<<k;
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'5':
				spati();
				cout<<"Arborele binar de cautare introdus este: ";
				preordine(rad);
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'6':
				spati();
				cout<<"Arborele binar de cautare sortat in ordine crescatoare este: ";
				inordine(rad);
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'7':
				spati();
				cout<<"Introduceti numarul ce doriti sa il stergeti: ";
				cin>>k;
				x=cautbinar(rad,k);
				if(x==NULL)
					cout<<endl<<"Numarul ce doriti sa il stergeti nu exista in arbore!!!"<<endl;
				else
				{
					sterge_nod(rad,x);
					cout<<"Am sters numarul :"<<k;
				}
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'8':
				spati();
				cout<<"Introduceti numarul ce doriti sa faceti rotatie la stanga: ";
				cin>>k;
				x=cautbinar(rad,k);
				if(x==NULL)
					cout<<endl<<"Numarul in jurul caruia doriti sa faceti rotatie la stanga nu exista in arbore!"<<endl;
				else
					if(x->ld==NULL)
						cout<<"Nu avem un nod drept pentru a face rotatie la dreapta!"<<endl;
					else
					{
						rotatie_stanga(rad,x);
						cout<<endl<<"Am facut rotatie la stanga in jurul lui "<<k;
					}
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case'9':
				spati();
				cout<<"Introduceti numarul ce doriti sa faceti rotatie la dreapta: ";
				cin>>k;
				x=cautbinar(rad,k);
				if(x==NULL)
					cout<<endl<<"Numarul in jurul caruia doriti sa faceti rotatie la dreapta nu exista in arbore!"<<endl;
				else
					if(x->ls==NULL)
						cout<<"Nu avem un nod stang pentru a face rotatie la dreapta!"<<endl;
					else
					{
						rotatie_dreapta(rad,x);
						cout<<endl<<"Am facut rotatie la dreapta in jurul lui "<<k;
					}
				spati();
				cout<<"Apasati orice tasta...";
				spati();
				break;

			case 27:
				spati();
				cout<<"Apasati orice tasta pentru a iesi din program!"<<endl;
				break;

			default:
				spati();
				cout<<"Apasati 1,2,3,4,5,6 sau Esc!"<<endl;
				spati();
		}
		getch();
	}
	while(c!=27);

	return 0;
}

