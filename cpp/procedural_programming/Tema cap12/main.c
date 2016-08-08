#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <process.h>


int main(int argc, char *argv[])

{

	char numef[100];
	float vector[200],aux;
	FILE *fis;
	int i,j,k;
	
	printf("Dati numele fisierului: ");
	gets(numef);	
	fis=fopen(numef,"rt+");
	
		if (fis==NULL)
	{
		printf("Eroare!");
		getch();
	}
	
	i=0;
	while (feof(fis))
	{
		fscanf(fis,"%f",vector[1]);
		i=i+1;
	}

	for (j=0;j<i;j++)
   		printf("%f ",vector[j]);
   
   	for (j=0;j<i-1;j++)
   		for (k=j+1;k<i;k++)
			if (vector[j]>vector[k])
			{
				aux=vector[j];
				vector[j]=vector[k];
				vector[k]=aux;
			}
			
	for (j=0;j<i;j++)
		fprintf(fis,"%f ",vector[j]);
		
	fclose(fis);			
			
	return 0;
}
