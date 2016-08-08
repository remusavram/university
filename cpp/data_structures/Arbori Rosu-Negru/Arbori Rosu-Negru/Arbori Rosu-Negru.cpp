#include "stdafx.h"
#include<iostream>
#include <conio.h>

using namespace std;

//========================= Spati ===============================

void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl;
}

//========================= Structura ==============================

struct R_N
{
	char culoare;
	int key;
	struct R_N *ls,*ld,*p;
};

//========================= Rotatie stanga ==============================

void Rotatie_stanga(R_N *&T, R_N *&x)
{
	R_N *y;

	y=x->ld;
	x->ld=y->ls;
	if(y->ls!=NULL)
		y->ls->p=x;
	y->p=x->p;
	if(x->p==NULL)
		T=y;
	else
		if(x==x->p->ls)
			x->p->ls=y;
		else
			x->p->ld=y;
	y->ls=x;
	x->p=y;
}

//================== Rotatie dreapta=============================

void Rotatie_dreapta(R_N *&T, R_N *x)
{
	R_N *y;

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

//==================== Inordine ==========================

void inordine(R_N *T)
{
	if(T)
	{		
		inordine(T->ls);
		cout<<T->key<<" ";
		inordine(T->ld);
	}
}

//==================== Preordine ========================

void preordine(R_N *T)
{
	if(T)
	{
		cout<<T->key<<" ";
		preordine(T->ls);
		preordine(T->ld);
	}
}

//=========================== RN Inserare ==========================

void RN_Insereaza(R_N *&T, R_N *&x)
{
	R_N *y;

	x->culoare='r';
	while((x!=T) && (x->p->culoare='r'))
	{
		if(x->p==x->p->p->ls)
		{
			y=x->p->p->ld;
			if(y->culoare='r')
			{
				x->p->culoare='n';
				y->culoare='n';
				x->p->p->culoare='r';
				x=x->p->p;
			}
			else
			{
				if(x==x->p->ld)
				{
					x=x->p;
					Rotatie_stanga(T,x->p->p);
				}
				x->p->culoare='n';
				x->p->p->culoare='r';
				Rotatie_dreapta(T,x->p->p);
			}
		}
		else
			if(x->p==x->p->p->ld)
			{
				y=x->p->p->ls;
				if(y->culoare='r')
				{
					x->p->culoare='n';
					y->culoare='n';
					x->p->p->culoare='r';
					x=x->p->p;
				}
				else
				{
					if(x==x->p->ls)
					{
						x=x->p;
						Rotatie_dreapta(T,x->p->p);
					}
					x->p->culoare='n';
					x->p->p->culoare='r';
					Rotatie_stanga(T,x->p->p);
				}
			}
	}
}

//====================== Minimul =================================

R_N* minim(R_N *T)
{
	R_N *x;
	x=T;

	while(x->ls!=NULL)
		x=x->ls;

	return x;
}

//======================== Succesorul ==============================

R_N* succesor(R_N *x)
{
	R_N *y;

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

//=========================== RN Repara ==========================

void RN_sterge_repara(R_N *&T, R_N *&x)
{
	R_N *w;

	while((x!=T) && (x->culoare=='n'))
	{
		if(x==x->p->ls)
		{
			w=x->p->ld;
			if(w->culoare=='r')
			{
				w->culoare='n';
				x->p->culoare='r';
				Rotatie_stanga(T,x->p);
			}
			if(w->ls->culoare=='n')
			{
				w->culoare='r';
				x=x->p;
			}
			else
			{
				if(w->ld->culoare=='n')
				{
					w->ls->culoare='n';
					w->culoare='r';
					Rotatie_dreapta(T,w);
					w=x->p->ld;
				}
				w->culoare=x->p->culoare;
				x->p->culoare='n';
				w->ld->culoare='n';
				Rotatie_stanga(T,x->p);
				x=T;
			}
		}
		else
			if(x==x->p->ld)
		{
			w=x->p->ls;
			if(w->culoare=='r')
			{
				w->culoare='n';
				x->p->culoare='r';
				Rotatie_dreapta(T,x->p);
			}
			if(w->ld->culoare=='n')
			{
				w->culoare='r';
				x=x->p;
			}
			else
			{
				if(w->ls->culoare=='n')
				{
					w->ld->culoare='n';
					w->culoare='r';
					Rotatie_stanga(T,w);
					w=x->p->ls;
				}
				w->culoare=x->p->culoare;
				x->p->culoare='n';
				w->ls->culoare='n';
				Rotatie_stanga(T,x->p);
				x=T;
			}
		}

	}
	x->culoare='n';
}

//=========================== RN Stergere ==========================

R_N* RN_sterge(R_N *&T, R_N *&z)
{
	R_N *y,*x;

	if((z->ls==NULL) || (z->ld==NULL))
		y=z;
	else
		y=succesor(z);
	if(y->ls!=NULL)
		x=y->ls;
	else
		x=y->ld;
	x->p=y->p;
	if(x->p==NULL)
		T=x;
	else
		if(y==y->p->ls)
			y->p->ls=x;
		else
			y->p->ld=x;
	if(y!=z)
		z->key=y->key;
	if(y->culoare=='n')
		RN_sterge_repara(T,x);
	
	return y;
}

//=========================== Main ==========================

void main()
{
	int n, i, *v, k, c;
	R_N *rad=NULL, *nod, *x, *y;

	cout<<"Introduceti numarul de noduri al arborelui: ";
	cin>>n;

	v=new int[n];

	for(i=0;i<n;i++)
	{
		cout<<"v["<<i+1<<"]=";
		cin>>v[i];
		nod = new R_N();
		nod->key=v[i];
		nod->ls=NULL;
		nod->ld=NULL;
		nod->p=NULL;
		nod->culoare='n';
		RN_Insereaza(rad,nod);
	}
	getch();
}

