/* 
Se citeste din fisierul Matrice.in o matrice cu n linii si m coloane.
Sa se tipareasca in fisierul Matrice.out minimul de pe fiecare linie.
*/

#include "stdio.h"
#include "conio.h"

int a[10][10],n,m,min[10]; 

// a[10][10] - este matrice de n linii si m coloane
// n - numarul de linii al matricei
// m - numarul de coloane al matricei
// min[10] - este sirul in care se va retine minimul de pe fiecare linie.

void main()
{
	FILE *f=fopen("Matrice.in","rt");
	fscanf(f,"%d %d",&n,&m); // Se citeste din fisierul Matrice.in numarul de linii si coloane ale matricei

	//Se citesc elementele matricei
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			fscanf(f,"%d",&a[i][j]);
	fclose(f);

	//Se afla minimul de pe fiecare linie
	for (int i=0;i<n;i++)
	{
		min[i]=a[i][0];
		for (int j=1;j<m;j++)
			if (min[i]>a[i][j]) min[i]=a[i][j];
	}

	//Se tipareste sirul care contine minumul de pe fiecare linie
	FILE *g=fopen("Matrice.out","wt");
	fprintf(f,"Sirul care contine minimele de pe fiecare linie este: \n");
	for (int i=0;i<n;i++)
		fprintf(g,"%d ",min[i]);
	fclose(g);
}