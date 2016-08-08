#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	char c;
	int i;
	
	printf("Se afiseaza pe ecran cele 256 caractere ale tabelei ASCII!\n");
	for (i=1;i<256;i++)
	    printf("%d - %c\n",i,i);
	 c=getch();   
	return 0;
}
