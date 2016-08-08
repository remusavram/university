#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <math.h>

void spati()

{
	printf("\n\n\n");
}


void matrice_media_aritmetica()

{
	//Se citeste un numar n. Se creaza o matrice triunghiulara. Se calucleaza si se afiseaza mediile aritmetice pe lini.

 	int n,i,j,k;
 	float **a,ma;

    spati();
 	printf("Dati numarul de lini!\n\n");
 	printf("n= ");
 	scanf("%d",&n);
 	a=(float**)calloc(n,sizeof(float*));

	for (i=0;i<n;i++)
 	    a[i]=(float*)calloc(n,sizeof(float));

 	for (i=0;i<n;i++)
 	   for (j=0;j<=i;j++)
  	    {
  	     printf("a[%d,%d]=",i+1,j+1);
   	    scanf("%f",&a[i][j]);
   	   }
	printf("\n");
	printf("Matricea este!\n\n");

	 for (i=0;i<n;i++)
	    {
		 for (j=0;j<=i;j++)
	        printf("%-4.0f",a[i][j]);
	     printf("\n\n");
	    }

	 for (i=0;i<n;i++)
	    {
	     ma=0;
		 k=0;
		 for (j=0;j<=i;j++)
		    {
	   		 ma=ma+a[i][j];
	   		 k=k+1;
	    	}
	 	 ma=ma/k;
	 	 printf("Media aritmetica pe linia %d este: %2.2f\n",i+1,ma);
	    }

	for (i=0;i<n;i++)
	   free(a[i]);
	free(a);
	printf("\n");
	printf("Apasa orice tasta...\n");
	getch();
}


void matrice_tridimensionala()

{
		
	//Citim trei numere si creem o matrice tridimensionala.Sa se gaseasca cel mai mare si cel mai mic element la matrici.
	
	int n,m,p,i,j,k,min,max;
	float ***a;
	
	spati();
	printf("Dati dimensiunile matricii!\n");
	printf("m= ");
	scanf("%d",&m);
	printf("n= ");
	scanf("%d",&n);
	printf("p= ");
	scanf("%d",&p);
	
	a=(float***)calloc(m,sizeof(float**));
	
	for (i=0;i<m;i++)
	   a[i]=(float**)calloc(n,sizeof(float*));
	
	for (i=0;i<m;i++)
	   for (j=0;j<n;j++)
	      a[i][j]=(float*)calloc(p,sizeof(float));
	
	for (i=0;i<m;i++)
	   for(j=0;j<n;j++)
	      for(k=0;k<p;k++)
	      {
	      	printf("a[%d,%d,%d]= ",i+1,j+1,k+1);
	      	scanf("%f",&a[i][j][k]);
	      }
	      
	min=a[0][0][0];
	max=a[0][0][0];
	
	for (i=0;i<m;i++)
	   for(j=0;j<n;j++)
	      for(k=1;k<p;k++)
	         {
	     	  if (min>a[i][j][k])
	     	     min=a[i][j][k];
	  	      if (max<a[i][j][k])
	  	         max=a[i][j][k];
	         }
	printf("\n\n"); 
	printf("Cel mai mic element al matricei este: %d\n",min);
	printf("Cel mai mare element al matricei este: %d\n",max);
	
	for (j=0;j<n;j++)
	   for (k=0;k<p;k++)
	      free(a[j,k]);
    
    for (j=0;j<n;j++)
       free(a[j]);
    free(a);
	printf("\n\n"); 
	printf("Apasati orice tasta...");
	getch();

}


void primele_prime()

{
	
	//Construim un vector in care depunem primele n numere naturale prime.
	
	int n,nr,x,i,ok,*a;
	
	spati();
	printf("Introduceti un numar mai mare ca 1: ");
	scanf("%d",&n);
	
	a=(int*)calloc(n,sizeof(int));
	nr=0;
	x=2;
	
	while (nr<n)
	  {
	   for (i=2,ok=1;i<=(sqrt(x));i++)
	     if (x%i==0)
		    {
	   		 ok=0;
	   		 break;
	    	} 
	   if (ok==1)
	      {
	  	   a[nr]=x;
	  	   nr=nr+1;
	      } 
	   x=x+1;	   	
	}
	
	printf("\n");
	printf("Primele %d numere prime sunt: ",n);
	for (i=0;i<n;i++)
	   printf("%d ",a[i]);
    free(a);
	
	printf("\n\n\n\n");
	printf("Apasati orice tasta... ");
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
 	printf("\n1.Se citeste un numar n. Se creaza o matrice triunghiulara. Se calucleaza si se afiseaza mediile aritmetice pe lini.\n");
 	printf("\n2.Citim trei numere si creem o matrice tridimensionala.Sa se gaseasca cel mai mare si cel mai mic element la matrici.\n");
 	printf("\n3.Construim un vector in care depunem primele n numere naturale prime.\n");
 	
 	optiune=getch();
 	
 	switch(optiune)
 	{
 	   case '1':
 	      matrice_media_aritmetica();
 	      break;
       case '2':
          matrice_tridimensionala();
          break;
       case '3':
          primele_prime();
          break;
       default :
          spati();
          printf("OPTIUNEA NU ESTE VALIDA!");
          break;
    }
    spati();
    printf("Doriti sa reveniti la meniu initial?(d/n)\n");
    spati();
   	tasta = getch();
 }
 while(tasta == 'd' || tasta == 'D');
 
return 0;
}
