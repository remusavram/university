#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>



struct tstiva

{

	char info;
	struct tstiva *leg;

}*cap;


typedef struct tstiva tstiva;



void spati()

{
	printf("\n\n\n\n\n\n\n");
}



int introducere(char c)

{
	struct tstiva *p;
	p=(struct tstiva*)malloc(sizeof(tstiva));
	if (p==NULL)
		return 0;
	p->info=c;
	p->leg=cap;
	cap=p;
	return 1;
}



int scoatere(char *c)

{
	struct tstiva *p;
	if (cap==NULL)
		return 0;
	p=cap;
	cap=p->leg;
	*c=p->info;
	free(p);
	return 1;
}



void afisare()

{
	struct tstiva *p=cap;
	while (p!=NULL)
	{
		printf("%c ",p->info);
		p=p->leg;
	}
}



void golirestiva()

{
	struct tstiva *p;
	while (cap!=NULL)
	{
		p=cap;
		cap=p->leg;
		free(p);
	}
}



int main(int argc, char *argv[])

{

char c, inf;
cap=NULL;

do
{
	puts("1. Introducere caracter in stiva");
	puts("2. Scoatere ultim caracter in stiva");
	puts("3. Afisare continut stiva");
	puts("4. Golire stiva\n");
	puts("Esc - Parasirea programului\n");
	c=getch();

	switch(c)
	{
		case'1':
			spati();
			printf("Dati un caracter: ");
			inf=getche();
			if(!introducere(inf))
				printf("Memorie insuficienta!");
			else
				printf("\nAm introdus: %c",inf);
			spati();
			break;
		case'2':
			spati();
			if (!scoatere(&inf))
				printf("Stiva goala!");
			else
				printf("Am scos din stiva: %c",inf);
			spati();
			break;
		case'3':
			spati();
			printf("Stiva contine: ");
			afisare();
			spati();
			break;
        case '4':
            spati();
            golirestiva();
            printf("Am golit stiva!");
            break;
		case 27:
			spati();
			printf("Apasati o tasta pt. a iesi!");
			spati();
			break;
		default:
			spati();
			printf("Apasati 1,2,3,4 sau Esc");
			spati();
	}
	getch();
}
while(c!=27);
golirestiva();

	return 0;
}


