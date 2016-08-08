#include "stdafx.h"
#include<iostream>
#include <conio.h>

using namespace std;

//================= Spati =================

void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl;
}

//============== Structura AVL ==============

struct AVL{
	int key, h;					// key - infornatia, h - inaltimea	
	struct AVL *ls,*ld;			// ls - fiul stang, ld - fiul drept, p - parintele
};

//================ Drumul Maxim ================

void drum_maxim(AVL *x, int &max, int lung)
{
	if (x!=NULL)
	{
		drum_maxim(x->ld,max,lung+1);
		if ((x->ls==NULL)&&(x->ld==NULL)&&(max<lung))
		max=lung;
		drum_maxim(x->ls,max,lung+1);
	}
}

//==== Calcularea factorului de echilibru unui subarbore ====

void calcul_factor_echilibru(AVL *x)
{
	int hLeft=1, hRight=1;

	if(x->ls!=NULL)
		drum_maxim(x->ls,hLeft,1);
	else
		hLeft=0;
	if(x->ld!=NULL)
		drum_maxim(x->ld,hRight,1);
	else
		hRight=0;
	x->h=hRight-hLeft;
}

//============ Rotatie simpla dreapta ============

AVL* rotatie_simpla_dreapta(AVL *x)
{
	AVL *y;

	y=x->ls;
	x->ls=y->ld;
	y->ld=x;
	calcul_factor_echilibru(x);
	calcul_factor_echilibru(y);
	x=y;
	return x;
}

//============ Rotatie simpla stanga ============

AVL* rotatie_simpla_stanga(AVL *x)
{
	AVL *y;

	y=x->ld;
	x->ld=y->ls;
	y->ls=x;
	calcul_factor_echilibru(x);
	calcul_factor_echilibru(y);
	x=y;
	return x;
}

//============ Rotatie dubla dreapta ============

AVL* rotatie_dubla_dreapta(AVL *x)
{
	x->ls=rotatie_simpla_stanga(x->ls);
	x=rotatie_simpla_dreapta(x);
	return(x);
}

//============ Rotatie dubla stanga ============

AVL* rotatie_dubla_stanga(AVL *x)
{
	x->ld=rotatie_simpla_dreapta(x->ld);
	x=rotatie_simpla_stanga(x);
	return(x);
}

//================ Echilibrare ================

AVL* echilibrare(AVL *x)
{
	AVL *w;
	calcul_factor_echilibru(x);
	if(x->h==-2)
	{
		w=x->ls; 
		if (w->h==1)
			x=rotatie_dubla_dreapta(x);
		else
			x=rotatie_simpla_dreapta(x);
	}
	else
		if(x->h==2)
		{
			w=x->ld;
		if (w->h==-1)
			x=rotatie_dubla_stanga(x);
		else
			x=rotatie_simpla_stanga(x);
		}
	return x;
}

//================= Insert_AVL =================

AVL* insert_AVL(AVL *&x, int k, int &verificare)
{
	verificare=0;
	if(x==NULL)
	{
		x= new AVL();
		x->key=k;
		x->ls=NULL;
		x->ld=NULL;
		x->h=0;
		return x;
	}
	else
	{
		if(k<x->key)
			x->ls=insert_AVL(x->ls,k,verificare);
		else
			if(k>x->key)
				x->ld=insert_AVL(x->ld,k,verificare);
			else
			{
				cout<<endl<<"Nodul cu informatia "<<k<<" exista deja!"<<endl;
				verificare=1;
			}
	}
	x=echilibrare(x);
}

//======================= Stergere AVL =======================

AVL* stergere(AVL *x,int k)
{
	AVL *q,*r,*w;
	if (x!=NULL)									// daca nodul curent este diferit de NULL
		if (k<x->key)								//cheia care se doreste stearsa este mai mica decat informatia din nod
			x->ls = stergere(x->ls,k);				// se cauta cheia de sters in subarborele stang al	nodului curent
		else
			if (k>x->key)							// daca cheia este mai mare
				x->ld = stergere(x->ld,k);			// se cauta in subarborele drept
			else
			{										//daca cheia este egala cu informatia din nodul curent
				q=x;								//un nod q devine x
				if (q->ld==NULL)					// daca copilul drept al lui q eate NULL
					x=q->ls;						// atunci x devine q->stanga
				else
					if (q->ls==NULL)				//altfel daca copilul stang al lui q este NULL
						x=q->ld;					// x devine q->dreapta
					else
					{
						w=q->ls;					//altfel w este copilul stanga al lui q
						r=q;						// r devine q
						if (w->ld!=NULL)			// daca copilul drept al lui w nun este NULL
						{
							while (w->ld!=NULL)
							{
								r=w;
								w=w->ld;
							}
							x->key=w->key;
							q=w;
							r->ld=w->ls;
							r=x->ls;
							w=w->ls;
							if (r!=NULL)
								while ((r!=w)&&(r!=NULL))
								{
									r = echilibrare(r);
									r=r->ld;
								}
						}
						else
						{
							x->key=w->key;
							x->ls=w->ls;
							q=w;
						}
					}
					delete(q);						// se sterge q
			}
	if (x!=NULL)
	x = echilibrare(x);								// se echilibreaza x daca nu este NULL
	return x;
}

//==================== Inordine ==================================

void inordine(AVL *T)
{
	if(T)
	{		
		inordine(T->ls);
		cout<<T->key<<" ";
		inordine(T->ld);
	}
}

//==================== Preordine ================================

void preordine(AVL *T)
{
	if(T)
	{
		cout<<T->key<<" ";
		preordine(T->ls);
		preordine(T->ld);
	}
}

//================= Nr. elemente =================

void nr_elemente(AVL *T, int &k)
{
	if(T!=NULL)
	{
		k++;
		if(T->ls!=NULL)
			nr_elemente(T->ls,k);
		if(T->ld!=NULL)
			nr_elemente(T->ld,k);
	}
}

//======================= MAIN =======================

void main()
{
	AVL *rad=NULL, *nod, *x, *y;
	int n, i, *v, c, k, max=0, verificare=0, nr_elem=0, temp=0;

	cout<<"Introduceti numarul de noduri al arborelui: ";
	cin>>n;

	v=new int[n];

	for(i=0;i<n;i++)
	{
		cout<<"v["<<i+1<<"]=";
		cin>>v[i];
		insert_AVL(rad,v[i],verificare);
	}

	cout<<endl<<endl;

	do
	{
		cout<<"1. Insereaza un nod in arborele AVL."<<endl;
		cout<<"2. Aflarea inaltimi arborelui."<<endl;
		cout<<"3. Afisarea arborelui AVL."<<endl;
		cout<<"4. Sortarea in ordine crescatoare a arborelui AVL."<<endl;
		cout<<"5. Stergerea unui nod in arborele AVL."<<endl;
		cout<<"ESC - Parasire program!"<<endl;

		c=getch();
		spati();

		switch(c)
		{
			case'1':
				cout<<"Introduceti numarul ce doriti sa il inserati in arbore: ";
				cin>>k;
				insert_AVL(rad,k,verificare);
				if(verificare==0)
					cout<<endl<<"Am introdus in arborele binar numarul: "<<k;;
				spati();
				cout<<"Apasati orice tasta...";
				break;
				
			case '2':
				drum_maxim(rad,max,2);
				cout<<"Inaltimea arborelui dat este: "<<max;
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '3':
				cout<<"Arborele AVL introdus este: ";
				preordine(rad);
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '4':
				cout<<"Arborele AVL sortat in ordine crescatoare este: ";
				inordine(rad);
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '5':
				cout<<"Introduceti cheia nodului ce doriti sa o stergeti: ";
				cin>>k;
				nr_elemente(rad,nr_elem);
				temp=nr_elem;
				nr_elem=0;
				rad=stergere(rad,k);
				nr_elemente(rad,nr_elem);
				if(temp==nr_elem)
					cout<<"Nodul cu cheia "<<k<<" nu a putut fi sters!"<<endl;
				else
					cout<<"Nodul cu cheia "<<k<<" a fost sters!"<<endl;
				nr_elem=0;
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case 27:
				spati();
				cout<<"Apasati orice tasta pentru a iesi din program!"<<endl;
				break;

			default:
				spati();
				cout<<"Apasati 1,2 sau Esc!"<<endl;
		}
		getch();
		spati();
	}
	while(c!=27);
}

