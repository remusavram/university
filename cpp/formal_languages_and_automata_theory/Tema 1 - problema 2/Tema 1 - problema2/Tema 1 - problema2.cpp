// Avand un cuvant "x" si un vocabular "V" sa se verifice daca "x" este cuvat peste alfabet.


#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char cuvant[100], *Vocabular;
	int nr_de_caractere_al_vocabularului;
	int verificare=1;

	cout<<"Dati numarul de caractere al vocabularului: ";
	cin>>nr_de_caractere_al_vocabularului;

	Vocabular=new char [nr_de_caractere_al_vocabularului];

	cout<<"Introduceti vocabularul: "<<endl;
	for(int i=0;i<nr_de_caractere_al_vocabularului;i++)
	{
		cout<<"V["<<i+1<<"]=";
		cin>>Vocabular[i];
	}

	cout<<"Introduceti cuvantul ce doriti sa aflati daca este cuvant peste alfabet: ";
	cin>>cuvant;

	for(int i=0;i<strlen(cuvant);i++)
		if(strchr(Vocabular,cuvant[i])==NULL)
		{
			verificare=0;
			break;
		}

	if(verificare)
		cout<<endl<<"Cuvantul '"<<cuvant<<"' este cuvant peste alfabet!";
	else
		cout<<endl<<"Cuvantul '"<<cuvant<<"' nu este cuvant peste alfabet!";

	getch();
	return 0;
}

