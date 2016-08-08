#include <stdafx.h>
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void main()
{
	cout<<"De la tastatura se citeste  o matrice de valori reale. Sa se afiseze pe ecran matricea, astfel incat fiecare element al matricei sa fie scris alineat la dreapta, pe opt caractere si cu doua zecimale exacte."<<endl<<endl<<endl<<endl;
	
	float a[100][100];
	int i,j,n,m;

	cout<<"Dati nr. de lini: ";
	cin>>n;
	cout<<"Dati nr. de coloane: ";
	cin>>m;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cout<<"a["<<i+1<<","<<j+1<<"]=";
			cin>>a[i][j];
		}

		cout<<endl<<endl<<"Matricea introdusa este: "<<endl<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<setiosflags(ios::fixed | ios::showpoint | ios::right);
			cout<<setw(8)<<setprecision(2)<<a[i][j];
		}
		cout<<endl;
	}

	getch();
}

