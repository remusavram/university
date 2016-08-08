#include "stdafx.h"
#include<iostream>
#include <conio.h>

using namespace std;

//========================= Spati ===============================

void spati()
{
	cout<<endl<<endl<<endl<<endl<<endl;
}

//====================== Heapfy ======================

void Heapfy(int *&v, int n, int i)
{
	int L,R,imax;
	
	L=2*i;
	R=2*i+1;
	if((L<=n)&&(v[i]<v[L]))
		imax=L;
	else
		imax=i;
	if((R<=n)&&(v[R]>v[imax]))
		imax=R;
	if(i!=imax)
	{
		int aux=v[i];
		v[i]=v[imax];
		v[imax]=aux;
		Heapfy(v,n,imax);
	}
}

//============== Construirea heap-ului ==============

void Construire_Heap(int *&v, int n)
{
	for(int i=n/2;i>=0;i--)
		Heapfy(v,n,i);
}

//=================== Heap sortare ==================

void Heap_sort(int *&v, int n)
{
	int x=0;

	Construire_Heap(v,n);
	for(int i=n-1;i>0;i--)
	{
		int aux=v[0];
		v[0]=v[i];
		v[i]=aux;
		Heapfy(v,i-1,x);
	}
}

//=================== Extract maxim ===================

void Extract_Max(int *&v, int &max, int &n)
{
	if(n<=0)
		cout<<"Heap vid";
	else
	{
		max=v[0];
		v[0]=v[n-1];
		n--;
		Heapfy(v,n,1);
		cout<<"Am extras din Heap elementul maxim: "<<max;
	}
}

//====================== Insert ======================

void Inserare(int *&v, int k, int &n)
{
	n++;
	v[n-1]=k;
	Construire_Heap(v,n);
}

//====================== Stergerea ======================

void Stergere(int *&v, int k, int &n)
{
	int temp=n;

		for(int i=0;i<n;i++)
			if(k==v[i])
			{
				cout<<"Am sters elementul: "<<k;
				for(int j=i;j<n;j++)
				{
					v[j]=v[j+1];
				}
				n--;
				Construire_Heap(v,n);
			}
		if(temp==n)
			cout<<"Elementul "<<k<<" nu exista in Heap!";
}

//====================== Main ======================

void main()
{
	int n,*v,c,max,k;

	cout<<"Introduceti nr. de elemente: ";
	cin>>n;
	v=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"v["<<i+1<<"]=";
		cin>>v[i]; 
	}
	max=v[0];
	Construire_Heap(v,n);
	cout<<endl<<endl;

	do
	{
		cout<<"1. Afisati constructia Heap-ului."<<endl;
		cout<<"2. Sortati in ordine crescatoare Heap-ul."<<endl;
		cout<<"3. Extragerea maximului."<<endl;
		cout<<"4. Inserarea unui element."<<endl;
		cout<<"5. Stergerea unui element."<<endl;
		cout<<"ESC - Parasire program!"<<endl;

		c=getch();
		spati();

		switch(c)
		{
			case'1':
				Construire_Heap(v,n);
				cout<<endl<<"Constructia Heap-ului este: ";
				for(int i=0;i<n;i++)
				{
					cout<<v[i]<<" ";
				}
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case'2':
				Heap_sort(v,n);
				cout<<endl<<"Heap-ul sortat in ordine crescatoare este: ";
				for(int i=0;i<n;i++)
				{
					cout<<v[i]<<" ";
				}
				spati();
				cout<<"Apasati orice tasta...";
				break;

			case '3':
				Construire_Heap(v,n);
				Extract_Max(v,max,n);
				spati(); 
				cout<<"Apasati orice tasta...";
				break;

			case '4':
				cout<<"Introduceti numarul ce doriti sa il inserati in Heap: ";
				cin>>k;
				Inserare(v,k,n);
				cout<<endl<<endl<<"Ati introdus in Heap elementul: "<<k;
				spati(); 
				cout<<"Apasati orice tasta...";
				break;

			case '5':
				if(n<=0)
					cout<<"Heap vid";
				else
				{
					Construire_Heap(v,n);
					cout<<"Introduceti numarul ce doriti sa il stergeti din Heap: ";
					cin>>k;
					Stergere(v,k,n);
				}
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
				cout<<"Apasati 1,2,3,4,5 sau Esc!"<<endl;
		}
		getch();
		spati();
	}
	while(c!=27);
}
