// test2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"



/*Dintr un fisier text se citeste un vector de nr reale, sa se gasesasca perechea de elem. pt. care distanta dintre ele este minima
Daca exista mai mult de o pereche sa se afiseze toate perechile.
Solutiile se vor depune intr un alt fisier text.

Altfel cum am gandi problema!

  v=(1,10,11,15,16,2,3)

luam fiecare element si vedem distanta dintre el si restu:
ex:

  distanta dintre 1 si 10 = 9
  distanta dintre 1 si 11 = 10
  distanta dintre 1 si 15 = 14
  .............................
  distanta dintre 1 si 2 = 1
  ............................
  distanta dintre 10 si 11 = 1
  distanta dintre 10 si 15 = 4
  ............................

  luam cele mai mici distante si apoi afisam perechile


  respuns: (1,2);(2,3);(10,11).....


*/



int main(int argc, char* argv[])
{

int n,i,j;
float v[100],k,t;

FILE *f=fopen("fis.in","rt");//deschide fisieru
fscanf(f,"%d",&n); //citeste din fisier prima valoare (adica cate elemente are vectoru)

for (i=0;i<n;i++)
	fscanf(f,"%f",&v[i]); //citeste din fisier vectoru
		

fclose(f);
		
if (v[0]>v[1])     //treaba asta o facem ca nu stim ce valoare sa ii dam lui k (adica noi trebuie sa ii dam cea mai mare valoare, dupa care el sa caute daca exista valori mai mici)
	k=v[0]-v[1];	// si atunci ii dam prima distanta                       
else
	k=v[1]-v[0];


for (i=0;i<n-1;i++)             //verificam toate distantele dintre un element si toate dupa el
   for (j=i+1;j<n;j++)
   {
	   if (v[i]>v[j])
		   t=v[i]-v[j];
	   else 
		   t=v[j]-v[i];
	   
	   if (t<k)
		   k=t;					//cautam cea mai mica distanta si o memoram in k
   }

FILE *g=fopen("fis.out","wt");

for (i=0;i<n-1;i++)            //dupa ce am gasit cea mai mica distanta si am memorat-o in k
   for (j=i+1;j<n;j++)			//cautam toate distantele egale cu cea mai mica distanta
   {
	   if (v[i]>v[j])
		   t=v[i]-v[j];
	   else 
		   t=v[j]-v[i];
	   
	   if (t==k)
		   fprintf(g,"(%f,%f); ",v[i],v[j]);   //scriem distantele in fisierul fis.out, cauta si vezi daca alea sunt corecte :P
												// pune alte valori in fis.in si vezi daca modifica fis.out
   }

fclose(g);


	return 0;
}

