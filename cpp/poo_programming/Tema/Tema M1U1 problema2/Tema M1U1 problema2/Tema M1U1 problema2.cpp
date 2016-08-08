#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	cout<<"De la tastatura se citeste numele si varstele unor persoane. Sa se afiseze tabelar, sortat dupa nume, aceste date precum si media varstelor."<<endl<<endl<<endl;

	char s[30], nume[30][30];
	int varsta[30],n,i,j,aux;
	float media;

	cout<<"Dati nr. de persoane: ";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cin.getline(s,30);
		cout<<endl<<"nume["<<i+1<<"]= ";
		cin.getline(nume[i],30);
		cout<<"varsta["<<i+1<<"]=";
		cin>>varsta[i];
	}

	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(nume[i],nume[j])>0)
			{
				strcpy(s,nume[i]);
				strcpy(nume[i],nume[j]);
				strcpy(nume[j],s);
				aux=varsta[i];
				varsta[i]=varsta[j];
				varsta[j]=aux;
			}

	media=0;
	for(i=0;i<n;i++)
		media=media+varsta[i];
	
	media=media/n;

	cout<<endl<<endl<<"Datele introduse sortate dupa nume si media varstelor sunt: "<<endl<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"|Nr. |NUMELE SI PRENUMELE           |Varsta |"<<endl;
	cout<<"|crt.|                              |       |"<<endl;
	cout<<"|----|------------------------------|-------|"<<endl;

	for(i=0;i<n;i++)
	{
		cout<<setiosflags(ios::right);
		cout<<"|"<<setw(4)<<i+1<<"|";
		cout<<resetiosflags(ios::right);
		cout<<setiosflags(ios::left);
		cout<<setw(30)<<nume[i];
		cout<<resetiosflags(ios::left);
		cout<<setiosflags(ios::right);
		cout<<"|"<<setw(7)<<varsta[i]<<"|";
		cout<<endl;
	}

	cout<<"|-----------------------------------|-------|"<<endl;
	cout<<setiosflags(ios::fixed | ios::right);
	cout<<"| Media varstelor:                  |"<<setw(7)<<setprecision(2)<<media<<"|"<<endl;
	cout<<"---------------------------------------------"<<endl;


	getch();
	return 0;
}

