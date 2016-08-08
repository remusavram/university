#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <setjmp.h>



void mesaj_eroare()
{
	perror("Au fost erori in timpul executiei!");
	getch();
}


void tmain()
{
	char numef[100];
	FILE *fis;
	jum_buf stare;

	if(!setjmp(stare))
	{
		printf("Dati numele unui fisier: ");
		scanf("%s",numef);
		fis=fopen(numef,"rb");
		if(fis==NULL)
			longjmp(stare,1);
	}
	else
	{
		perror("Eroare! Nu am putut deschide fis.");
		atexit(mesaj_eroare);
		exit(1);
	}
	fclose(fis);
	atexit(mesaj_ok);
	
}

