// Tema 3 - Automate Finite Deterministe

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>

using namespace std;

int inversare_cuvant(int cuvant)
{
	int temp=0;
	while(cuvant!=0)
	{
	temp=temp*10+cuvant%10;
	cuvant=cuvant/10;
	}
	cuvant=temp;
	return cuvant;
}

int cuvant_eliminare_prima_cifra(int &cuvant)
{
	int temp=cuvant, y=0, p=1;
	while(temp>9)
	{
		y=y+(temp%10)*p;
		p=p*10;
		temp=temp/10;
	}
	return y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nr_stari,matrice[100][100],*vector, stare_initiala, cuvant, cuvant_temp, x;
	char stare_finala[100];
	ifstream f("Numere.in");														// citirea din fisier
	f>>nr_stari;																	// citim nr starilor
	vector=new int[nr_stari];														//retinem starile in vectorul "vector"
	for(int i=0;i<nr_stari;i++)
		f>>vector[i];
	for(int i=0;i<nr_stari;i++)
	{
		f>>matrice[vector[i]][1];
		f>>matrice[vector[i]][2];
	}
	f>>stare_initiala;
	f>>cuvant;
	f>>stare_finala;
	f.close();
	

	cout<<"Cele "<<nr_stari<<" stari citite din fisier sunt: ";
	for(int i=0;i<nr_stari;i++)
		cout<<vector[i]<<" ";
	cout<<endl<<"Starea initiala este: "<<stare_initiala<<endl;
	cout<<stare_finala<<endl;
	cout<<"Cuvantul: "<<cuvant<<endl;
	cuvant_temp=inversare_cuvant(cuvant);

/*	for(int i=0;i<nr_stari;i++)
	{
		for(int j=1;j<3;j++)
			cout<<matrice[vector[i]][j]<<" ";
		cout<<endl;
	}
*/
	cout<<endl<<"("<<stare_initiala<<", "<<cuvant<<")|---";
	while(cuvant_temp>9)
	{
		x=cuvant_temp%10;
		cuvant_temp=cuvant_temp/10;
		stare_initiala=matrice[stare_initiala][x];
		cuvant=cuvant_eliminare_prima_cifra(cuvant);
		cout<<"("<<stare_initiala<<", "<<cuvant<<")|---";
	}
		cout<<"("<<stare_initiala<<", "<<"&)";

	getch();
	return 0;
}


/*
	matrice=new int*[nr_stari];													// alocam memorie dinamica pt cate stari sunt
	for(int i=0;i<nr_stari;i++)
		matrice[i]=new int[2];
*/