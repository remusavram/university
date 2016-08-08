#include <stdio.h>
#include <malloc.h>
#include <conio.h>



void spati()

{
	printf("\n\n\n\n");
	
}



int cautare_binara(int n,int x,int *a, int ok)

{
	
	int i;
	
	ok=0;
	if (x==a[n/2])
	   ok=1;
    else if (x<a[n/2])
       for (i=0;i<n/2;i++)
          if (x==a[i])
		  {
			  ok=1;
		  }
    if (x>a[n/2])
       for (i=n/2;i<n;i++)
          if(x==a[i])
             ok=1;
             
   return ok;
	
}


void problema1()

{
	
	//1.Functie pt. cautare binara a unei valori dintr-un sir sortat crescator.
		
		int i,n,ok,a[100],x;
	
	spati();
	printf("Dati numarul de elemente a sirului: ");
	scanf("%d",&n);
	printf("\n");
	printf("Dati elementele sirului in ordine crescatoare!\n");
	printf("\n");
	
	for (i=0;i<n;i++)
	{
     printf("a[%d]= ",i+1);
     scanf("%d",&a[i]);		
	}
    
    printf("\n");
    printf("Introduceti numarul cautat: ");
    scanf("%d",&x);
		
	if (cautare_binara(n,x,a,ok)==1)
       printf("Numarul %d exista in sir!\n\n",x);
    else 
       printf("Numarul %d nu exista in sir!\n",x);
    
	printf("\n"); 
	printf("Apasati orice tasta...");
	getch();   
       
}


//2.Functie pt. cautare secventiala a unei valori intr-un sir. Functia returneaza numarul de aparitii a valori in sir.	



int apariti(int n,int a[100],int x)

{
	
	int i,k=0;
	
	for (i=0;i<n;i++)
	   if (x==a[i])
          k=k+1;
    
	return k;	
	
}



void problema2()

{
	
	
	        	    
	int n,a[100],x,i;
	
	printf("\n\n");    
	printf("Dati lungimea sirului: ");
	scanf("%d",&n);
	printf("\n");
	printf("Introduceti valorile elementelor din sir!\n");
	printf("\n");
	    
	for(i=0;i<n;i++)
	      {
	       printf("a[%d]= ",i+1);
	       scanf("%d",&a[i]);
	      }
	      
	printf("\n");
	printf("Introduceti valoarea cautata in sir: ");
	scanf("%d",&x); 
	
	printf("\n\n");
	printf("Numarul de apariti a numarului %d in sir este de %d ori.\n",x,apariti(n,a,x));
	printf("\n\n");
	printf("Apasati orice tasta...");
	getch();
    
}    
	


float ordonare(int n,float *a)

{
	
	int i,j;
	float aux;
	
	for (i=0;i<n-1;i++)
	   for(j=i+1;j<n;j++)
	      if (a[i]>a[j])
	         {
     		  aux=a[i];
     		  a[i]=a[j];
     		  a[j]=aux;
         	 }

	return *a;
	
}



void problema3()

{
	
	//3.Functie care sorteaza crescator un sir.
	
	int n,i;
	float a[100];
	
	spati();
	printf("Introduceti lungimea sirului: ");
	scanf("%d",&n);
	printf("\n");
	printf("Introduceti valorile elementelor din sir!\n");
	printf("\n");
	
	for (i=0;i<n;i++)
	   {
	   	printf("a[%d]= ",i+1);
	   	scanf("%f",&a[i]);
	   }
	   
	ordonare(n,a);
	printf("\n");
	printf("Sirul ordonat crescator este: ");
	
	for (i=0;i<n-1;i++)  
	   printf("%-3.2f, ",a[i]);
	   
	printf("%-3.2f ",a[n-1]);   
	printf("\n\n");
	printf("Apasati orice tasta...");
	getch();  
	 	
}



int main(int argc, char *argv[])
{
	
int optiune;
char tasta;

optiune=0;
tasta=0;

do 
  {
  	spati();
  	printf("\t\t Probleme capitolul 8\n\n");
  	printf("1.Functie pt. cautare binara a unei valori dintr-un sir sortat crescator.\n");
  	printf("2.Functie pt. cautare secventiala a unei valori intr-un sir. Functia returneaza numarul de aparitii a valori in sir.\n");
  	printf("3.Functie care sorteaza crescator un sir.\n");
  	
  	optiune=getch();
  	switch(optiune)
  	{
  	   case '1':
  	      problema1();
  	      break;
       case '2':
          problema2();
          break;
       case '3':
          problema3();
          break;
       default:
          spati();
          printf("OPTIUNEA ESTE INVALIDA!\n");
          break;
  	}
  	
   spati();
   printf("Doriti sa reveniti la meniu initial?(d/n)\n") ;      
   tasta=getch();  	
  }
  while(tasta=='d' || tasta=='D');
	
	return 0;
	
}
