#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>



struct tprodus

{
	
	char denumire_produs[50];
	float cantitate,pret,valoare;
	
};

int main(int argc, char *argv[])

{

int n,i,j;
float s=0,aux2;
char aux[100];

printf("\n\nDe la tastatura cititi stocul unei firme intr-un sir de elemente de tip 'struct'.In structura se vor retine: denumirea produsului, cantittatea si pretul. Sortati crescator sirul dupa denumirea produselor, dupa care afisati tabelar produsele.\n\n\n");
	
struct tprodus x[50];
	
printf("Dati numarul de produse: ");
scanf("%d",&n);
printf("\n");
	
for (i=0;i<n;i++)
{	
	gets(x[i-1].denumire_produs);	
	printf("Denumirea produsului %d: \n",i+1);
}	
gets(x[n-1].denumire_produs);
printf("\n");

for (i=0;i<n;i++)
{
	printf("Cantitatea produsului '%s': ",x[i].denumire_produs);
	scanf("%f",&x[i].cantitate);
	printf("Pretul produsului %s: ",x[i].denumire_produs);
	scanf("%f",&x[i].pret);
	x[i].valoare=x[i].cantitate*x[i].pret;
	printf("\n");
}

printf("\n\n");
printf("-----------------------------------------------------------\n");
printf("| Nr.|  Denumire Produs    | Cantitate |  Pret  | Valoare |\n");
printf("|--------------------------+--------------------+---------|\n");

for (i=0;i<n;i++)
{
	printf("|%4d| %-20s|%11.2f|%8.2f|%9.2f|",i+1,x[i].denumire_produs,x[i].cantitate,x[i].pret,x[i].valoare);
	printf("\n");	
}
printf("|--------------------------+--------------------+---------|\n");
for (i=0;i<n;i++)
	s=s+x[i].valoare;
	
printf("|  Valoarea totala stoc: %33.2f|\n",s);
printf("-----------------------------------------------------------\n");
printf("\n\n");

for (i=0;i<n-1;i++)
	for (j=i+1;j<n;j++)
			if (strcmp(x[i].denumire_produs,x[j].denumire_produs)>0)
			{
			 strcpy(aux,x[i].denumire_produs);
			 strcpy(x[i].denumire_produs,x[j].denumire_produs);
			 strcpy(x[j].denumire_produs,aux);
			 
			 aux2=x[i].cantitate;
			 x[i].cantitate=x[j].cantitate;
			 x[j].cantitate=aux2;
			 
			 aux2=x[i].pret;
			 x[i].pret=x[j].pret;
			 x[j].pret=aux2;
			 
			 aux2=x[i].valoare;
			 x[i].valoare=x[j].valoare;
			 x[j].valoare=aux2;		  	
			}

printf("Tabelul in ordine crescatoare dupa denumirea produselor!");
printf("\n\n");
printf("-----------------------------------------------------------\n");
printf("| Nr.|  Denumire Produs    | Cantitate |  Pret  | Valoare |\n");
printf("|--------------------------+--------------------+---------|\n");

for (i=0;i<n;i++)
{
	printf("|%4d| %-20s|%11.2f|%8.2f|%9.2f|",i+1,x[i].denumire_produs,x[i].cantitate,x[i].pret,x[i].valoare);
	printf("\n");	
}
printf("|--------------------------+--------------------+---------|\n");
printf("|  Valoarea totala stoc: %33.2f|\n",s);
printf("-----------------------------------------------------------\n");
printf("\n\n");	

getch();

	return 0;
}
