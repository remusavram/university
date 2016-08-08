// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/* Dintr un fisier text se citeste un vector de nr reale, sa se gasesasca perechea de elem. pt. care distanta dintre ele este minima
Daca exista mai mult de o pereche sa se afiseze toate perechile.
Solutiile se vor depune intr un alt fisier text.

Ex:
v=(1,5,8,-13,-20,14,30);

distanta dintre 1 si 5 =4;
distanta dintre 5 si 8 =3;
..........................
distanta dintre 14 si 30 =16;

cea mai mica distanta este perechea (5,8)=3

*/



int main(int argc, char* argv[])


{
int n,i;
float v[100],k,t;

FILE *f=fopen("fis.in","rt");//deschide fisieru
fscanf(f,"%d",&n); //citeste din fisier prima valoare (adica cate elemente are vectoru)

for (i=0;i<n;i++)
	fscanf(f,"%f",&v[i]); //citeste din fisier vectoru
		

fclose(f);
				//ii dam lui k distanta dintre primele 2 elemente (adica dintre 1 si 5)
if (v[0]>v[1])   //v[0]=1 si v[1]=5  1nu este mai mare ca 5 
	k=v[0]-v[1]; 
else
	k=v[1]-v[0]; // 5-1=4    facem chestia asta ca sa nu il avem pe k negativ

for (i=1;i<n-1;i++)
	{
	 if (v[i]>v[i+1])  //aflam distanta dintre celelalte numere
		 t=v[i]-v[i+1];
	 else
		 t=v[i+1]-v[i];

	 if (t<k)     //daca gasim o distanta mai mica, k va lua valoare lui t
		 k=t;
	}

FILE *g=fopen("fis.out","wt");

for (i=0;i<n-1;i++)  // verificam din nou toate distantele iar daca gasim mai multe perechi cu distanta k le vom afisa
	{
	 if (v[i]>v[i+1])
		 t=v[i]-v[i+1];
	 else
		 t=v[i+1]-v[i];

	 if (k==t)
		 fprintf(g,"(%f,%f); ",v[i],v[i+1]); //afisam in fis.out uite-te acolo sa vezi rezultatu :P

	}

fclose(g);

	return 0;
}

