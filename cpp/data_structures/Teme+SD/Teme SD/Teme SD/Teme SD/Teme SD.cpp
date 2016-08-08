// 22032009.cpp : Defines the entry point for the console application.

#include "stdafx.h"

struct arb
{
	int val;
	arb *st;
	arb *dr;
};

//===============CITIRE DIN FISIER A ARBORELUI=================
void citeste(FILE *f, arb* &r)
{
	if(!feof(f))
	{
		int x = 0;
		fscanf(f, "%d", &x);
		if(x != -1)
		{
			r = (arb *)malloc(sizeof(arb));
			r->val = x;
			citeste(f, r->st);
			citeste(f, r->dr);
		}
		else
		{
			r = NULL;
		}
	}
}

//===============PREORDINE=================
void preordine(arb *r)
{
	if(r != NULL)
	{
		printf("%d ", r->val);
		preordine(r->st);
		preordine(r->dr);
	}
}

//===============INORDINE=================
void inordine(arb *r)
{
	if(r != NULL)
	{
		inordine(r->st);
		printf("%d ", r->val);
		inordine(r->dr);
	}
}

//===============POSTORDINE=================
void postordine(arb *r)
{
	if(r != NULL)
	{
		postordine(r->st);
		printf("%d ", r->val);
		postordine(r->dr);
	}
}

//===============AFISARE FRUNZE=================
void frunze(arb *r)
{
	if(r != NULL)
	{
		if(r->st == NULL && r->dr == NULL)
		{
			printf("%d ", r->val);
		}
		else
		{
			frunze(r->st);
			frunze(r->dr);
		}
	}
}

//===============AFISARE INALTIME=================
void inaltime(arb *r, int &h, int level)
{
	if(r != NULL)
	{
		h = max(h, level++);
		inaltime(r->st, h, level);
		inaltime(r->dr, h, level);
	}
}

//===============AFISARE NIVEL MAXIM=================
void afisareNivel(arb *r, int show, int level)
{
	if(r!=NULL)
	{
		if(show==level)
		{
			printf("%d ", r->val);
		}
		level++;
		afisareNivel(r->st, show, level);
		afisareNivel(r->dr, show, level);
	}
}

//===============ADAUGARE NOD=================
void insertNode(arb* &r, int val)
{
	if(r->val == NULL)
	{
		r->val = val;
	}
	else if(val < r->val)
	{
		if(r->st == NULL)
		{
			r->st = (arb *)malloc(sizeof(arb));
			r->st->dr = NULL;
			r->st->st = NULL;
			r->st->val = NULL;
		}
		insertNode(r->st, val);
	} 
	else 
	{
		if(r->dr == NULL)
		{
			r->dr = (arb *)malloc(sizeof(arb));
			r->dr->dr = NULL;
			r->dr->st = NULL;
			r->dr->val = NULL;
		}
		insertNode(r->dr, val);
	}
}

void citesteArboreBinar(FILE *f, arb* &r)
{
	while(!feof(f))
	{
		int x = 0;
		fscanf(f, "%d", &x);
		printf("%d ", x);
		insertNode(*&r, x);
	}
}

//=======CAUTARE BINARA============
int cautaNumar(arb *r, int val, int level)
{
	if(r != NULL)
	{
		if(r->val == val)
		{
			return level;
		}
		else
		{
			level++;
			if(val < r->val)
			{
				return cautaNumar(r->st, val, level);
			}
			else
			{
				return cautaNumar(r->dr, val, level);
			}
		}
	}
	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	arb *rad;
	int h = 0, level = 0, search = 0;
	FILE *f  = fopen("arb.txt", "r");
	rad = (arb *)malloc(sizeof(arb));
	citeste(f, *&rad);

	cout<<"PREORDINE: ";
	preordine(rad);
	cout<<endl<<endl;

	cout<<"INORDINE: ";
	inordine(rad);
	cout<<endl<<endl;

	cout<<"POSTORDINE: ";
	postordine(rad);
	cout<<endl<<endl;

	cout<<"FRUNZE: ";
	frunze(rad);
	cout<<endl<<endl;

	cout<<"INALTIME: ";	
	inaltime(rad, h, 0);
	cout<<h<<" (radacina fiind pe nivelul 0)"<<endl<<endl;
	
	cout<<"ALEGE NIVELUL PE CARE VREI SA-L AFISEZI:";
	cin>>level;
	cout<<"PE NIVELUL "<<level<<" SE GASESC NODURILE:";
	afisareNivel(rad, level, 0);
	cout<<endl<<endl;
	
	free(rad);

	f  = fopen("sir.txt", "r");
	rad = (arb *)malloc(sizeof(arb));
	rad->val = NULL;rad->st = NULL;rad->dr = NULL;
	cout<<"SIRUL CITIT: ";
	citesteArboreBinar(f, *&rad);
	cout<<endl<<"INTRODUCETI NUMARUL CAUTAT:";
	cin>>search;
	level = cautaNumar(rad, search, 0);
	if(level == -1)
	{
		cout<<"NUMARUL NU A FOST GASIT"<<endl;
	}
	else 
	{
		cout<<"NUMARUL A FOST GASIT PE NIVELUL "<<level<<endl;
	}

	free(rad);
	return 0;
}