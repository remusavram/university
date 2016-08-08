#include <stdio.h>
#include <conio.h>
#include <math.h>


void spati()
{
	 printf("\n\n\n");	
}
	
void numar_prim()
{
	//verificam daca un nr. este prim

	int n,i,ok;
	
	spati();
	printf("Introduceti un numar: ");
	scanf("%d",&n);
	for (i=2;i<sqrt(n);i++)
		ok=1;
		if (n%i==0)
			{
			 printf("Numarul %d nu este prim!\n",n);
		     ok=0;
		     
			}
		if (ok==1)
		    printf("Numarul %d este prim!\n",n);
    spati();
  	printf("Apasa orice tasta...\n");
	getch();

}



void primele_prime()
{
	//afiseaza primele n numere naturale prime
	
	int n,i,k=0,nr=2,ok;
 
 	spati();
	printf("Introduceti un numar: ");
	scanf("%d",&n);
	printf("Primele %d numere naturale prime sunt: ",n);
	while (k<n)
       {
		for (i=2,ok=1;i<=trunc(sqrt(nr));i++)
			if (nr%i==0)
				{
			 	 ok=0;
                 break;
				}
		if (ok==1)
           {
           	printf("%d ",nr);
           	k=k+1;
           }
		nr=nr+1;
       }
	printf("\n");
	spati();	   	
	printf("Apasa orice tasta...\n");
	getch();

}



void palindrom()
{
    //verificam daca nu numar este palindrom
    
	int n,nou=0,u=0,nr;

	spati();
    printf("Introduceti un numar: ");
	scanf("%d",&n);
	nr=n;
	while (nr!=0)
	   {
   		u=nr%10;
   		nou=nou*10+u;
   		nr=nr/10;
   	   }
    if (n==nou)
        printf("Numarul %d este palindrom!\n",n);
    else
        printf("Numarul %d nu este palindrom!\n",n);	
    spati();    
   	printf("Apasa orice tasta...\n");
	getch();

}



int main(int argc, char *argv[])
{
	int optiune=0;
	char tasta=0;
	
	do
	{
		printf("\t\t\tMENIU - introduceti numarul optiunii\n\n");
		printf("\t1. Verificati daca numarul este prim.\n");
		printf("\t2. Afisati primele n numere naturale prime.\n");
		printf("\t3. Verificati daca numarul este polindrom.\n");
	
	
	optiune = getch();
	
	switch(optiune)
    {
  		case'1':
  		   numar_prim();
  		   break;
	    case'2':
	       primele_prime();
	       break;
        case'3':
           palindrom();
           break;
        default:
       	   spati();
           printf("Optiunea nu este valida.\n");
	       break;
  	}
  		spati();
	    printf("Doriti sa reveniti la ecranul initial?(d/n)\n");
     	tasta = getch();
     	spati();
	}
	while(tasta == 'd' || tasta == 'D');

	return 0;
}
