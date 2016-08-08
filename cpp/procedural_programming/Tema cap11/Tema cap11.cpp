#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>



void spati()
{
	printf("\n\n\n\n\n");
}


struct coada
{
	char info;
	struct coada *leg;
}*cap;



typedef struct coada coada;



int inserare(char c)
{
	struct coada *p;
	p=(struct coada*)malloc(sizeof(coada));
	if(p==NULL)
		return 0;
	p->info=c;
	p->leg=cap;
	cap=p;

	return 1;
}



int scoatere(char *c)
{
	struct coada *p,*x;
	if(cap==NULL) 
		return 0;
	if(cap->leg==NULL)
	{
		*c=cap->info;
		free(cap);
		cap=NULL;
		return 1;
	}

	else
	{
		p=cap;
		while(p->leg->leg!=NULL)
			p=p->leg;
		*c=p->leg->info;
		x=p->leg;
		p->leg=NULL;
		free(x);

		return 1;
	}
}



void afisare()
{
	struct coada *p;
	p=cap;
	while(p!=NULL)
	{
		printf("%c ",p->info);
		p=p->leg;
	}
}



void golirecoada()
{
	struct coada *p;
	while (cap!=NULL)
	{
		p=cap;
		cap=p->leg;
		free(p);
	}
}



int main(int argc, char *argv[])
{

	char c,inf;
	cap=NULL;

	do
	{
		printf("1. Introducere caracter in coada.\n");
		printf("2. Scoatere caracter din coada.\n");
		printf("3. Afisare coada.\n");
		printf("4. Golire coada.\n");
		printf("Esc - Parasirea programului\n");
		spati();

		c=getch();
		switch(c)
		{
		case '1':
			printf("Dati un caracter: ");
			inf=getche();
			if(!inserare(inf))
				printf("\nMemorie insuficienta!");
			else
				printf("\nAm introdus: %c",inf);
			spati();
			printf("Apasati orice tasta...\n\n\n");
			break;
		case '2':
			if(!scoatere(&inf))
				printf("Stiva goala!");
			else
				printf("Am scos: %c",inf);
			spati();
			printf("Apasati orice tasta...\n\n\n");
			break;
		case '3':
			printf("Stiva contine: ");
			afisare();
			spati();
			printf("Apasati orice tasta...\n\n\n");
			break;
		case '4':
			golirecoada();
			printf("Am golit stiva!");
			spati();
			printf("Apasati orice tasta...\n\n\n");
			break;
		case 27:
			printf("Apasati o tasta pt. a iesi!");
			break;
		default:
			printf("Apasati 1,2,3,4 sau Escape");
			spati();
		}

		getch();
	}
	while (c!=27);
	golirecoada();


	return 0;
}
