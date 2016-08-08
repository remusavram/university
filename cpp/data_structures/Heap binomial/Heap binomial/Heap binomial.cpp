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

struct Binomial
{
	int cheie,grad;
	struct Binomial *frate,*fiu,*parinte;
};

//===================== Creaza Heap Binomial ==========================

Binomial* Creaza_heap_binomial()
{
	Binomial *H;
	H=NULL;
	return H;
}

Binomial* H=Creaza_heap_binomial();
Binomial* Hr=Creaza_heap_binomial();
int count=1;

//===================== Creaza nod ==========================

Binomial* Creaza_nod(int k)
{
	Binomial* p=new Binomial;
    p->cheie=k;
    return p;
}

//===================== Interclasarea a 2 Heap-uri ==========================

Binomial* Interclaseaza_heap_binomial(Binomial *&H1, Binomial *&H2)
{
	Binomial *H=Creaza_heap_binomial();
	Binomial *y,*z,*a,*b;
    
    y=H1;
    z=H2;
    if(y!=NULL)
    {
		if(z!=NULL&&y->grad<=z->grad)
			 H=y;
		else if(z!=NULL&&y->grad>z->grad)
			 H=z; 
			else
				H=y;
    }
    else
		H=z;
    while(y!=NULL&&z!=NULL)
    {
		if(y->grad<z->grad)
	    {
			y=y->frate;
	    }
		else 
			if(y->grad==z->grad)
			{
			a=y->frate;
			y->frate=z;
			y=a;
			}
			else
			{
				 b=z->frate;
				 z->frate=y;
				 z=b;
			}	  
	 } 

    return H;    
  }

//============================= Legatura ==================================

void Binomial_legatura(Binomial *&y, Binomial *&z)
{
	y->parinte=z;
	y->frate=z->fiu;
	z->fiu=y;
	z->grad=z->grad+1;
}

//================================= Reunire ======================================

Binomial* heap_binomial_reuneste(Binomial *H1, Binomial *H2)
{
	Binomial *x,*prec_x,*urm_x;
	Binomial *H=Creaza_heap_binomial();

	H=Interclaseaza_heap_binomial(H1,H2);
	if(H==NULL)
		return H;
	
	prec_x=NULL;
	x=H;
	urm_x=x->frate;
	while(urm_x!=NULL)
	{
		if((x->grad!=urm_x->grad) || (urm_x->frate!=NULL) && (urm_x->frate->grad==x->grad))
		{
			prec_x=x;
			x=urm_x;
		}
		else
		{
			if(x->cheie<=urm_x->cheie)
			{
				x->frate=urm_x->frate;
				Binomial_legatura(urm_x,x);
			}
			else
			{
				if(prec_x==NULL)
					H=urm_x;
				else
					prec_x->frate=urm_x;
				Binomial_legatura(x,urm_x);
				x=urm_x;
			}
		}
		urm_x=x->frate;
	}
	return H;
}

//============================== Afisare ==============================

int Afisare(Binomial* H)
  { 
    if(H==NULL)
      {
      cout<<endl<<"Heap vid!!!";
      return 0;
      }
    cout<<endl<<"Nodurile radacina sunt: ";
    Binomial* p;
    p=H;
    while(p!=NULL)
      {
	cout<<p->cheie;
	if(p->frate!=NULL)
	  cout<<", ";
	p=p->frate;
      }
    cout<<endl;  
  }

//=============================================================================

void afisare2(Binomial *&y)
{
	if(y!=NULL)
		cout<<y->cheie<<" ";
	if(y->fiu!=NULL)
		afisare2(y->fiu);
	if(y->frate!=NULL)
		afisare2(y->frate);

}

//============================== Afisare noduri ==============================

int Afisare_noduri(Binomial* H)
  { 
	  Binomial* x,*y;
	  int i=1;
	  x=H;

    if(H==NULL)
      {
      cout<<endl<<"Heap vid!!!";
      return 0;
      }
	cout<<"Elementele sunt: "<<endl<<endl;
	 while(x!=NULL)
	 {
		 cout<<endl<<"Subheap-ul "<<i<<" este: "<<x->cheie<<"-->";
		 if(x->fiu!=NULL)
		 {
			 y=x->fiu;
			 afisare2(y);
		 }
		 if(x->frate!=NULL)
	  cout<<endl<<endl;
		 i++;
	x=x->frate;
	 }

}

//============================== Insert ==============================

Binomial* Insert_heap_binomial(Binomial *H, Binomial *x)
{
	Binomial *H1=Creaza_heap_binomial();

	x->parinte=NULL;
	x->fiu=NULL;
	x->frate=NULL;
	x->grad=0;
	H1=x;
	H=heap_binomial_reuneste(H,H1);

	return H;
}

//===================== reveniti lista =====================

void Reveniti_lista(Binomial* y)
{
    if(y->frate!=NULL)
    {
		Reveniti_lista(y->frate);
		y->frate->frate=y;
    }
    else
		Hr=y;
 }

//===================== Heap Binomial Extract Minim =====================

Binomial* Heap_binomial_extract_minim(Binomial *H1)
{
	Hr=NULL;
    Binomial* t=NULL, *x=H1, *p=x;
    if(x==NULL)
      {
      cout<<endl<<"Nu avem nimic de extras!!!"<<endl;
      return x; 
      }   
    int min=x->cheie;
    while(p->frate!=NULL)
      {
	if((p->frate)->cheie<min)
	  {
	    min=(p->frate)->cheie;
	    t=p;
	    x=p->frate;
	  }
	p=p->frate;  
      }
    if(t==NULL&&x->frate==NULL)
      H1=NULL;
    else if(t==NULL)
      H1=x->frate;
    else if(t->frate==NULL)
      t=NULL;
    else
      t->frate=x->frate;
    if(x->fiu!=NULL)
      {
	Reveniti_lista(x->fiu);
	(x->fiu)->frate=NULL;
      }
    H=heap_binomial_reuneste(H1,Hr);
    return x;
}

//========================== gaseste nod ==========================

Binomial* Gaseste_nod(Binomial* H,int k)
  { 
    Binomial* x=H, *p=NULL;
    if(x->cheie==k)
    {
		p=x;
		return p;
    }
    if(x->fiu!=NULL&&p==NULL)
		p=Gaseste_nod(x->fiu,k);
    if(x->frate!=NULL&&p==NULL)
      p=Gaseste_nod(x->frate,k);

    return p; 
  }

//========================== Descreste cheie ==========================

int Heap_binomial_descreste_cheie(Binomial *H,int i,int k)
{
	int temp;
    Binomial *p,*y,*z;

    p=Gaseste_nod(H,i);
    if(p==NULL)
      {
	cout<<endl<<"Nu s-a gasit nodul!!!"<<endl;
	return 0;
      }
    if(k>p->cheie)
      {
      cout<<endl<<"Eroare!!!!!Noua cheie este mai mare decat precedenta!!!";
      return 0;
      }
    p->cheie=k;
    y=p;
    z=p->parinte;
    while(z!=NULL&&y->cheie<z->cheie)
      {
	temp=y->cheie;
	y->cheie=z->cheie;
	z->cheie=temp;
	y=z;
	z=z->parinte;
      }
    cout<<endl<<"Cheia a fost decrementata cu succes!!!";  
}

//=================== Stergere Heap Binomial =====================

int Heap_binomial_stergere(Binomial *&H,int k)
{
	Binomial *np;

    if(H==NULL)
      {
      cout<<endl<<"Heap binomial vid!!!!!";
      return 0;
      }
    Heap_binomial_descreste_cheie(H,k,-1000);
    np=Heap_binomial_extract_minim(H);
    if(np!=NULL)
    cout<<endl<<"Nodul a fost sters cu succes!!!";
}

//=================== Main ======================

void main()
{
	Binomial *p;
	int n,m,l;
	char ch,c;
	
	cout<<"Introduceti numarul de elemente: ";
    cin>>n; 
	if(n>0)
	{
		cout<<endl<<"Elementele sunt: "<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<"elementul "<<i<<": ";
			cin>>m;
			Binomial* np=Creaza_nod(m);
			H=Insert_heap_binomial(H,np);
		}
	}
	cout<<endl;
    Afisare(H);
	Afisare_noduri(H);
	spati();

	do
    {
		cout<<"1. Insereaza nod."<<endl;
		cout<<"2. Extragere nodului cu cheie minima."<<endl;
		cout<<"3. Decrementarea cheii unui nod."<<endl;
		cout<<"4. Stergere nod."<<endl;
		cout<<"ESC - Parasire program!"<<endl;

		c=getch();
		spati();
		switch(c)
		{
			case '1':
				cout<<"Elementul ce doriti sa il inserati este: ";
				cin>>m;
				p=Creaza_nod(m);
				H=Insert_heap_binomial(H,p);
				Afisare(H);
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '2':
				cout<<endl<<"Extragere nod cu cheie minima!!";
				p=Heap_binomial_extract_minim(H);
				if(p!=NULL)
					cout<<endl<<"Nodul ce doriti sa il extrageti este: "<<p->cheie;
		 		Afisare(H);
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '3':
				cout<<endl<<"Introduceti cheia nodului ce va fi decrementata: ";
				cin>>m;
				cout<<endl<<"Introduceti noua valuare: ";
				cin>>l;
				Heap_binomial_descreste_cheie(H,m,l);
				Afisare(H);
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '4':
				cout<<"\nIntroduceti cheia nodului ce se va sterge: ";
				cin>>m;
				Heap_binomial_stergere(H,m);
				Afisare(H);
				spati();
				cout<<"Apasati orice tasta...";
				break;

		  case 27:
				spati();
				spati();
				spati();
				spati();
				cout<<"Apasati orice tasta pentru a iesi din program!"<<endl;
				break;

			default:
				cout<<"Apasati 1,2,3,4 sau Esc!"<<endl;
		}
		getch();
		spati();
	}
	while(c!=27);
}

