// Tema 4 - Minimizarea

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int nr_stari,matrice[100][100], *vector, stare_initiala,nr_stari_finale, *vector_stari_finale, **matrice_tabel_stari_nemarcate, contor1=0, contor2=0, verifica=1,x,y, contor3=0;
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
	f>>nr_stari_finale;
	vector_stari_finale=new int[nr_stari_finale];
	for(int i=0;i<nr_stari_finale;i++)
		f>>vector_stari_finale[i];
	f.close();

	matrice_tabel_stari_nemarcate=new int*[nr_stari];
	for(int i=0;i<nr_stari;i++)
		matrice_tabel_stari_nemarcate[i]=new int[nr_stari];
	
	for(int i=1;i<nr_stari;i++)
		for(int j=0;j<i;j++)
			matrice_tabel_stari_nemarcate[i][j]=0;
	for(int i=1;i<nr_stari;i++)
		for(int j=0;j<i;j++)
		{
			if(vector[j]==stare_initiala)
				contor1=1;
			else
				for(int k=0;k<nr_stari_finale;k++)
					if(vector[j]==vector_stari_finale[k])
						contor1=1;
			if(vector[i]==stare_initiala)
				contor2=1;
			else
				for(int k=0;k<nr_stari_finale;k++)
					if(vector[i]==vector_stari_finale[k])
						contor2=1;
			if(contor1!=contor2)
				matrice_tabel_stari_nemarcate[j][i]=1;
			else
				matrice_tabel_stari_nemarcate[j][i]=0;
			contor1=0;
			contor2=0;
		}
	
		for(int i=1;i<nr_stari;i++)
		{
			for(int j=0;j<i;j++)
				cout<<matrice_tabel_stari_nemarcate[j][i]<<" ";
			cout<<endl;
		}

		while(verifica!=0)
		{
			verifica=0;
			for(int i=1;i<nr_stari;i++)
			{
				for(int j=0;j<i;j++)
				{
					x=matrice[vector[i]][1];
					y=matrice[vector[j]][1];

					if(x==stare_initiala)
						contor1=1;
					else
						for(int k=0;k<nr_stari_finale;k++)
							if(x==vector_stari_finale[k])
								contor1=1;
					if(y==stare_initiala)
						contor2=1;
					else
						for(int k=0;k<nr_stari_finale;k++)
							if(y==vector_stari_finale[k])
								contor2=1;
					if(contor1!=contor2 && matrice_tabel_stari_nemarcate[j][i]!=1)
					{
						matrice_tabel_stari_nemarcate[j][i]=1;
						verifica=1;
						contor3=1;
					}
					
					contor1=0;
					contor2=0;

					if(contor3==0)
					{
						x=matrice[vector[i]][2];
						y=matrice[vector[j]][2];

						if(x==stare_initiala)
							contor1=1;
						else
							for(int k=0;k<nr_stari_finale;k++)
								if(x==vector_stari_finale[k])
									contor1=1;
						if(y==stare_initiala)
							contor2=1;
						else
							for(int k=0;k<nr_stari_finale;k++)
								if(y==vector_stari_finale[k])
									contor2=1;
						if(contor1!=contor2 && matrice_tabel_stari_nemarcate[j][i]!=1)
						{
							matrice_tabel_stari_nemarcate[j][i]=1;
							verifica=1;
						}
						
						contor1=0;
						contor2=0;
						}
					contor3=0;

					}
				}
			}
	cout<<endl<<endl;
	for(int i=1;i<nr_stari;i++)
	{
		for(int j=0;j<i;j++)
			cout<<matrice_tabel_stari_nemarcate[j][i]<<" ";
		cout<<endl;
	}
	int eliminare=nr_stari;
	for(int i=1;i<nr_stari;i++)
		for(int j=0;j<i;j++)
			if(matrice_tabel_stari_nemarcate[j][i]==0)
			{
				vector[i]=vector[j];
				eliminare--;
				if(eliminare==1)
					break;
			}
	cout<<endl<<"Dupa minimizare au ramas "<<eliminare<<" stari!";
	cout<<"Starile sunt: ";
	for(int i=0;i<nr_stari-1;i++)
		for(int j=i;j<nr_stari;j++)

	getch();
	return 0;
}

/*
		cout<<endl<<endl<<endl;
		for(int i=1;i<nr_stari;i++)
		{
			for(int j=0;j<i;j++)
				cout<<j<<" "<<i<<" ";
			cout<<endl;
		}
		*/