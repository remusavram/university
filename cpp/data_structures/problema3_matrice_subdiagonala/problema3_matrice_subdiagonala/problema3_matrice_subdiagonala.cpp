
#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

void spatii()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
}

void transformare()
{
	int n,a[100][100],i,j,v[100],k=0;

	cout<<"Introduceti numarul de lini/coloane al matricii: ";
	cin>>n;
	
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;

	cout<<endl<<"Introduceti elementele matricii subdiagonale: "<<endl;

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			cout<<"a["<<i+1<<","<<j+1<<"]= ";
			cin>>a[i][j];
		}
	
	cout<<endl<<"Ati introdus matricea subdiagonala:"<<endl<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i>=j)
			{
				v[k]=a[i][j];
				k=k+1;
			}

	cout<<endl<<"Partea nenula a matrici este: ";

	for(i=0;i<k;i++)
		cout<<v[i]<<" ";

	spatii();
	cout<<"Apasati orice tasta...";
	getch();
	spatii();

}

void produs_matrici()
{

	int a[100][100],b[100][100],c[100][100],va[100],vb[100],vc[100];
	int i,j,n,k,t;

	cout<<"Introduceti numarul de lini/coloane al matricilor: ";
	cin>>n;
	

	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
			c[i][j]=0;
		}

	cout<<endl<<"Introduceti elementele matricii A subdiagonale: "<<endl;

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			cout<<"a["<<i+1<<","<<j+1<<"]= ";
			cin>>a[i][j];
		}
	
	cout<<endl<<"Ati introdus matricea A subdiagonala:"<<endl<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl<<"Introduceti elementele matricii B subdiagonale: "<<endl;

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			cout<<"b["<<i+1<<","<<j+1<<"]= ";
			cin>>b[i][j];
		}
	
	cout<<endl<<"Ati introdus matricea B subdiagonala:"<<endl<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}

	k=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i>=j)
			{
				va[k]=a[i][j];
				vb[k]=b[i][j];
				k=k+1;
			}

	cout<<endl<<"Partea nenula a matrici A este: ";

	for(i=0;i<k;i++)
		cout<<va[i]<<" ";

	cout<<endl<<"Partea nenula a matrici B este: ";

	for(i=0;i<k;i++)
		cout<<vb[i]<<" ";

	for(i=0;i<k;i++)
		vc[i]=0;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(t=j;t<=i;t++)
				{
					vc[i*(i+1)/2+j]=vc[i*(i+1)/2+j]+va[i*(i+1)/2+t]*vb[t*(t+1)/2+j];
					c[i][j]=c[i][j]+va[i*(i+1)/2+t]*vb[t*(t+1)/2+j];
				}


	cout<<endl<<"Partea nenula a matrici C este: ";

	for(i=0;i<k;i++)
		cout<<vc[i]<<" ";


	cout<<endl<<endl<<"Matricea C (AxB) subdiagonala este:"<<endl<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}

	spatii();
	cout<<"Apasati orice tasta...";
	getch();
	spatii();

}

int main()
{

	int optiune;
	char tasta;

	do
	{
		cout<<"a) Se considera o matrice patratica subdiagonala. Sa se transforme partea nenula a matrici intr-un vector."<<endl;
		cout<<"b) Sa se scrie un algoritm care citeste 2 matrici subdiagonale A,B; le transforma conform punctului a) in 2 vectori va si vb, si calculeaza produsul AxB folosind doar vectorii va si vb."<<endl;

		optiune=getch();
		switch(optiune)
		{
		case 'a':
			spatii();
			transformare();
			break;
		case 'b':
			spatii();
			produs_matrici();
			break;
		default:
			spatii();
			cout<<"OPTIUNEA ESTE INVALIDA!!!";
			spatii();
			break;
		}
	cout<<"Doriti sa reveniti la meniul anterior?(y/n)";
	spatii();
	tasta=getch();
	}
	while(tasta=='y' || tasta=='Y');
		
	return 0;
}

