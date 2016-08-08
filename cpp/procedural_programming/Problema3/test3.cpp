// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

/* 
Intr un fisier text se citeste o matrice patratica, sa se verifice daca fiecare element de pe diagonala principala a indicei ii 
este mai mare decat fiecare element de pe linia i si respectiv de pe coloana i. Pentru matrice se va aloca dinamic memorie.

*/

int main(int argc, char* argv[])
{

int i,j,n,**a,k;

FILE *f=fopen("fis.in","rt");

fscanf(f,"%d",&n);	

a=(int**)calloc(n,sizeof(int*));  //alocarea dinamica

for (i=0;i<n;i++)
	a[i]=(int*)calloc(n,sizeof(int));


for (i=0;i<n;i++)   //citim matricea din fisier
	for (j=0;j<n;j++)
		fscanf(f,"%d",&a[i][j]);

fclose(f);

k=1;

for (i=0;i<n;i++)   
{
	for (j=0;j<n;j++)
	{
		if ((a[i][i]<a[i][j])||(a[i][i]<a[j][i]))  //verificam daca toate elementele de pe diagonala principala sunt mai mari deca elementele de pe linia si coloana cu indicele i
		{
		 k=0;
		 break;  // daca gasim un numar mai mare decat cel de pe diagonala principala iesim fortat din for(j)
		}
	
	}
	if (k==0)
		break;  // daca gasim undeva problema cu nr mai mare decat elementu de pe diagonala principala iesim fortat si din for(i)  ( nu mai facem toate calculele)
}

if (k==0)
	printf("Fiecare element de pe diagonala principala a indicei 'ii' nu este mai mare decat fiecare element de pe linia 'i' si respectiv de pe coloana i\n");

if (k==1)
	printf("Fiecare element de pe diagonala principala a indicei 'ii' este mai mare decat fiecare element de pe linia 'i' si respectiv de pe coloana i\n");

	return 0;
}

