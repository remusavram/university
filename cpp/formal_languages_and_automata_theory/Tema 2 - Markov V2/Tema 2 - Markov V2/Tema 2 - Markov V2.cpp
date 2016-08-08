// Markov.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void citireCuvant(char c[10], int k)
{
cout<<"Introduceti cuvantul: ";
for(int i=0;i<k;i++)
      {
	    cin>>c[i];
      }
}

void inlocuire(char a[10][2],char c[10], int n,int k)
{
int t=0;
for(int i=0;i<n;i++)
{
		for(int j=0;j<k;j++)
		{
		int r=0;
		if(a[i][0]==c[j])
		{
			c[j]=a[i][1];
			t++; r=1;
			if (r==1)
			cout<<t<<". ";
			for(int j=0;j<k;j++)
			cout<<c[j];
			cout<<endl;
		}
        }
}
}


void main()
{
int n,k;
char a[10][2];
char c[20];

fstream f("Fisier.in");
f>>n;
for (int i=0;i<n;i++)
  for (int j=0;j<2;j++)
  {
   f>>a[i][j];
  }

cout<<"Numarul de caractere al cuvantului: ";
cin>>k;
cout<<endl;
citireCuvant(c,k);
cout<<endl;
inlocuire(a,c,n,k);
fclose;
cout<<endl;
getch();
}