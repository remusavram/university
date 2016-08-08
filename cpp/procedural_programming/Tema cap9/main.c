#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>



void spati()

{
	
	printf("\n\n\n\n");
	
}



void problema1()

{
	
	//Folosind functia 'strrev' verificati daca un nr. este polindrom.
	
	char s1[100],s2[100];
	
	spati();
	printf("Sirul este: ");
	gets(s1);
	printf("\n");
	
	strcpy(s2,s1);
	strrev(s2);

	if (strcmp(s1,s2)==0)
	   printf("Numarul este polindrom!\n\n");
    else 
       printf("Numarul nu este polindrom!\n\n");
	
	printf("Apasati orice tasta...");
	spati();
	getch();
	     	
}



void problema2()

{
	
	//Scrieti o functie care returneaza nr. de cuvinte dintr-un string.
	
	spati();
	char s[100],c;
	int i,k=1;
	
	c=' ';
	printf("Sirul este: ");
	gets(s);
	
	for (i=1;i<strlen(s)-1;i++)
   		if (s[i]==c)
     		k=k+1;

  	printf("Numarul de cuvinte este: %d\n\n",k);
 
 	spati();
 	printf("Apasati orice tasta...\n\n");
	getch();

}



int main(int argc, char *argv[])
{

	int optiune=0;
	char tasta=0;
	
	do
	{
		spati();
		printf("\t Probleme capitolul 9\n\n\n");
		printf("1.Folosind functia 'strrev' verificati daca un nr. este polindrom.\n");
		printf("2.Scrieti o functie care returneaza nr. de cuvinte dintr-un string.");
		spati();
		
		optiune=getch();
		switch(optiune)
		{
			case '1':
			   problema1();
			   break;
   			case '2':
			   problema2();
			   break;
   			default:
			   spati();
   			   printf("OPTIUNEA ESTE INVALIDA!");
   			   spati();
   			   break;
		}
		
		printf("Doriti sa reveniti la meniu anterior?(d/n)");
		spati();
		tasta=getch();
	}
	while(tasta=='d' || tasta=='D');
	
	return 0;
}
