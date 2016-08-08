#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

struct arb
{
	arb *ls, *ld, *p;
	int key, n;
};

struct coada
{
	arb* info;
	struct coada *urm,*prim, *ultim;
};

typedef struct coada coada;



void introduce(coada *&ultim, coada *&prim, arb* c)
{
	struct coada *p;
	p=new coada();
	p->info=c;
	if(prim==NULL)
	{
		prim=p;
		ultim=p;
	}
	else
	{
		ultim->urm=p;
		ultim=p;
	}
}



arb *scoate(coada *&prim, coada *&ultim)
{
	struct coada *p;
	p=prim;
	if(p==NULL)
	{
		cout<<"Coada este goala!";
		return NULL;
	}
	else{
		arb *nod=p->info;
	
		if(p->urm==NULL)
		{
			prim=NULL;
			ultim=NULL;
		}
		else
			prim=p->urm;

	delete p;
	return nod;}
	
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



void postordine(arb *T)
{
	if(T)
	{
		postordine(T->ls);
		postordine(T->ld);
		cout<<T->key<<" ";
		
	}
}

void nivel(arb *T, int k)
{
	if(T)
	{
		nivel(T->ls,k);
		nivel(T->ld,k);
		if(T->n==k)
		cout<<T->key<<" ";
		
	}
}


void main()
{
	arb *rad, *nod1, *nod2;
	int k,a;
	coada *ultim=NULL, *prim=NULL;

	cout<<"Introduceti radacina: ";
	cin>>k;
	rad= new arb();
	rad->key=k;
	rad->ls=NULL;
	rad->ld=NULL;
	rad->p=NULL;
	rad->n=0;
	introduce(ultim,prim,rad);

		while (prim!=0)
		{
			nod1=scoate(prim,ultim);
			cout<<"Exista nod stang al nodului "<<nod1->key<<"? 1/0";
			cin>>a;
			if((a==1))
			{
				cout<<"Introduceti nodul stang al nodului "<<nod1->key<<" : ";
				cin>>k;
				nod2= new arb();
				nod2->key=k;
				nod2->ls=NULL;
				nod2->ld=NULL;
				nod2->p=nod1;
				nod1->ls=nod2;
				nod2->n=nod1->n+1;
				introduce(ultim,prim,nod2);
			}
			cout<<"Exista nod drept al nodului "<<nod1->key<<"? 1/0";
			cin>>a;
			if((a==1))
			{
				cout<<"Introduceti nodul drept al nodului "<<nod1->key<<" : ";
				cin>>k;
				nod2= new arb();
				nod2->key=k;
				nod2->ls=NULL;
				nod2->ld=NULL;
				nod2->p=nod1;
				nod1->ld=nod2;
				nod2->n=nod1->n+1;
				introduce(ultim,prim,nod2);
				
			}
		}
		cout<<"Afisarea arborelui in preordine este: ";
		preordine(rad);
		cout<<endl;

/*		cout<<"Introduceti nivelul ce doriti sa aflati alementele: ";
		cin>>k;
		cout<<"Elementele de pe nivelul "<<k<<" sunt: ";
		nivel(rad,k);
*/		cout<<endl;
		int nv=0;
		cout<<"Arborele afisat pe nivele este: "<<endl;

		introduce(ultim,prim,rad);
		while(prim!=NULL)
		{
			nod1=scoate(prim,ultim);
			if(nod1->n>nv)
			{
				cout<<endl;
				nv++;
			}
			cout<<nod1->key<<" ";
			if(nod1->ls!=NULL)
				introduce(ultim,prim,nod1->ls);
			if(nod1->ld!=NULL)
				introduce(ultim,prim,nod1->ld);

		}

		getch();

}

